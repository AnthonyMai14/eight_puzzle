#include <iostream>
#include <string>
#include <vector>
#include <string.h> //strcpy, strtok
#include <stdlib.h> //atoi

#include "../header/grid.h"
#include "../header/puzzle.h"

const unsigned ROW = 3;
std::vector< std::vector<unsigned> > default_input(ROW);

int main() {
    //opening statement
    std::cout << "Welcome to Anthony Mai's 8-puzzle solver" << std::endl; 
    std::string user_input = "";
    std::string algorithm_input = "";
    
    //menu
    std::cout << "Press \'1\' to use default, "
            << "\'2\' to use your custom matrix" 
            << std::endl;
    
    getline(std::cin, user_input);
    
    //ask for choice of algorithm
        std::cout << std::endl << "What is your choice of algorithm:"
                    << std::endl << "1. Uniform Cost Search"
                    << std::endl << "2. A* with the Misplaced Tile heuristic"
                    << std::endl << "3. A* with the Manhattan distance heuristic"
                    << std::endl << std::endl;
        getline(std::cin, algorithm_input);
        
    if (user_input == "1") {
        //do default
        default_input.at(0).push_back(1);
        default_input.at(0).push_back(2);
        default_input.at(0).push_back(3);
        default_input.at(1).push_back(4);
        default_input.at(1).push_back(8);
        default_input.at(1).push_back(0);
        default_input.at(2).push_back(7);
        default_input.at(2).push_back(6);
        default_input.at(2).push_back(5);
        
        Puzzle* p = new Puzzle(default_input, ROW, algorithm_input);
        p->run();
    }
    else if (user_input == "2") {
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
        
        //parse and store unsigned vector
        //create Puzzle
        Puzzle* p = new Puzzle(custom_input, ROW, algorithm_input);
        p->run();
    }
    return 0;
}