//File: drawSideBySide.cpp
#include <iostream>
#include <string>
#include <vector>
#include <cctype> //isalpha, isdigit, isspace
#include <climits> //INT_MAX
#include "TurtleGraphics.hpp"

std::vector<std::vector<int>> CMDS_CAP_LETTERS[] = {
  //std::vector<std::vector<int>> commandsA = 
  {
    // tip at (3,10): approach from (2,10) going south
    {1}, //pen up
    {3}, //turn right -> SOUTH (start facing EAST, right=SOUTH)
    {5,2}, //move south -> (2,0)... wait need to go east first
    {4}, //turn left -> EAST
    {5,10}, //move east -> (2,10)
    {3}, //turn right -> SOUTH
    {2}, //pen down
    {5,1}, //draw * at (3,10)

    // left diagonal: (4,9),(5,8),(6,7),(7,6),(8,5)
    {1}, //pen up
    {3}, //turn right -> WEST
    {5,1}, //move west -> (3,9)
    {4}, //turn left -> SOUTH
    {2}, //pen down
    {5,1}, //draw * at (4,9)

    {1}, //pen up
    {3}, //turn right -> WEST
    {5,1}, //move west -> (4,8)
    {4}, //turn left -> SOUTH
    {2}, //pen down
    {5,1}, //draw * at (5,8)

    {1}, //pen up
    {3}, //turn right -> WEST
    {5,1}, //move west -> (5,7)
    {4}, //turn left -> SOUTH
    {2}, //pen down
    {5,1}, //draw * at (6,7)

    {1}, //pen up
    {3}, //turn right -> WEST
    {5,1}, //move west -> (6,6)
    {4}, //turn left -> SOUTH
    {2}, //pen down
    {5,1}, //draw * at (7,6)

    {1}, //pen up
    {3}, //turn right -> WEST
    {5,1}, //move west -> (7,5)
    {4}, //turn left -> SOUTH
    {2}, //pen down
    {5,1}, //draw * at (8,5)

    // right diagonal: (4,11),(5,12),(6,13),(7,14),(8,15)
    {1}, //pen up
    {4}, //turn left -> EAST (from SOUTH)
    {4}, //turn left -> NORTH
    {5,5}, //move north -> (3,5)
    {3}, //turn right -> EAST
    {5,6}, //move east -> (3,11)
    {3}, //turn right -> SOUTH
    {2}, //pen down
    {5,1}, //draw * at (4,11)

    {1}, //pen up
    {4}, //turn left -> EAST
    {5,1}, //move east -> (4,12)
    {3}, //turn right -> SOUTH
    {2}, //pen down
    {5,1}, //draw * at (5,12)

    {1}, //pen up
    {4}, //turn left -> EAST
    {5,1}, //move east -> (5,13)
    {3}, //turn right -> SOUTH
    {2}, //pen down
    {5,1}, //draw * at (6,13)

    {1}, //pen up
    {4}, //turn left -> EAST
    {5,1}, //move east -> (6,14)
    {3}, //turn right -> SOUTH
    {2}, //pen down
    {5,1}, //draw * at (7,14)

    {1}, //pen up
    {4}, //turn left -> EAST
    {5,1}, //move east -> (7,15)
    {3}, //turn right -> SOUTH
    {2}, //pen down
    {5,1}, //draw * at (8,15)

    // crossbar row 9, cols 4-16
    {1}, //pen up
    {5,1}, //move south -> (8,15) ... need to navigate to (9,3)
    {3}, //turn right -> WEST
    {5,12}, //move west -> (8,3)
    {4}, //turn left -> SOUTH
    {4}, //turn left -> EAST
    {2}, //pen down
    {5,13}, //draw crossbar cols 4-16

    // left leg col 4, rows 10-15
    {1}, //pen up
    {4}, //turn left -> NORTH (from EAST)
    {4}, //turn left -> WEST
    {5,12}, //move west -> (9,4)
    {3}, //turn right -> NORTH
    {3}, //turn right -> EAST
    {3}, //turn right -> SOUTH
    {2}, //pen down
    {5,6}, //draw left leg rows 10-15

    // right leg col 16, rows 10-15
    {1}, //pen up
    {4}, //turn left -> EAST
    {4}, //turn left -> NORTH
    {5,6}, //move north -> (9,4)... need (9,16)
    {3}, //turn right -> EAST
    {5,12}, //move east -> (9,16)
    {3}, //turn right -> SOUTH
    {2}, //pen down
    {5,6}, //draw right leg rows 10-15

    {1}, //pen up
    {6}, //print
  },

  //TurtleGraphics tgA;
  //tgA.run(commandsA);

  //std::vector<std::vector<int>> commandsB = 
  { // pen up, move to (2,4), draw left vertical col4 rows 3-15
    {1}, //pen up
    {5,4}, //move east 4 steps
    {3}, //turn right, from east to south
    {5,2}, //move south 2 steps -> (2,4)
    {2}, //pen down
    {5,13}, //draw left vertical from (3,4) to (15,4)

    // bottom horizontal row15 cols 5-16
    {4}, //turn left, from south to east
    {5,12}, //draw bottom horizontal cols 5-16

    // bottom right col16 rows 14-11
    {1}, //pen up
    {4}, //turn left, from east to north
    {2}, //pen down
    {5,4}, //draw col16 rows 14 down to 11

    // bottom curve at (10,14)
    {1}, //pen up
    {5,1}, //move north 1 -> (10,16)
    {4}, //turn left, from north to west
    {5,2}, //move west 2 -> (10,14)
    {3}, //turn right, from west to north
    {5,1}, //move north 1 -> (9,14)
    {3}, //turn right, from north to east
    {3}, //turn right, from east to south
    {2}, //pen down
    {5,1}, //draw bottom curve at (10,14)

    // middle horizontal row9 cols 4-13
    {1}, //pen up
    {3}, //turn right, from south to west
    {3}, //turn right, from west to north
    {5,1}, //move north 1 -> (9,14)
    {3}, //turn right, from north to east
    {3}, //turn right, from east to south
    {3}, //turn right, from south to west
    {5,11}, //move west 11 -> (9,3)
    {3}, //turn right, from west to north
    {3}, //turn right, from north to east
    {2}, //pen down
    {5,10}, //draw middle horizontal cols 4-13

    // top curve at (8,14)
    {1}, //pen up
    {3}, //turn right, from east to south
    {3}, //turn right, from south to west
    {3}, //turn right, from west to north
    {5,1}, //move north 1 -> (8,13)
    {3}, //turn right, from north to east
    {2}, //pen down
    {5,1}, //draw top curve at (8,14)

    // top right col16 rows 3-7
    {1}, //pen up
    {5,2}, //move east 2 -> (8,16)
    {4}, //turn left, from east to north
    {2}, //pen down
    {5,5}, //draw col16 rows 7 down to 3

    // top horizontal row3 cols 5-15
    {1}, //pen up
    {3}, //turn right, from north to east
    {3}, //turn right, from east to south
    {3}, //turn right, from south to west
    {2}, //pen down
    {5,11}, //draw top horizontal cols 15 down to 5

    {1}, //pen up
    {6}, //print
  },
  //tgA.run(commandsB);

  //std::vector<std::vector<int>> commandsC = 
  { {1},{3},{5,3},{4},{5,7},{2},{5,5},           // top horiz row3 cols 8-12
    {1},{5,1},{3},{2},{5,1},                     // top-right (4,13)
    {1},{4},{5,1},{3},{2},{5,1},                 // top-right (5,14)
    {1},{4},{4},{5,2},{4},{5,7},{4},{2},{5,1},   // top-left (4,7)
    {1},{3},{5,1},{4},{2},{5,1},                 // top-left (5,6)
    {1},{3},{5,1},{4},{2},{5,1},                 // top-left (6,5)
    {1},{3},{5,1},{4},{2},{5,5},                 // left vert col4 rows 7-11
    {1},{4},{5,1},{3},{2},{5,1},                 // bot-left (12,5)
    {1},{4},{5,1},{3},{2},{5,1},                 // bot-left (13,6)
    {1},{4},{5,1},{3},{2},{5,1},                 // bot-left (14,7)
    {1},{5,1},{4},{2},{5,5},                     // bot horiz row15 cols 8-12
    {1},{4},{5,4},{3},{5,3},{3},{1},{5,1},       // bot-right (12,15), change from {2},{5,1} to {1},{5,1}, do not display the top * in the bottom right diagonal
    {1},{3},{5,1},{4},{2},{5,1},                 // bot-right (13,14)
    {1},{3},{5,1},{4},{2},{5,1},                 // bot-right (14,13)
    {1},{6}
  },
  //tgA.run(commandsC);

  //std::vector<std::vector<int>> commandsD = 
  { {1},{3},{5,2},{4},{5,4},{3},{2},{5,13},       // left vert col4 rows 3-15
    {1},{4},{4},{5,12},{3},{2},{5,6},              // top horiz row3 cols 5-10
    {1},{5,2},{3},{2},{5,1},                       // top curve (4,12)
    {1},{4},{5,2},{3},{2},{5,1},                   // top curve (5,14)
    {1},{4},{5,2},{3},{2},{5,6},                   // right vert col16 rows 6-11
    {1},{2},{5,1},                                 // bot curve (12,16)
    {1},{3},{5,2},{4},{2},{5,1},                   // bot curve (13,14)
    {1},{3},{5,2},{4},{2},{5,1},                   // bot curve (14,12)
    {1},{5,1},{3},{5,8},{4},{4},{2},{5,6},          // bot horiz row15 cols 5-10
    {1},{6}
  },
  //tgA.run(commandsD);

  //std::vector<std::vector<int>> commandsE = 
  { {1},{3},{5,2},{4},{5,4},{3},{2},{5,13},   // left vert col4 rows 3-15
    {1},{4},{4},{5,12},{4},{5,1},{4},{4},{2},{5,13}, // top horiz row3 cols 4-16
    {1},{3},{5,6},{3},{5,13},{4},{4},{2},{5,11},     // middle horiz row9 cols 4-14
    {1},{3},{5,6},{3},{5,11},{4},{4},{2},{5,13},     // bot horiz row15 cols 4-16
    {1},{6}
  },
  //tgA.run(commandsE);

  //std::vector<std::vector<int>> commandsF = 
  { {1},{3},{5,2},{4},{5,4},{3},{2},{5,13},   // left vert col4 rows 3-15
    {1},{4},{4},{5,12},{4},{5,1},{4},{4},{2},{5,13}, // top horiz row3 cols 4-16
    {1},{3},{5,6},{3},{5,13},{4},{4},{2},{5,11},     // middle horiz row9 cols 4-14
    {1},{6}
  },
  //tgA.run(commandsF);

  //std::vector<std::vector<int>> commandsG = 
  { // left vertical col4 rows 3-15
    {1}, //pen up
    {5,4}, //move east 4 steps
    {3}, //turn right, from east to south
    {5,2}, //move south 2 -> (2,4)
    {2}, //pen down
    {5,13}, //draw left vertical rows 3-15

    // bottom horizontal row15 cols 5-16
    {4}, //turn left, from south to east
    {2}, //pen down
    {5,12}, //draw bottom horizontal cols 5-16

    // right vertical col16 rows 14-9
    {1}, //pen up
    {4}, //turn left, from east to north
    {2}, //pen down
    {5,6}, //draw col16 rows 14 down to 9

    // middle arm row9 cols 15-10
    {4}, //turn left, from north to west
    {5,6}, //draw middle arm cols 15 down to 10

    // top-right curve col16 rows 5-3
    {3}, //turn right, from west to north
    {1}, //pen up
    {5,3}, //move north 3 -> (6,10)
    {3}, //turn right, from north to east
    {5,6}, //move east 6 -> (6,16)
    {3}, //turn right, from east to south
    {3}, //turn right, from south to west
    {3}, //turn right, from west to north
    {2}, //pen down
    {5,3}, //draw col16 rows 5,4,3

    // top horizontal row3 cols 15-5
    {1}, //pen up
    {3}, //turn right, from north to east
    {3}, //turn right, from east to south
    {3}, //turn right, from south to west
    {2}, //pen down
    {5,11}, //draw top horizontal cols 15 down to 5

    {1}, //pen up
    {6}, //print
  },
  //tgA.run(commandsG);

  //std::vector<std::vector<int>> commandsH = 
  { {1},{5,4},{3},{5,2},{2},{5,13},              // left vertical col4 rows 3-15
    {1},{4},{5,12},{4},{5,13},{3},{3},{2},{5,13}, // right vertical col16 rows 3-15
    {1},{3},{3},{5,6},{3},{3},{3},{2},{5,12},     // middle horiz row9 cols 5-16
    {1},{6},
  },
  //tgA.run(commandsH);

  //std::vector<std::vector<int>> commandsI = 
  { {1},{3},{5,3},{4},{5,4},{2},{5,11},          // top horiz row3 cols 5-15
    {1},{4},{5,1},{4},{5,5},{4},{2},{5,13},       // center vert col10 rows 3-15
    {1},{3},{5,6},{4},{4},{2},{5,11},             // bot horiz row15 cols 5-15
    {1},{6}
  },
  //tgA.run(commandsI);

  //std::vector<std::vector<int>> commandsJ = 
  { // top horiz row3 cols 5-15 (11 cells)
    {1},{3},{5,3},{4},{5,4},{2},{5,11},
    // vert col10 rows 3-12
    {1},{4},{5,1},{4},{5,5},{4},{2},{5,10},
    // curve (13,9)
    {1},{3},{5,1},{4},{2},{5,1},
    // curve (14,8)
    {1},{3},{5,1},{4},{2},{5,1},
    // left hook col4 rows 12-15
    {1},{4},{4},{5,3},{4},{5,4},{4},{2},{5,4},
    // bot horiz row15 cols 4-7
    {1},{3},{5,1},{4},{4},{2},{5,4},
    {1},{6}
  },
  //tgA.run(commandsJ);

  //std::vector<std::vector<int>> commandsK = 
  { // left vertical col4 rows 3-15
    {1},{3},{5,2},{4},{5,4},{3},{2},{5,13},
    // upper diagonal: (8,6),(7,8),(6,10),(5,12),(4,14) -- step 2 per row
    {1},{4},{4},{5,8},{3},{5,2},{3},{2},{5,1},
    {1},{4},{4},{5,2},{3},{5,2},{3},{2},{5,1},
    {1},{4},{4},{5,2},{3},{5,2},{3},{2},{5,1},
    {1},{4},{4},{5,2},{3},{5,2},{3},{2},{5,1},
    {1},{4},{4},{5,2},{3},{5,2},{3},{2},{5,1},
    // lower diagonal: (10,6),(11,8),(12,10),(13,12),(14,14) -- step 2 per row
    {1},{5,5},{3},{5,8},{4},{2},{5,1},
    {1},{4},{5,2},{3},{2},{5,1},
    {1},{4},{5,2},{3},{2},{5,1},
    {1},{4},{5,2},{3},{2},{5,1},
    {1},{4},{5,2},{3},{2},{5,1},
    {1},{6}
  },
  //tgA.run(commandsK);

  //std::vector<std::vector<int>> commandsL = 
  //letter L
  { {1}, {3}, {5, 2}, {4}, {5, 4}, {3}, {2}, {5, 13}, {1}, {3}, {5, 1}, {4}, {4}, {2}, {5, 13}, {1}, {6}
  },
  //tgA.run(commandsL);

  //std::vector<std::vector<int>> commandsM = 
  { {{1}, {3}, {5, 2}, {4}, {5, 4}, {3}, {2}, {5, 13}, {1}, {4}, {4}, {5, 13}, {3}, {5, 12}, {3}, {2}, {5, 13}, {1}, {4}, {4}, {5, 12}, {4}, {5, 11}, {4}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {2}, {5, 1}, {1}, {4}, {4}, {5, 6}, {3}, {5, 5}, {3}, {2}, {5, 1}, {1}, {3}, {5, 1}, {4}, {2}, {5, 1}, {1}, {3}, {5, 1}, {4}, {2}, {5, 1}, {1}, {3}, {5, 1}, {4}, {2}, {5, 1}, {1}, {3}, {5, 1}, {4}, {2}, {5, 1}, {1}, {3}, {5, 1}, {4}, {2}, {5, 1}, {1}, {6}}
  },
  //tgA.run(commandsM);

  //std::vector<std::vector<int>> commandsN = 
  { {1}, {3}, {5, 2}, {4}, {5, 4}, {3}, {2}, {5, 13}, {1}, {4}, {4}, {5, 13}, {3}, {5, 12}, {3}, {2}, {5, 13}, {1}, {4}, {4}, {5, 12}, {4}, {5, 11}, {4}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {2}, {5, 1}, {1}, {6}
  },
  //tgA.run(commandsN);

 
  //std::vector<std::vector<int>> commandsO = 
  { // top horiz row3 cols 8-12
    {1},{3},{5,3},{4},{5,7},{2},{5,5},
    // top-right corner: (4,13),(5,14),(6,15)
    {1},{5,1},{3},{2},{5,1},
    {1},{4},{5,1},{3},{2},{5,1},
    {1},{4},{5,1},{3},{2},{5,1},
    // right vert col16 rows 7-11
    {1},{4},{5,1},{3},{2},{5,5},
    // bot-right corner: (12,15),(13,14),(14,13)
    {1},{3},{5,1},{4},{2},{5,1},
    {1},{3},{5,1},{4},{2},{5,1},
    {1},{3},{5,1},{4},{2},{5,1},
    // bot horiz row15 cols 8-12
    {1},{5,1},{3},{5,6},{4},{4},{2},{5,5},
    // bot-left corner: (14,7),(13,6),(12,5)
    {1},{4},{5,2},{4},{5,5},{4},{2},{5,1},
    {1},{4},{4},{5,2},{4},{5,1},{4},{2},{5,1},
    {1},{4},{4},{5,2},{4},{5,1},{4},{2},{5,1},
    // left vert col4 rows 11-7
    {1},{3},{5,1},{3},{2},{5,5},
    // top-left corner: (6,5),(5,6),(4,7)
    {1},{3},{5,1},{4},{2},{5,1},
    {1},{5,2},{3},{5,1},{3},{2},{5,1},
    {1},{4},{4},{5,2},{3},{5,1},{3},{2},{5,1},
    {1},{6}
  },
  //tgA.run(commandsO);

  //std::vector<std::vector<int>> commandsP = 
  { {1}, {3}, {5, 2}, {4}, {5, 4}, {3}, {2}, {5, 13}, {1}, {4}, {4}, {5, 12}, {4}, {5, 1}, {4}, {4}, {2}, {5, 13}, {1}, {4}, {5, 1}, {4}, {4}, {2}, {5, 5}, {1}, {5, 1}, {3}, {5, 1}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {5, 11}, {4}, {4}, {2}, {5, 10}, {1}, {6}
  },
  //tgA.run(commandsP);

  //std::vector<std::vector<int>> commandsQ = 
  { // 3-step round O (same as O)
    {1},{3},{5,3},{4},{5,7},{2},{5,5},
    {1},{5,1},{3},{2},{5,1},
    {1},{4},{5,1},{3},{2},{5,1},
    {1},{4},{5,1},{3},{2},{5,1},
    {1},{4},{5,1},{3},{2},{5,5},
    {1},{3},{5,1},{4},{2},{5,1},
    {1},{3},{5,1},{4},{2},{5,1},
    {1},{3},{5,1},{4},{2},{5,1},
    {1},{5,1},{3},{5,6},{4},{4},{2},{5,5},
    {1},{4},{5,2},{4},{5,5},{4},{2},{5,1},
    {1},{4},{4},{5,2},{4},{5,1},{4},{2},{5,1},
    {1},{4},{4},{5,2},{4},{5,1},{4},{2},{5,1},
    {1},{3},{5,1},{3},{2},{5,5},
    {1},{3},{5,1},{4},{2},{5,1},
    {1},{5,2},{3},{5,1},{3},{2},{5,1},
    {1},{4},{4},{5,2},{3},{5,1},{3},{2},{5,1},
    // diagonal tail (9,10)..(15,16)
    {1},{5,4},{4},{5,3},{3},{2},{5,1},
    {1},{4},{5,1},{3},{2},{5,1},
    {1},{4},{5,1},{3},{2},{5,1},
    {1},{4},{5,1},{3},{2},{5,1},
    {1},{4},{5,1},{3},{2},{5,1},
    {1},{4},{5,1},{3},{2},{5,1},
    {1},{4},{5,1},{3},{2},{5,1},
    {1},{6}
  },
  //tgA.run(commandsQ);

  //std::vector<std::vector<int>> commandsR = 
  {
    {1}, {3}, {5, 2}, {4}, {5, 4}, {3}, {2}, {5, 13}, {1}, {4}, {4}, {5, 12}, {4}, {5, 1}, {4}, {4}, {2}, {5, 13}, {1}, {4}, {5, 1}, {4}, {4}, {2}, {5, 5}, {1}, {5, 1}, {3}, {5, 1}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {5, 11}, {4}, {4}, {2}, {5, 10}, {1}, {4}, {4}, {5, 2}, {4}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {2}, {5, 1}, {1}, {4}, {5, 1}, {3}, {2}, {5, 1}, {1}, {6}
  },
  //tgA.run(commandsR);

  //std::vector<std::vector<int>> commandsS = 
  { // top horiz row3 cols 6-14
    {1},{3},{5,3},{4},{5,5},{2},{5,9},
    // top-left 2-step: (4,5),(5,4)
    {1},{4},{4},{5,9},{4},{2},{5,1},
    {1},{3},{5,1},{4},{2},{5,1},
    // left vert col4 row 6 only
    {1},{2},{5,1},
    // 5 waist segments (each 2 cells, adjacent)
    {1},{5,1},{4},{2},{5,2},         // row7: cols 5-6
    {1},{3},{5,1},{4},{2},{5,2},     // row8: cols 7-8
    {1},{3},{5,1},{4},{2},{5,2},     // row9: cols 9-10
    {1},{3},{5,1},{4},{2},{5,2},     // row10: cols 11-12
    {1},{3},{5,1},{4},{2},{5,3},     // row11: cols 13-15
    // right vert col16 rows 12-13 only
    {1},{5,1},{3},{2},{5,2},
    // bot-right 2-step: (13,16),(14,15)
    {1},{4},{4},{5,1},{4},{4},{2},{5,1},
    {1},{3},{5,1},{4},{2},{5,1},
    // bot horiz row15 cols 6-14
    {1},{5,1},{3},{5,10},{4},{4},{2},{5,9},
    {1},{6}
  },
  //tgA.run(commandsS);

  //std::vector<std::vector<int>> commandsT = 
  { {1}, {3}, {5, 3}, {4}, {5, 3}, {2}, {5, 13}, {1}, {4}, {5, 1}, {4}, {5, 6}, {4}, {2}, {5, 13}, {1}, {6}
  },
  //tgA.run(commandsT);

  //std::vector<std::vector<int>> commandsU = 
  { {1},{3},{5,2},{4},{5,4},{3},{2},{5,10},     // left vert col4 rows 3-12
    {1},{4},{4},{5,10},{3},{5,12},{3},{2},{5,10}, // right vert col16 rows 3-12
    {1},{3},{5,11},{4},{2},{5,1},               // bot-left (13,5)
    {1},{4},{5,1},{3},{2},{5,1},                // bot-left (14,6)
    {1},{5,1},{4},{2},{5,6},                    // bot horiz row15 cols 7-12
    {1},{4},{5,2},{3},{5,2},{3},{2},{5,1},      // bot-right (14,14)
    {1},{4},{4},{5,2},{3},{5,1},{3},{2},{5,1},  // bot-right (13,15)
    {1},{6}
  },
  //tgA.run(commandsU);

  //std::vector<std::vector<int>> commandsV = 
  { {1}, {3}, {5, 2}, {4}, {5, 4}, {3}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 12}, {3}, {2}, {5, 1}, {1}, {3}, {5, 12}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 12}, {3}, {2}, {5, 1}, {1}, {3}, {5, 11}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 10}, {3}, {2}, {5, 1}, {1}, {3}, {5, 10}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 10}, {3}, {2}, {5, 1}, {1}, {3}, {5, 9}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 8}, {3}, {2}, {5, 1}, {1}, {3}, {5, 8}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 8}, {3}, {2}, {5, 1}, {1}, {3}, {5, 7}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 6}, {3}, {2}, {5, 1}, {1}, {3}, {5, 6}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 6}, {3}, {2}, {5, 1}, {1}, {3}, {5, 5}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 4}, {3}, {2}, {5, 1}, {1}, {3}, {5, 4}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 4}, {3}, {2}, {5, 1}, {1}, {3}, {5, 3}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 2}, {3}, {2}, {5, 1}, {1}, {3}, {5, 2}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 2}, {3}, {2}, {5, 1}, {1}, {3}, {5, 1}, {4}, {2}, {5, 1}, {1}, {6}
  },
  //tgA.run(commandsV);

  //std::vector<std::vector<int>> commandsW = 
  { {1}, {3}, {5, 2}, {4}, {5, 4}, {3}, {2}, {5, 13}, {1}, {4}, {4}, {5, 13}, {3}, {5, 12}, {3}, {2}, {5, 13}, {1}, {4}, {4}, {5, 7}, {4}, {5, 6}, {4}, {2}, {5, 1}, {1}, {3}, {5, 1}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 2}, {3}, {2}, {5, 1}, {1}, {3}, {5, 3}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 4}, {3}, {2}, {5, 1}, {1}, {3}, {5, 5}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 6}, {3}, {2}, {5, 1}, {1}, {3}, {5, 7}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 8}, {3}, {2}, {5, 1}, {1}, {3}, {5, 9}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 10}, {3}, {2}, {5, 1}, {1}, {6}
  },
  //tgA.run(commandsW);

  //std::vector<std::vector<int>> commandsX = 
  { {1}, {3}, {5, 2}, {4}, {5, 4}, {3}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 12}, {3}, {2}, {5, 1}, {1}, {3}, {5, 11}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 10}, {3}, {2}, {5, 1}, {1}, {3}, {5, 9}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 8}, {3}, {2}, {5, 1}, {1}, {3}, {5, 7}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 6}, {3}, {2}, {5, 1}, {1}, {3}, {5, 5}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 4}, {3}, {2}, {5, 1}, {1}, {3}, {5, 3}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 2}, {3}, {2}, {5, 1}, {1}, {3}, {5, 1}, {4}, {2}, {5, 1}, {1}, {3}, {5, 1}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 2}, {3}, {2}, {5, 1}, {1}, {3}, {5, 3}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 4}, {3}, {2}, {5, 1}, {1}, {3}, {5, 5}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 6}, {3}, {2}, {5, 1}, {1}, {3}, {5, 7}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 8}, {3}, {2}, {5, 1}, {1}, {3}, {5, 9}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 10}, {3}, {2}, {5, 1}, {1}, {3}, {5, 11}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 12}, {3}, {2}, {5, 1}, {1}, {6}
  },
  //tgA.run(commandsX);

  //std::vector<std::vector<int>> commandsY = 
  { {1}, {3}, {5, 2}, {4}, {5, 4}, {3}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 12}, {3}, {2}, {5, 1}, {1}, {3}, {5, 11}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 10}, {3}, {2}, {5, 1}, {1}, {3}, {5, 9}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 8}, {3}, {2}, {5, 1}, {1}, {3}, {5, 7}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 6}, {3}, {2}, {5, 1}, {1}, {3}, {5, 5}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 4}, {3}, {2}, {5, 1}, {1}, {3}, {5, 3}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {3}, {5, 2}, {3}, {2}, {5, 1}, {1}, {3}, {5, 1}, {4}, {2}, {5, 1}, {1}, {4}, {4}, {5, 1}, {4}, {4}, {2}, {5, 7}, {1}, {6}
  },

  //std::vector<std::vector<int>> commandsZ = 
  { {1}, {3}, {5, 3}, {4}, {5, 3}, {2}, {5, 13}, {1}, {3}, {5, 12}, {3}, {5, 13}, {4}, {4}, {2}, {5, 13}, {1}, {4}, {5, 12}, {4}, {5, 1}, {4}, {2}, {5, 1}, {1}, {3}, {5, 1}, {4}, {2}, {5, 1}, {1}, {3}, {5, 1}, {4}, {2}, {5, 1}, {1}, {3}, {5, 1}, {4}, {2}, {5, 1}, {1}, {3}, {5, 1}, {4}, {2}, {5, 1}, {1}, {3}, {5, 1}, {4}, {2}, {5, 1}, {1}, {3}, {5, 1}, {4}, {2}, {5, 1}, {1}, {3}, {5, 1}, {4}, {2}, {5, 1}, {1}, {3}, {5, 1}, {4}, {2}, {5, 1}, {1}, {3}, {5, 1}, {4}, {2}, {5, 1}, {1}, {3}, {5, 1}, {4}, {2}, {5, 1}, {1}, {6}
  },
  //tgA.run(commandsZ);
};

