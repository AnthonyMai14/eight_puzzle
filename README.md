# eight_puzzle
Introduction to Artificial Intelligence Course | University of California Riverside
How to compile:
    g++ src/main.cpp src/grid.cpp
To Run program:
    ./a.out
Rule:
    1) Must be a matrix square (i.e. 2x2, 3x3, 4x4...)
    2) In order to change the dimension of the matrix,
        need to change const ROW
    3) ROW >= 2;
    4a) The number of non-zero values present must be
        ROW^2 - 1. (i.e. ROW = 3, therefore 3^2 - 1 = 8)
    4b) Number must be in numerical order from 1 to (ROW^2 -1)
    5) There must be a blank spot. Blank spot will be represented
        by the number '0'