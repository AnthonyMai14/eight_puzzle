#include "../header/puzzle.h"

Puzzle::Puzzle(const unsigned ROW, const std::string algorithm) {
    sol = new Grid(ROW);
    this->algorithm = algorithm;
    max_check_grid_size = 0;
}
Puzzle::Puzzle(std::vector< std::vector<unsigned> > &v, const unsigned ROW, const std::string algorithm) {
    sol = new Grid(ROW);
    this->algorithm = algorithm;
    max_check_grid_size = 0;
    
    //initial state
    Grid* g = new Grid(v);
    check_grid.push_back(g);
}
void Puzzle::run() {
    std::cout << "Expanding: " << std::endl << std::endl;
    //create tree
    Grid* ans = create_tree();
    
    std::cout << "Goal!!" << std::endl << std::endl
            << "To solve this problem the search algorithm expanded a total of "
            << grid_visited.size()
            << "The maximum number of nodes in the queue at any one time was"
            << max_check_grid_size
            << "The depth of the goal node was"
            << ans->get_g_n() << std::endl;
}
Grid* Puzzle::create_tree() {
    //if queue empty, return null
    if (check_grid.size() == 0) return NULL;
    //dequeue
    if (check_grid.size() > max_check_grid_size) {
        max_check_grid_size = check_grid.size();
    }
    Grid* g = check_grid.back();
    g->output_grid();
    std::cout << "Expanding this node..." << std::endl;
    check_grid.pop_back();
    //if goal, return node
    if (g->is_equal(sol)) return g;
    
    unsigned children = 0;
    
    //create children and add to queue
    for (unsigned r = 0; r < g->v_num.size(); ++r) {
        for (unsigned c = 0; c < g->v_num.at(r).size(); ++c) {
            //find if at location, it can move
            std::string move = g->can_move(r, c);
            
            if (move == "no move") { continue; }
            //make copy of 2D vector
            std::vector< std::vector<unsigned> > tmp_v(g->v_num.size());
            for (unsigned i = 0; i < g->v_num.size(); ++i) {
                for (unsigned j = 0; i < g->v_num.at(i).size(); ++j) {
                    tmp_v.at(i).push_back(g->v_num.at(i).at(j));
                }
            }
            
            //find what ways are possible for that location
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
            //create a grid with that move
            Grid* g_new = new Grid(tmp_v);
            //if the grid already exist, don't push onto grid_visited
            if (grid_exist(g_new)) {
                continue;
            }
            //increment how many children have visited
            ++children;
            //set depth
            g_new->set_g_n(g);
            //set cost depending on algorithm
            if (algorithm == "2") {//manhattan_heuristic
                g_new->set_f_n(manhattan_heuristic(g_new));
            }
            else if (algorithm == "1") {//misplaced_heuristic
                g_new->set_f_n(misplaced_heuristic(g_new));
            }
            else {//if algorithm == 0
                g_new->set_f_n(0);
            }
            //set parent
            g_new->parent = g;
            grid_visited.push_back(g_new);
            check_grid.push_back(g_new);
        }
    }
    //reorder so that smallest f_n in back
    reorder_f_n();
    std::cout << "Best state to expand with a g(n) = "
                << check_grid.back()->get_g_n()
                << " and h(n) = "
                << check_grid.back()->get_f_n()
                << "is..." << std::endl;
    return create_tree();
}
bool Puzzle::grid_exist(Grid* g) {
    for (unsigned i = 0; i < grid_visited.size(); ++i) {
        if (g->is_equal(grid_visited.at(i))) return true;
    }
    return false;
}

unsigned Puzzle::misplaced_heuristic(Grid* g) {
    unsigned count = 0;
    for (unsigned r = 0; r < g->v_num.size(); ++r) {
        for (unsigned c = 0; c < g->v_num.at(r).size(); ++c) {
            if (g->v_num.at(r).at(c) != sol->v_num.at(r).at(c)) ++count;
        }
    }
    return count;
}

unsigned Puzzle::manhattan_heuristic(Grid* g) {
    unsigned count = 0;
    for (unsigned r = 0; r < g->v_num.size(); ++r) {
        for (unsigned c = 0; c < g->v_num.at(r).size(); ++c) {
            if (g->v_num.at(r).at(c) != sol->v_num.at(r).at(c)) {
                //find where it is suppose to be
                count += manhattan(g,r,c);
            }
        }
    }
    return count;
}

unsigned Puzzle::manhattan(Grid* g, unsigned r_init, unsigned c_init) {
    int r_final;
    int c_final;
    unsigned val = g->v_num.at(r_init).at(c_init);
    
    for (unsigned r = 0; r < g->v_num.size(); ++r) {
        for (unsigned c = 0; c < g->v_num.at(r).size(); ++c) {
            if (sol->v_num.at(r).at(c) == val) {
                r_final = r;
                c_final = c;
            }
        }
    }
    return (unsigned)(abs((int)r_init - r_final) + abs((int)c_init - c_final));
}
void Puzzle::reorder_f_n() {
    //using insert sort
    unsigned index_largest = 0;
    
    for (unsigned i = 0; i < check_grid.size(); ++ i) {
        unsigned largest_f_n = check_grid.at(i)->get_f_n();
        
        for (unsigned j = i; j < check_grid.size(); ++j) {
            unsigned current = check_grid.at(j)->get_f_n();
            
            if (current > largest_f_n) {
                index_largest = j;
                largest_f_n = current;
            }
        }
        
        //swap
        Grid* tmp = check_grid.at(i);
        check_grid.at(i) = check_grid.at(index_largest);
        check_grid.at(index_largest) = tmp;
        
    }
}