std::vector<std::vector<int>> CMDS_DIGITS[] = {
  //commands0: comments to draw 0
  { {1},   // pen up, facing east by default
    {5,4}, // move east 4 steps from (0,1) to (0,4)
    {3},   // turn right, from east to south
    {5,3}, // move 3 steps, from (1,4) to (3,4)
    {4},   // turn left, from south to east again

    {2},   // pen down

    // draw top horizontal line
    {5,12},// move 12 steps, from

    // draw right vertical line
    {3},{5,12},

    // draw bottom horizontal line
    {3},{5,12},

    // draw left vertical line
    {3},{5,12},

    // print
    {6}
  },

  //commands1: comments to draw 1
  { {1},{5,3},{3},{5,3},{4},
    {5,5},
    {2},{5,1},{3},{5,1},{3},{5,1},
    {1},{3},{5,1},{3},{5,1},{3},{5,1},
    {2},{5,11},
    {4},{5,2},{1},{4},{5,1},{4},{5,2},
    {2},{4},{5,1},{3},{5,2},
    {6}
  },

  //commands2
  {  {1},{5,3},{3},{5,3},{4},
     {2},{5,13},{3},{5,6},{3},{5,12},{4},{5,6},{4},{5,12},
     {6} 
  },
		
  //commands3
  {  {1},{5,3},{3},{5,3},{4},
     {2},{5,13},{3},{5,6},
    {3},{5,12},{1},
    {4},{5,5},{2},{5,1},{4},
    {5,12},{4},{5,6},{6}
  },

  //commands4
  { {1},   // pen up, facing east by default
    {5,4}, // move east 4 steps from (0,1) to (0,4), where 4-1+1 = 4
    {3},   // turn right, from east to south
    {5,2}, // move 2 steps, from (1,4) to (2,3), where 2-1+1 = 2

    {2},   // pen down
    
    // draw left line
    {5,7},// move 12 steps, from (3,4) to (9,4), where 9-3+1 = 7

    {4}, // turn left, from south to east
    {5,12}, // move from (9,5) to (9,16), a total of of 16-5+1 = 12 steps

    // move to one step above the top of vertical line, ie, (2,16), facing south
    {1}, // pen up
    {4}, // turn left, from east to north
    {5,7}, // move from (8,16) to (2,16), a total of 8-2+1 = 7 steps
    {3}, // turn right, from north to east
    {3}, // turn right, from east to south

    {2}, // pen down
    {5,13}, // move from (3,16) to (15,16), a total of 15-3+1 = 13 steps

    // print
    {6}
  },

  //commands5
  { // facing east in the beginning
    {1}, // pen up
    {5,16}, // move from (0,1) to (0,16)
    {3}, // turn right from east to south
    {5,2}, // move three steps in the south direction, from (1,16) to (2,16)
 
    {2}, // pen down
    {5,1}, // draw from (3,16) to (3,16)
    {3}, // trun right, from south to west
    {5,12}, // draw horizontal line from (3,15) to (3,4) 
 
    // draw left upper vertical line of 5, from (4,4) to (4,9)
    {4}, // turn left
    {5,6}, // draw vertical line
 
    // draw middle horizontal line 
    {4}, // turn left from south to east
    {5,12}, // from (9,5) to (9,16)
 
    // draw right lower vertical line
    {3}, // turn right from east to south
    {5,6}, // draw 6 steps from (10,16) to (15, 16)
 
    // draw bottom horizontal line
    {3}, // turn right from south to west
    {5,12}, // draw 12 steps from (15,15) to (15,4)
 
    {6} // print
  },

  //commands6
  { // facing east in the beginning
    {1}, // pen up
    {5,16}, // move from (0,1) to (0,16)
    {3}, // turn right from east to south
    {5,2}, // move three steps in the south direction, from (1,16) to (2,16)
 
    {2}, // pen down
    {5,1}, // draw from (3,16) to (3,16)
    {3}, // trun right, from south to west
    {5,12}, // draw horizontal line from (3,15) to (3,4) 
 
    // draw left upper vertical line of 5, from (4,4) to (4,15)
    {4}, // turn left, from west to south
    {5,12}, // draw vertical line
 
    // draw bottom horizontal line
    {4}, // turn left, from south to east
    {5,12}, // draw 12 steps from (15,5) to (15,16)
 
    // draw right lower vertical line
    {4}, // turn left from east to north
    {5,6}, // draw 6 steps from (16,14) to (16, 9)
 
    // draw middle horizontal line 
    {4}, // turn left from north to west
    {5,12}, // from (9,5) to (9,16)
 
    // print
    {6}
  },

  //commands7
  { {1},  // pen up
    {5,3},// move east 3 steps
    {3},  // turn right from east, facing south
    {5,3},// move south 3 steps
    {4},  // turn left from south, face east again
 
    //## draw top horizontal line
    {2}, // pen down
    {5,13},// move 13 steps, from (3,4) to (3,16),
 
    {3}, // turn right, from east to south
    {5,12}, // move 12 steps, from (4,16) to (15,16)
 
    {6} //print out
  },

  //commands8
  { {1},   // pen up, facing east by default
    {5,4}, // move east 4 steps from (0,1) to (0,4)
    {3},   // turn right, from east to south
    {5,3}, // move 3 steps, from (1,4) to (3,4)
    {4},   // turn left, from south to east again

    {2},   // pen down
    
    // draw top horizontal line
    {5,12},// move 12 steps, from 

    // draw right vertical line, facing south
    {3},{5,12},

    // draw bottom horizontal line, facing west
    {3},{5,12},

    // draw left vertical line, facing north
    {3},{5,12},

    // pen up, turn south 
    {1}, // pen up
    {3}, // turn right, from south to east
    {3}, // turn right, from east to north
    {5,6}, // move 6 steps, at (9,4)
    {4}, // turn left, from north to east
  
    // draw middle line
    {2},
    {5,12},

    // print
    {6}
  },

  //commands9
  { {1},   // pen up, facing east by default
    {5,4}, // move east 4 steps from (0,1) to (0,4)
    {3},   // turn right, from east to south
    {5,3}, // move 3 steps, from (1,4) to (3,4)
    {4},   // turn left, from south to east again

    {2},   // pen down
    
    // draw top horizontal line
    {5,12},// move 12 steps, from 

    // draw right vertical line, facing south
    {3},{5,12},

    // draw bottom horizontal line, facing west
    {3},{5,12},

    // draw left top vertical line, facing north
    {3}, 
    {1},
    {5,5}, // move to (10,4)
    {2},
    {5,7}, // move to (3,4)

    // pen up, turn south 
    {1}, // pen up
    {3}, // turn right, from south to east
    {3}, // turn right, from east to north
    {5,6}, // move 6 steps, at (9,4)
    {4}, // turn left, from north to east
  
    // draw middle line
    {2},
    {5,12},
 
    // print
    {6} 
  },
};

