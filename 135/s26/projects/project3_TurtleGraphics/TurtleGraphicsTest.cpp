/*
 Sample input/output:
Enter command, 9 to stop: 3
Next command: 5 4 
Next command: 4 
Next command: 5 3 
Next command: 2 
Next command: 5 13
Next command: 3
Next command: 5 6
Next command: 3
Next command: 5 12
Next command: 4
Next command: 5 6
Next command: 4
Next command: 5 12
Next command: 6
                    
                    
                    
                    
    *************   
                *   
                *   
                *   
                *   
                *   
    *************    
    *               
    *               
    *               
    *               
    *               
    *************    
                    
                    
                    
Next command: 9

                    
                    
                    
                    
    *************   
                *   
                *   
                *   
                *   
                *   
                *   
                *   
                *   
                *   
                *   
                *   
                    
                    
                    
                    
                    
                    
                    
                    
    *************   
                *   
                *   
                *   
                *   
                *   
    ************    
    *               
    *               
    *               
    *               
    *               
    ************    
                    
                    
                    
                                        
                                        
                                        
                                        
    *************       *************   
                *                   *   
                *                   *   
                *                   *   
                *                   *   
                *                   *   
                *       ************    
                *       *               
                *       *               
                *       *               
                *       *               
                *       *               
                *       ************  
*/
//File name: /Users/laptopuser/Documents/courses_macbook_pro/cs135/s26/turtleGraphics/cpp/TurtleGraphicsTest.cpp

#include <iostream>
#include <string>
#include <vector>
#include "TurtleGraphics.hpp"

void display(int num);

