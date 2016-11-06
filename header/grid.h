#ifndef GRID_H
#define GRID_H

#include <string>
#include <vector>
#include <iostream>

struct Algorithm;

struct Grid {
	//data values
	std::vector< std::vector<unsigned> > v_num;
	Grid* parent;
	std::vector<Grid*> children;
	
	//constructors
	Grid(const unsigned);
	Grid(std::vector< std::vector<unsigned> >&);
	
	//functions
	std::string can_move(unsigned, unsigned);
	void output_grid();
	bool is_equal(const Grid*);
	// bool operator==(const Grid*);
	
	//algorithms
	void algorithm_val(Algorithm*);
	unsigned sort();
	
};
#endif