std::vector<std::vector<int>> CMDS_MINUS = {
  {1},        // pen up
  {3},{5,9},  // turn right -> SOUTH, move 9 -> (9,0)
  {4},{5,4},  // turn left  -> EAST,  move 4 -> (9,4)
  {2},{5,10}, // pen down, draw east 10 -> row9 cols 5-14
  {1},{6}
};

void display(int num);
void display(const std::string& str);

int main() {
  std::cout << "Enter an integer: ";
  int num;
  std::cin >> num;
  std::cout << "integer shape is follows:\n"; //this line is needed
  
  // TODO: Call display(num).

  // Discard the newline left in the buffer after reading the integer,
  // so that the subsequent getline call reads correctly.
  std::cin.ignore(INT_MAX, '\n');
  std::cout << "Enter a string (only supports capital letters, spaces, and digits: ";
  std::string str;
  getline(std::cin, str);
  std::cout << "string shape is follows:\n"; //this line is needed
  
  // TODO: Call display(str).

  return 0;
}

void display(int num) {
  // TODO:
  // (1) Declare sign as an int initialized to 1.
  // (2) If num is negative:
  //     (a) Set sign to -1.
  //     (b) Set num to its absolute value (e.g., -123 becomes 123)
  //         so that num % 10 always returns a non-negative digit.

  // TODO: Declare a TurtleGraphics object named tg.

  // Declare shapes as a vector of Floor objects.
  std::vector<Floor> shapes;
  int digit;
  do {
    // TODO: Extract the least significant digit of num into variable digit.

    // TODO: Call tg.run() with CMDS_DIGITS[digit] to draw that digit.
    // Example: if digit is 3, run CMDS_DIGITS[3], which draws the digit 3.

    // TODO: Call tg.getFloor() and append the result to shapes.

    // TODO: Call tg.restart() to clear the floor and reset the turtle
    //       to position (0, 0) facing east, ready to draw the next digit.

    // TODO: Remove the least significant digit from num.
    //       Example: if num is 123, it becomes 12.

  } while (...); // TODO: Continue as long as num has remaining digits.

  // TODO: If sign is -1, call tg.run() with CMDS_MINUS to draw the minus sign,
  //       then append tg.getFloor() to shapes.
  //
  // Note: push_back() adds to the end, so digits are stored in reverse order
  // (least significant first). Example:
  //   display(-123): shapes contains: [3, 2, 1, -]
  //   display(123):  shapes contains: [3, 2, 1]

  // Get the first element of shapes to determine row/column dimensions.
  // shapes is guaranteed non-empty since num has at least one digit.
  const Floor& floor = ...; // TODO: first element of shapes

  // TODO: Outer loop: iterate over each row of the floor.
  for (int row = 0; row < ...; row++) {

    // TODO: Middle loop: iterate over shapes in REVERSE order (last index to first).
    //       Reason: digits were stored least-significant-first, so reversing
    //       prints them left-to-right (most significant digit first).
    for (int k = ...; ...; ...) {

      // TODO: Inner loop: iterate over each column of the current shape.
      for (int col = ...; col < ...; ...) {
        std::cout << shapes[...].at(..., ...); // TODO: print character at (row, col) of shapes[k]
      }
    }

    std::cout << '\n';
  }
}

