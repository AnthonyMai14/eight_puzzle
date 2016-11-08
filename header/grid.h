#ifndef GRID_H
#define GRID_H

#include <string>
#include <vector>
#include <iostream>

struct Grid {
	//data values
	std::vector< std::vector<unsigned> > v_num;
	Grid* parent;
	unsigned g_n; //depth/cost
	unsigned h_n; //distance to goal
	
	//constructors
	Grid(const unsigned);
	Grid(std::vector< std::vector<unsigned> >&);
	
	//functions
	std::string can_move(unsigned, unsigned);
	void output_grid();
	bool is_equal(const Grid*);
	// bool operator==(const Grid*);
	unsigned get_g_n();
	void set_g_n(Grid*);
	unsigned get_h_n();
	void set_h_n(unsigned);
	unsigned get_f_n();
	
};
#endif