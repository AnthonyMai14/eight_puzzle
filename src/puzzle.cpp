#include "../header/puzzle.h"

Puzzle::Puzzle(const unsigned ROW) {
    sol = new Grid(ROW);
}
Puzzle::Puzzle(std::vector< std::vector<unsigned> > v, const unsigned ROW) {
    sol = new Grid(ROW);
    
    Grid* g = new Grid(v);
    //create tree
    create_tree(g);
    //if sol, then create
    //else, display error
    
}
void Puzzle::create_tree(Grid* g) {
    if (grid_exist(g)) {
        return;
    }
    
    //push onto vector
    visit.push_back(g);
    
    if (g->is_equal(sol)) {
        return;
    }
    
    for (unsigned r = 0; r < g->v_num.size(); ++r) {
        for (unsigned c = 0; c < g->v_num.at(r).size(); ++c) {
            std::string move = can_move(i, j);
            if (move == "no move") { continue; }
            
            std::vector< vector<int> > tmp_v = g->v_num;
            if (move == "up") {
                tmp_v.at(r - 1).at(c) = tmp_v.at(r).at(c);
                tmp_v.at(r).at(c) = 0;
            }
            else if (move == "right") {
                tmp_v.at(r).at(c + 1) = tmp_v.at(r).at(c);
                tmp_v.at(r).at(c) = 0;
            }
            else if (move == "down") {
                tmp_v.at(r + 1).at(c) = tmp_v.at(r).at(c);
                tmp_v.at(r).at(c) = 0;
            }
            else if (move == "left") {
                tmp_v.at(r).at(c - 1) = tmp_v.at(r).at(c);
                tmp_v.at(r).at(c) = 0;
            }
            
            Grid g_new = new Graph(tmp_v);
            g_new->parent = g;
            //--------------need to take care of childrean-----
            create_tree(g_new);
        }
    }
}
bool grid_exist(Grid* g) {
    for (unsigned i = 0; i < visit.size(); ++i) {
        if (g.is_equal(visit.at(i))) return true;
    }
    return false;
}
