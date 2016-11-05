#include "../header/grid.h"
Grid::Grid(const unsigned row) {
	parent = NULL;
	v_num.resize(row);
	for(unsigned i = 0; i < row; ++i) {
	    v_num.at(i).resize(row);
	}
	unsigned num = 1;
	
	for (unsigned r = 0; r < row; ++r) {
		for (unsigned c = 0; c < row; ++c) {
			if (r == (row - 1) && c == (row - 1)) {
			    v_num.at(r).at(c) = 0;
			}
			else { 
			    v_num.at(r).at(c) = num;
			    ++num;
			}
		}
	}
}

Grid::Grid(std::vector< std::vector<unsigned> > &v) {
    parent = NULL;
    this->v_num = v;
}

std::string Grid::can_move(unsigned r, unsigned c) {
    //up
    if (r != 0) {
        if (v_num.at(r - 1).at(c) == 0) {
            return "up";
        }
    }
    //right
    if (r != v_num.size() - 1) {
        if (v_num.at(r).at(c + 1) == 0) {
            return "right";
        }
    }
    //down
    if (c != v_num.at(r).size() - 1) {
        if (v_num.at(r + 1).at(c) == 0) {
            return "down";
        }
    }
    //left
    if (c != 0) {
        if(v_num.at(r).at(c - 1) == 0) {
            return "left";
        }
    }
    
    return "no move";
}

bool Grid::is_equal(const Grid* rhs) {
	unsigned row = this->v_num.size();
    unsigned col = this->v_num.at(row - 1).size();
    
    for (unsigned r = 0; r < row; ++r) {
        for(unsigned c = 0; c < col; ++ c) {
            if (this->v_num.at(r).at(c) != rhs->v_num.at(r).at(c)) {
                return false;
            }
        }
    }
    
    return true;
}

void Grid::output_grid() {
    for (unsigned r = 0; r < v_num.size(); ++r) {
        for (unsigned c = 0; c < v_num.at(r).size(); ++c) {
            std::cout << v_num.at(r).at(c) << " ";
        }
        std::cout << std::endl;
    }
}