void display(const std::string& str) {
  TurtleGraphics tg;
  std::vector<Floor> shapes;

  // TODO: Process each character ch in str:
  // (1) Uppercase letter (isupper): run CMDS_CAP_LETTERS[ch - 'A'].
  //     Example: 'A' -> CMDS_CAP_LETTERS[0], 'B' -> CMDS_CAP_LETTERS[1].
  // (2) Lowercase letter (islower): convert to uppercase with toupper(ch),
  //     then apply the same logic as (1).
  // (3) Digit character (isdigit): run CMDS_DIGITS[ch - '0'].
  //     Example: '0' -> CMDS_DIGITS[0], '1' -> CMDS_DIGITS[1].
  //     Note: unlike display(int), where digits are extracted numerically,
  //     here a digit is a char (from '0' to '9'), so use ch - '0' to get its index.
  // (4) Space character (isspace): call tg.restart() to produce a blank floor.
  // (5) Any other character: skip it with continue.
  // (6) After processing ch, append tg.getFloor() to shapes.
  // (7) Call tg.restart() to reset the floor and turtle for the next character.

  if (...) { // TODO: condition: shapes is empty (str had no drawable characters)
    std::cout << "no string inputed" << "\n";
    return;
  }

  // Shapes are stored left-to-right, matching the order of characters in str.
  // Example: "AB 12" -> shapes contains: [A, B, space, 1, 2]
  const Floor& floor = ...; // TODO: first element of shapes

  // TODO: Outer loop: iterate over each row of the floor.
  for (int row = ...; row < ...; ...) {

    // TODO: Middle loop: iterate over shapes in FORWARD order (first to last),
    //       since characters in str are processed left to right.
    for (int k = ...; ...; ...) {

      // TODO: Inner loop: iterate over each column of the current shape.
      for (int col = ...; col < ...; ...) {
        std::cout << shapes[...].at(..., ...); // TODO: print character at (row, col) of shapes[k]
      }
    }

    std::cout << '\n';
  }
}
