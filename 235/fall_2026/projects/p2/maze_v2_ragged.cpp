// File: maze_v2_ragged.cpp
// Name:
// Email:
//
// P2: Maze -- Task B. Complete reachable() below. Everything else in this
// file (includes, struct, main()) is already provided -- do not rename or
// remove it, and do not remove the test calls already in main(). See
// "Task B" in the project handout for the required behavior and edge cases.
#include <iostream>
#include <queue>
#include <vector>

struct Coordinate {
  int row;
  int col;
};

// Maze representation:
// - Rows may have different numbers of columns.
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

  std::vector<std::vector<int>> maze3 = {
    {0, 1, },
    {0, 1, 1, 0},
    {0, 0},
    {1, 0, 0},
    {1, 0},
  };

  std::cout << std::boolalpha << reachable(maze3, {0, 0}, {4, 3}) << '\n'; // false, {4, 3} is not a valid entry
  std::cout << std::boolalpha << reachable(maze3, {0, 0}, {4, 1}) << '\n'; // true
  std::cout << reachable(maze3, {1, 3}, {4, 1}) << '\n'; // false: the neighboring rows do not contain column 3

  std::vector<std::vector<int>> maze4 = {
    {},
    {0, 0},
    {},
    {0}
  };

  std::cout << reachable(maze4, {1, 0}, {1, 1}) << '\n'; // true
  std::cout << reachable(maze4, {1, 0}, {3, 0}) << '\n'; // false
  std::cout << reachable(maze4, {0, 0}, {1, 0}) << '\n'; // false

  return 0;
}

bool reachable(const std::vector<std::vector<int>>& maze, Coordinate start, Coordinate target) {
  // TODO: implement reachable() for a RAGGED maze using BFS.
  // See "Task B" in the handout -- bounds-check each neighbor against
  // its OWN row's length, not one shared column count. You do not need a
  // separate check for "every row is empty": the ordinary start-coordinate
  // bounds check already returns false in that case.
  return false;
}
