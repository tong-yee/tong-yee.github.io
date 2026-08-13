// File: maze_v1_fixed_width.cpp
// Name:
// Email:
//
// P2: Maze -- Task A. Complete reachable() below. Everything else in this
// file (includes, struct, main()) is already provided -- do not rename or
// remove it, and do not remove the test calls already in main(). See
// "Task A" in the project handout for the required behavior and edge cases.
#include <iostream>
#include <queue>
#include <vector>

struct Coordinate {
  int row;
  int col;
};

// Precondition:
// - Every row of maze has the same number of columns.
// - A value of 0 represents an accessible cell.
bool reachable(const std::vector<std::vector<int>>& maze, Coordinate start, Coordinate target);

int main() {
  std::vector<std::vector<int>> maze = {
    {0, 0, 1, 1},
    {0, 0, 1, 1},
    {0, 0, 0, 1},
    {0, 0, 0, 0},
  };

  std::cout << std::boolalpha << reachable(maze, {0, 0}, {3, 3}) << '\n';

  std::vector<std::vector<int>> maze2 = {
    {0, 1, 1, 1},
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1},
    {0, 0, 1, 0},
  };

  std::cout << std::boolalpha << reachable(maze2, {0, 0}, {4, 3}) << '\n';

  return 0;
}

bool reachable(const std::vector<std::vector<int>>& maze, Coordinate start, Coordinate target) {
  // TODO: implement reachable() for a fixed-width maze using BFS.
  // See "Task A" in the handout for the required behavior and edge cases:
  // - empty maze, out-of-bounds start/target, start or target on a wall,
  //   start == target, and no path between two otherwise-valid cells.
  return false;
}
