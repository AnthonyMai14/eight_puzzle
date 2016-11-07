#include <iostream>
#include <string>
#include <vector>
#include <string.h> //strcpy, strtok
#include <stdlib.h> //atoi

#include "../header/grid.h"
#include "../header/puzzle.h"

const unsigned ROW = 3;

int main() {
    //opening statement
    std::cout << "Welcome to Anthony Mai's 8-puzzle solver" << std::endl; 
    std::string user_input = "";
    
    //menu
    do {
        std::cout << "Press \'d\' to use default, "
                << "\'c\' to use your custom matrix, " 
                << "or \'e\' to exit" << std::endl;
        
        getline(std::cin, user_input);
        
        if (user_input == "d") {
            //do default
        }
        else if (user_input == "c") {
            std::vector< std::vector<unsigned> > custom_input(ROW);
            char char_user_input[1024];
            char *ptr;
            
            //start up for custom input
            for (unsigned i = 0; i < ROW; ++i) {
                std::cout << "Enter row " << i + 1
                        << ", use spaces between numbers. ";
                getline(std::cin, user_input);
                
                strcpy(char_user_input, user_input.c_str());
                
                //begin parsing user_input and store in parsed_input using strtok
                //parse white space
                ptr = strtok(char_user_input, " "); 
                //store parsed commands unsignedo parsed_input
                while (ptr != NULL) {
                    custom_input.at(i).push_back(atoi( ptr ));
                    ptr = strtok(NULL, " ");
                }
            }
            //ask for choice of algorithm
            std::cout << "What is your choice of algorithm:"
                        << "1. Uniform Cost Search" << std::endl
                        << "2. A* with the Misplaced Tile heuristic" << std::endl
                        << "A* with the Manhattan distance heuristic" << std::endl
                        << std::endl;
            getline(std::cin, user_input);
            
            //parse and store unsigned vector
            //create Puzzle
            Puzzle* p = new Puzzle(custom_input, ROW, user_input);
            p->run();
            // Grid* g = new Grid(custom_input);
            // for (unsigned i = 0; i < ROW; ++i) {
            //     for (unsigned j = 0; j < g->v_num.at(i).size(); ++j) {
            //         std::cout << g->v_num.at(i).at(j) << " ";
            //     }
            //     std::cout << std::endl;
            // }
        }
        else if (user_input != "e") {
            std::cout << "ERROR: Invalid input" << std::endl;
        }
        
    } while(user_input != "e");
    // Grid* g = new Grid(ROW);
    // Grid* h = new Grid(ROW);
    // std::cout << g->is_equal(h) << std::endl;
    // for (unsigned i = 0; i < ROW; ++i) {
    //     for (unsigned j = 0; j < g->v_num.at(i).size(); ++j) {
    //         std::cout << g->v_num.at(i).at(j) << " ";
    //     }
    //     std::cout << std::endl;
    // }
    return 0;
}