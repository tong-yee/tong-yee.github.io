// File: maze_v3_find_a_path.cpp
// Name:
// Email:
//
// P2: Maze -- Task C. Complete findPath() below. backtrack(),
// releaseMemory(), print(), and main() are already fully implemented --
// do not rename or modify them. See "Task C" in the project handout for
// the required behavior, edge cases, and memory-management requirements.
#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <iomanip> // setw

const char MARK_CHAR = '*';

struct Coordinate {
  int row;
  int col;
};

struct Node {
  Coordinate position;
  Node* parent;
};

// Maze representation:
// - Rows may have different numbers of columns.
// - A value of 0 represents an accessible cell.
std::list<Coordinate> findPath(const std::vector<std::vector<int>>& maze, Coordinate start, Coordinate target);
std::list<Coordinate> backtrack(const Node* currPtr);          // given, do not modify
void releaseMemory(std::vector<Node*>& nodePtrVec);            // given, do not modify
void print(const std::vector<std::vector<int>>& maze, Coordinate start, Coordinate target); // given, do not modify

int main() {
  std::vector<std::vector<int>> maze = {
    {0, 0, 1, 1},
    {0, 0, 1, 1},
    {0, 0, 0, 1},
    {0, 0, 0, 0},
  };

  print(maze, {0, 0}, {3, 3});

  std::vector<std::vector<int>> maze2 = {
    {0, 1, 1, 1},
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1},
    {0, 0, 1, 0},
  };

  print(maze2, {0, 0}, {4, 3});

  std::vector<std::vector<int>> maze3 = {
    {0, 1},
    {0, 1, 1, 0},
    {0, 0},
    {1, 0, 0},
    {1, 0},
  };

  print(maze3, {0, 0}, {4, 3}); // "", {4, 3} is not a valid entry
  print(maze3, {0, 0}, {4, 1});
  print(maze3, {1, 3}, {4, 1}); // "", the neighboring rows do not contain column 3

  std::vector<std::vector<int>> maze4 = {
    {},
    {0, 0},
    {},
    {0}
  };

  print(maze4, {1, 0}, {1, 1}); // (1,0)->(1,1)
  print(maze4, {1, 0}, {3, 0});
  print(maze4, {0, 0}, {1, 0});

  return 0;
}

std::list<Coordinate> findPath(const std::vector<std::vector<int>>& maze, Coordinate start, Coordinate target) {
  std::list<Coordinate> emptyLst;
  // TODO: implement findPath() using BFS with parent pointers.
  // See "Task C" in the handout, including the memory-management
  // requirements -- every `new Node` must end up in a std::vector<Node*>
  // and be released via releaseMemory() before you return, on EVERY
  // return path (found or not found).
  return emptyLst;
}

std::list<Coordinate> backtrack(const Node* currPtr) {
  std::list<Coordinate> coordLst;
  while (currPtr != nullptr) {
    coordLst.push_front({currPtr->position.row, currPtr->position.col});
    currPtr = currPtr->parent;
  }

  return coordLst;
}

void releaseMemory(std::vector<Node*>& nodePtrVec) {
  for (Node*& nodePtr : nodePtrVec) {
    delete nodePtr;
    nodePtr = nullptr;
  }
}

void print(const std::vector<std::vector<int>>& maze, Coordinate start, Coordinate target) {
  int numRows = static_cast<int>(maze.size());

  if (numRows == 0) {
    return;
  }

  int maxNumCols = 0;
  for (int i = 0; i < numRows; i++) {
    int currNumCols = static_cast<int>(maze[i].size());
    if (currNumCols > maxNumCols) {
      maxNumCols = currNumCols;
    }
  }

  // Print column labels
  std::cout << "    "; // spaces before the first column label
  for (int j = 0; j < maxNumCols; j++) {
    std::cout << std::setw(3) << j;
  }
  std::cout << '\n';

  // Mark all path cells. Start and target will still be printed as S and T.
  for (int i = 0; i < numRows; i++) {
    std::cout << std::setw(3) << i << " ";
    for (int j = 0; j < static_cast<int>(maze[i].size()); j++) {
      if (i == start.row && j == start.col) {
        std::cout << std::setw(3) << "S";
      }
      else if (i == target.row && j == target.col) {
        std::cout << std::setw(3) << "T";
      }
      else {
        std::cout << std::setw(3) << maze[i][j];
      }
    }
    std::cout << '\n';
  }
  std::cout << "\n";

  std::list<Coordinate> coordLst = findPath(maze, start, target);

  if (coordLst.empty()) {
    std::cout << "Cannot go from (" << start.row
      << "," << start.col << ')'
      << " to (" << target.row << ',' << target.col
      << ")\n";
    return;
  }

  std::vector<std::vector<int>> mazeMarked = maze;
  for (auto it = coordLst.begin(); it != coordLst.end(); ++it) {
    mazeMarked[it->row][it->col] = MARK_CHAR;
  }

  // Print column labels
  std::cout << "    "; // spaces before the first column label
  for (int j = 0; j < maxNumCols; j++) {
    std::cout << std::setw(3) << j;
  }
  std::cout << '\n';

  // Print * in all intermediate nodes between start and target.
  for (int i = 0; i < numRows; i++) {
    std::cout << std::setw(3) << i << " ";
    for (int j = 0; j < static_cast<int>(mazeMarked[i].size()); j++) {
      if (i == start.row && j == start.col) {
        std::cout << std::setw(3) << "S";
      }
      else if (i == target.row && j == target.col) {
        std::cout << std::setw(3) << "T";
      }
      else if (mazeMarked[i][j] == MARK_CHAR){ // marked character
        std::cout << std::setw(3) << MARK_CHAR;
      }
      else {
        std::cout << std::setw(3) << mazeMarked[i][j];
      }
    }
    std::cout << '\n';
  }
  std::cout << "\n";

  std::string pathStr;

  for (auto it = coordLst.begin(); it != coordLst.end(); ++it) {
    std::string coordStr = "(" + std::to_string(it->row) + "," + std::to_string(it->col) + ")";

    if (pathStr.empty()) {
      pathStr = coordStr;
    }
    else {
      pathStr += "->" + coordStr;
    }
  }

  std::cout << "[start]" << pathStr << "[end]\n";
}
