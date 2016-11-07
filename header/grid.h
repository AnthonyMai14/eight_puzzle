#ifndef GRID_H
#define GRID_H

#include <string>
#include <vector>
#include <iostream>

struct Grid {
	//data values
	std::vector< std::vector<unsigned> > v_num;
	Grid* parent;
	unsigned g_n; //depth
	unsigned f_n; //cost
	
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
	unsigned get_f_n();
	void set_f_n(unsigned);
	
};
#endif