int main() {
  TurtleGraphics tg;
  tg.run();

  display(1234567);

  std::cout << "letter A:" << std::endl;

  //rules to turn directions 
  //original  turn    updated_direction
  //east      left    north
  //east      right   south
  //west      left    south
  //west      right   north
  //south     left    east
  //south     right   west
  //north     left    west
  //north     right   east

  std::vector<std::vector<int>> commandsA = {
    //pen up, move to (9,5), heading to east
    //by default, heading east
    //{1}, //by default, pen is up
    {5,9}, //move to row col at (0,9) 
    {3}, //turn right, heading south
    {5,5},//move to row col at (5,9)
    {4}, //turn left, heading east  


    //=== first layer ===//
    //draw one * at (10,5)
    {2}, //pen down
    {5,1}, //move one spot, draw one * at (10,5) in east direction

    //=== second layer ===//
    //draw the second * at (9,6), which is south west from (10,5) 
    {1}, //pen up
    {3}, //turn right, heading south
//    {4}, //turn left, heading north
    {5,1}, //move one spot in south direction, at (10,6) now
    {3}, //turn right, heading west
    {2}, //pen down
    {5,1}, //move one spot, draw an * at (9,6). The turtle heads the west direction

    //draw the second * at (11,6), which is two spots from (9,6) 
    {1}, //pen up
    {4}, //turn left, heading north
    {4}, //turn west, heading west
    {5,1}, //move to (10,6)
    {2},
    {5,1}, //draw * at (11,6)

    //=== third layer ===//
    //draw an * at (12,7), starting from (11,6) and heading east
    {3}, //turn right, heading south
    {1}, //pen up
    {5,1}, //move to (12,6) in the south direction 
    {4}, //turn left, heading east
    {2}, //pen down
    {5,1}, //draw an * at (12,7), heading to east

    //draw an * at (12,8), starting from (12,7), heading to west
    {1}, //pen up
    {3}, //turn right, heading north
    {3}, //turn right, heading west 
    {5,3}, //move to (10,7)
    {2}, //pen down
    {5,1}, //draw an * at (11,8), heading east

    //=== fourth layer ===//
    //draw an * at (12,9)
    {4}, //turn left, heading south
    {1}, //pen up
    {5,1}, //move one spot, in (12,8)
    {3}, //turn right, heading east
    {2}, //pen down
    {5,1}, //draw an * at (12,9), heading to east

    //draw an * at (12,4)
    {1}, //pen up
    {3}, //turn right, heading south
    {3}, //turn right, heading west
    {5,5}, //move one spot in the west direction, at (12,2)
    {2}, //pen down
    {5,1}, //draw * at (12,4), heading east

    //=== fifth layer ===//
    //draw * at (13,8)
    {3}, //turn right, heading south
    {1}, //pen up
    {5,1}, //move to (12,6) in the south direction
    {4}, //turn left, heading east
    {2}, //pen down
    {5,1}, //draw an * at (12,7), heading to east

    //draw an * at (12,8), starting from (12,7), heading to west
    {1}, //pen up
    {3}, //turn right, heading north
    {3}, //turn right, heading west
    {2}, //pen down
    {5,8}, //move to (10,7)

    //draw the left leg, from top to bottom
    {4}, //turn left, from west turn to south
    {5,5}, //draw 6 asterisks towards the south direction

    //draw the right leg, from bottom to top
    //move to the bottom of right leg
    {1}, //pen up
    {4}, //turn left, from south to east
    {5,8}, //move the middle line

    {3}, //turn right, from east to south
    {5,1}, //down one step since the first step of {5,x} is not drawn
    {4}, //turn left, from south to east
    {4}, //turn right, from east to north
    {2}, 
    {5,6},

    {6}, //print
  };

  TurtleGraphics tgA;
  tgA.run(commandsA);

  std::vector<std::vector<int>> commandsB = {
    {1}, //pen up
    {5,6}, //move east 6 steps
    {3}, //turn right, from east to south
    {5,5}, //move down 5 steps
    {2}, //pen down
    {5,11}, //draw from (4,6) to (14, 6), where the first dimension is row.
    
    //low half-circle
    {4}, //turn left, from south to east
    {5,5}, //draw the bottom 5 asterisks //TODO
    {1}, //pen up
    {5,1}, //move one step to east
    {4}, //turn left, from east to north
    
    {2}, //pen down
    {5,3}, //move three steps north
    {1}, //pen up
    {5,1}, //move one step to the north direction
    {4}, //turn left, from north to west
    {2}, //pen down
    {5,1}, //draw one * in the west
    
    {1}, //pen up
    {3}, //turn right, from west to north
    {5,1}, //move one step to the north
    {4}, //turn left, from north to west
    {2}, //pen down
    {5,4}, //draw * in the west dirction //TODO
    
    {1}, //pen up
    {3}, //turn right, from west to north
    {5,1}, //move one step up
    {3}, //turn right, from north to east
    {5,3}, //TODO, orginal {5,2}
    {2}, //pen down
    {5,1}, //draw one * in the east direction
    {1}, //pen up
    {5,1},
    {4}, //turn left, from east to north
    {2},
    {5,3}, //draw three asterisks
    {1}, //pen up
    {5,1}, //move one step north
    {4}, //turn left, from north to east
    {2}, //pen down
    {5,5}, //the top 4 asterisks in the top half-circle //TODO

    {6}, //print
  };

  tgA.run(commandsB);

//letter L
 std::vector<std::vector<int>> commandsL = {
    //12 rows and 12 columns, where the top left point is at (4,4).
    //12 columns + 4 spaces to the left + 4 spaces to the right = 20
    //4 empty rows on the top + 12 rows + 4 empty rows at the bottom = 20
    //start from (0,0),
    //pen up, move to (5,5), heading to south
    //by default, heading east
    {1}, //pen up
    {5,5}, //move to (5,0)
    {3}, //turn right, heading south
    {5,5},//move to (5,5)

    {2}, //pen down
    {5,8}, //draw 12 * in the south direction 

    {4}, //turn left, heading east
    {5,8}, //draw 8 * in the east direction

    {6},
};

  TurtleGraphics tgL;
  tgL.run(commandsL);

  return 0;
}

