#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <stack>

#include "grid.h"

class Puzzle {
	private:
		Grid* sol;
		std::vector<Grid*> grid_visited;
		std::vector<Grid*> check_grid;
		std::stack<Grid*> sol_trace;
		unsigned max_check_grid_size;
		std::string algorithm;
		//helper functions
		Grid* create_tree();
		bool grid_exist(Grid*);
		unsigned manhattan(Grid*, unsigned, unsigned);
		void find_index(unsigned&, unsigned&);
		void reorder_f_n();
		//algorithm
		unsigned misplaced_heuristic(Grid *g);
		unsigned manhattan_heuristic(Grid *g);
		
		
	public:
		Puzzle(const unsigned, const std::string);
		Puzzle(std::vector< std::vector<unsigned> >&, const unsigned, const std::string);
		void run();
};
#endif