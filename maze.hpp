//
// Created by Kevin Drake on 11/25/20.
//

#ifndef PROJECT_2_MAZE_HPP
#define PROJECT_2_MAZE_HPP


#include <tuple>
#include <vector>
#include <random>
#include <ctime>
#include <queue>

class Maze {
public:
    Maze(int, int);
    int getNumRows() const {return numRows;}
    void setNumRows(int numRows) {this->numRows = numRows;}
    int getNumCols() const {return numCols;}
    void setNumCols(int numCols) {this->numCols = numCols;}
    void prims();
    void kruskals();

private:
    int row, col;
    //0: from, 1: to, 2: weight, 3 vertexFrom, 4 vertexTo, 5 edge direction
    std::vector<std::tuple<std::tuple<int, int>,std::tuple<int, int>, int, int, int, std::string>> edges;
    std::vector<std::tuple<std::tuple<int, int>,std::tuple<int, int>, int, int, int, std::string>> weightSortedEdges;
    //a grid of walls and paths, aka a maze. 0: vertex(if exists), 1: char for wall, path
    std::vector<std::vector<std::tuple<int, char>>> grid;
    int numRows = 0, numCols = 0, numVertices = 0;
    std::tuple<std::tuple<int, int>,std::tuple<int, int>, int, int, int, std::string> sourceEdge;
    std::tuple<std::tuple<int, int>,std::tuple<int, int>, int, int, int, std::string> destEdge;
    std::queue<std::tuple<std::tuple<int, int>,std::tuple<int, int>, int, int, int, std::string>> primsEdges;
    std::queue<std::tuple<std::tuple<int, int>,std::tuple<int, int>, int, int, int, std::string>> kruskalsEdges;
    std::vector<std::tuple<std::tuple<int, int>,std::tuple<int, int>, int, int, int, std::string>> kEdgesFinal;
    std::vector<std::tuple<std::tuple<int, int>,std::tuple<int, int>, int, int, int, std::string>> pEdgesFinal;
    std::vector<std::vector<std::tuple<int, char>>> kGrid;
    std::vector<std::vector<std::tuple<int, char>>> pGrid;
    std::vector<std::vector<bool>> pPathGrid;
    std::vector<std::vector<bool>> kPathGrid;

    int genRandWeight();
    std::tuple<int, int> genRandSourcePos();
    std::tuple<int, int> genRandDestPos();
    void print(std::vector<std::vector<std::tuple<int, char>>> grid);
    void kruskalSort();
    void kruskalsMST(std::vector<std::vector<int>> adjList, std::vector<bool> visited);
    void primsMST(std::vector<std::vector<int>> adjList, std::vector<bool> visited);
    void makeEdges();
    bool hasCycle(int from, int to, std::vector<std::vector<int>> adjList, std::vector<bool> visited);
    void source();
    void dest();
    bool pShortestPath(int row, int col);
    bool kShortestPath(int row, int col);
    bool areAllVisited(std::vector<bool> visited);
};


#endif //PROJECT_2_MAZE_HPP