void display(int num) {
  std::vector<std::vector<std::vector<int>>> digitCommands = {
    //commands0
    { {1}, {5,3}, {3}, {5,3}, {4}, //pen up, move to (3,4), heading to east
      {2}, {5, 12}, {3}, {5, 12}, 
      {3}, {5, 12}, {3}, {5, 12}, 
      {6} 
    }, 

    //commands1
    { {1}, {5,3}, {3}, {5,3}, {4}, //pen up, move to (3,4), heading to east
      {5, 5}, 
      {2}, {5,1}, {3}, {5, 1}, {3}, {5, 1},  
      //the little edge out of the top of digit 1.
      {1}, {3}, {5,1}, {3}, {5,1}, {3}, {5,1}, 
      //return to the original position.
      {2}, {5, 11},
      {4}, {5, 2}, {1}, {4}, {5,1}, {4}, {5, 2}, 
      {2}, {4}, {5, 1}, {3}, {5, 2}, 
      {6}
    },
    //TODO: can commands1 be simplified?
		
    //commands2
    { {1}, {5,3}, {3}, {5,3}, {4}, //pen up, move to (3,4), heading to east
      {2},
      {5,13},
      {3},
      {5,6},
      {3},
      {5,12},
      {4},
      {5,6},
      {4},
      {5,12},
      {6}
    },

    //commands3
    { {1}, {5,3}, {3}, {5,3}, {4}, //pen up, move to (3,4), heading to east
      {2}, {5,13}, {3}, {5,6}, 
      {3}, {5, 12}, {1}, 
      {4}, {5, 5}, {2}, {5,1}, {4}, 
      {5,12}, {4}, {5,6}, {6}
    },

    //commands4
    { {1}, {5,3}, {3}, {5,3}, {4}, //pen up, move to (3,4), heading to east
      {5, 11}, {2}, {5,1}, {3}, 
      {5, 6}, {3}, {5,12}, 
      {3}, {5, 6}, {1}, {3},
      {5,12}, {2}, {3}, {5,12}, {6}
    },

    //commands5
    { {1}, {5,3}, {3}, {5,3}, {4}, //pen up, move to (3,4), heading to east
      {2}, {5,12}, {1}, {3}, {5,5}, 
      {2}, {5,1}, {3}, {5, 12}, {3}, {5, 6}, 
      {1}, {3}, {5, 12}, {3}, {5, 6}, 
      {2}, {5, 6}, {3}, {5,12}, {6} 
    },

    //commands6
    { {1}, {5,3}, {3}, {5,3}, {4}, //pen up, move to (3,4), heading to east
      {2}, {5,12}, {1}, {3}, {5,5},  
      {2}, {5,1}, {3}, {5,12}, {3}, {5,6}, 
      {1}, {3}, {5,12}, {3}, {5,6}, 
      {2}, {5,6}, {3}, {5,12}, 
      {3}, {5,12}, {6}
    },

    //commands7
    { {1}, {5,2}, {3}, {5,3}, {4}, //pen up, move to (3,3), heading to east
      {2}, {5,13}, {3}, {5, 12}, {6}
    },

    //commands8
    { {1}, {5,3}, {3}, {5,3}, {4}, //pen up, move to (3,4), heading to east
      {2}, {5, 12}, {3}, {5, 12}, 
      {3}, {5, 12}, {3}, {5, 12}, 
      {1}, {3}, {5, 12}, {3}, {5, 6},
      {2}, {3}, {5, 12}, {6}
    },

    //commands9
    { {1}, {5,3}, {3}, {5,3}, {4}, //pen up, move to (3,4), heading to east
      {2}, {5,12}, {3}, {5,12}, 
      {3}, {5,12}, {1}, {3}, {5,6}, 
      {2}, {5,6}, {1}, {3}, {5,12}, 
      {3}, {5,6}, {2}, {3}, {5,12}, 
      {6}
    },
  };

  TurtleGraphics tg;

  std::vector<Floor> shapes;
  int digit;
  do {
    digit = num % 10;

    tg.restart(); //explicitly reset before each digit for clarity 
    
    tg.run(digitCommands[digit]);
    shapes.push_back(tg.getFloor()); //get the grid of the floor run that commands to draw the digit

    num /= 10;
  } while (num != 0);

  //vector has only push_back method, no push_front,
  //so if num is 12, the vector shapes hold shape 2, shape 1,
  //that is, the last digit is the first shape to be displayed in the leftmost position.
  const Floor& floor = shapes[0];
  for (int row = 0; row < floor.getNumRows(); row++) {
    //for (int k = 0; k < shapes.size(); k++) {
    for (int k = shapes.size()-1; k >= 0; k--) {
      for (int col = 0; col < floor.getNumCols(); col++) {
        std::cout << shapes[k].at(row, col);
      }
    }			

    std::cout << std::endl;
  }
}
