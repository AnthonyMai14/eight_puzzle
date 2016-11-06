#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <string>
#include <vector>



class Puzzle {
	private:
		Grid* sol;
		std::vector<*Grid> visit;
	protected:
		void create_tree(Grid*);
		bool grid_exist(Grid*);
		
		
	public:
		Puzzle(const unsigned);
		Puzzle(std::vector< std::vector<unsigned> >&, const unsigned);
};
#endif