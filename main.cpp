#include <iostream>
#include "maze.hpp"

int main(int argc, char *argv[]) {

    if (argc != 3){
        std::cout << "Error! Incorrect Number of Parameters!\n";
        exit(1);
    }
    std::cout << "Welcome to the \"A-MAZE-ING\" Maze Generator!" << std::endl << std::endl;

    Maze maze (std::stoi(argv[1]), std::stoi(argv[2]));

    maze.kruskals();
    maze.prims();


    return 0;
}

