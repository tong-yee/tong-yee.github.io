#include <iostream>
#include <cstdlib> //srand
#include <ctime> //time
#include "TurtleGraphics.hpp"
//g++ -o tg Turtle.cpp Floor.cpp TurtleGraphics.cpp TurtleGraphicsUnitTest.cpp
//test default constructor using
//./tg A
//test non-default constructor using
//./tg B
//test run commands stored in a vector using
//./tg C
//test run commands with console input using 
//./tg D < input3.txt

int main(int argc, const char *argv[]) {
  if (argc != 2) {
     std::cout << "Need 'A'-'D' in command line parameter" << std::endl;
     return -1;
  }

  //unit-testing for methods of Turtle class, which has no constructors 
  char type = *argv[1];
  std::string prompt;

  srand(time(NULL));
  const int SIZE = 20;
  switch (type) {
    case 'A': { //test default constructor of TurtleGraphics
      TurtleGraphics tg;
      Floor floor = tg.getFloor();
      if (floor.getNumRows() != SIZE || floor.getNumCols() != SIZE) {
        std::cout << "the number of rows or the number of columns of the floor of the default constructor is not correct." << std::endl;
      }
      else {
        std::cout << "the number of rows and the number of columns of the floor of the default constructor are correct." << std::endl; 
      }
      break;
    }

//g++ -o tg Turtle.cpp Floor.cpp TurtleGraphics.cpp TurtleGraphicsUnitTest.cpp
//./tg A
//expected output:
//the number of rows and the number of columns of the floor of the default constructor are correct.

    case 'B': { //test restart method
      TurtleGraphics tg;
      tg.restart();
      Turtle tur = tg.getTurtle();
      Floor floor = tg.getFloor();
      if ( !(tur.isPenUp() && tur.getRow() == 0 && tur.getCol() == 0 && tur.getHeading() == Direction::EAST) ) {
        std::cout << "turtle status after restart method is not correct" << std::endl;
        break;
      }
     
      bool notSpace = false;
      for (int row = 0; row < floor.getNumRows() && !notSpace; row++) {
        for (int col = 0; col < floor.getNumCols() && !notSpace; col++) {
          if (floor.at(row, col) != ' ') {
            notSpace = true;
          }
        }
      }

      if (notSpace) {
        std::cout << "the floor is not cleared in restart method of TurtleGraphics" << std::endl;
        break;
      }
      
      std::cout << "restart method of TurtleGraphics is correct." << std::endl;
      break;
    }

//g++ -o tg Turtle.cpp Floor.cpp TurtleGraphics.cpp TurtleGraphicsUnitTest.cpp
//./tg B
//expected output:
//restart method of TurtleGraphics is correct.

    case 'C': {
      //test run(std::vector<std::vector<int>> commands)
      std::vector<std::vector<int>> commands = {
        // facing east in the beginning
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
   
        // print
        {6}
      };

      TurtleGraphics tg;
      tg.run(commands);

      // After run() finishes, inspect the floor
      const Floor& floor = tg.getFloor();
    
      bool correct = true;
     
      //test the shape of 5
      //top horizontal line of 5 at row index 3, 9, 15 
      //(3, c) for c in range(4, 17)   // top horizontal line
      //(9, c) for c in range(4, 17)   // middle horizontal line
      //(15, c) for c in range(4, 17)  // bottom horizontal line
      for (int col = 4; col <= 16; col++) { //top line
        if (floor.at(3, col) != '*' || floor.at(9, col) != '*' || floor.at(15, col) != '*') {
          correct = false; 
          break;
        }
      }

      //left vertical line of 5 at column index 16
      //(r, 4) for r in range(3, 10)  // left upper veritical line
      for (int row = 3; row < 10; row++) {
        if (floor.at(row, 4) != '*') {
          correct = false;
          break;
        }
      }

      //(r, 16) for r in range(9, 16)    # right lower vertical line
      //right vertical line of 5 at column index 16
      for (int row = 9; row < 16; row++) {
        if (floor.at(row, 16) != '*') {
          correct = false;
          break;
        }
      }
    
      if (correct) {
        std::cout << "run (commands) method is correct" << std::endl;
      } else {
          std::cout << "run (commands) method is not correct" << std::endl;
      }
      break;
    }

//g++ -o tg Turtle.cpp Floor.cpp TurtleGraphics.cpp TurtleGraphicsUnitTest.cpp
//./tg C 
//expected output
//pen up
//row col at (0,16)
//heading: SOUTH
//row col at (2,16)
//pen down
//row col at (3,16)
//heading: WEST
//row col at (3,4)
//heading: SOUTH
//row col at (9,4)
//heading: EAST
//row col at (9,16)
//heading: SOUTH
//row col at (15,16)
//heading: WEST
//row col at (15,4)
//            1         
//  01234567890123456789
// 0                    
// 1                    
// 2                    
// 3    *************   
// 4    *               
// 5    *               
// 6    *               
// 7    *               
// 8    *               
// 9    *************   
//10                *   
// 1                *   
// 2                *   
// 3                *   
// 4                *   
// 5    *************   
// 6                    
// 7                    
// 8                    
// 9                    

//run (commands) method is correct

    case 'D': {
      //test run() method — reads from stdin
                   
      TurtleGraphics tg;
      tg.run();
    
      // After run() finishes, inspect the floor
      const Floor& floor = tg.getFloor();
    
      bool correct = true;

      //top horizontal line of digit 3 at row index 3, 9, 15
      for (int col = 4; col <= 16; col++) {
        if (floor.at(3, col) != '*' || floor.at(9, col) != '*' || floor.at(15, col) != '*') {
          correct = false; 
          break;
        }
      }

      //right vertical line of digit 3 at column index 16
      for (int row = 3; row <= 15; row++) {
        if (floor.at(row, 16) != '*') {
          correct = false;
          break;
        }
      }
    
      if (correct) {
        std::cout << "run (console) method is correct" << std::endl;
      } else {
          std::cout << "run (console) method is not correct" << std::endl;
      }
      break;
    }

//the contents of input3.txt for commands to draw digit 3 is as follows.
//1
//5 3
//3
//5 3
//4
//2
//5 13
//3
//5 6 
//3
//5 12
//1
//4
//5 5
//2
//5 1
//4 
//5 12
//4
//5 6
//6
//9

//g++ -o tg Turtle.cpp Floor.cpp TurtleGraphics.cpp TurtleGraphicsUnitTest.cpp
//./tg D < input3.txt
//Sample output:
//             1         
//  01234567890123456789
// 0                    
// 1                    
// 2                    
// 3    *************   
// 4                *   
// 5                *   
// 6                *   
// 7                *   
// 8                *   
// 9    *************   
//10                *   
// 1                *   
// 2                *   
// 3                *   
// 4                *   
// 5    *************   
// 6                    
// 7                    
// 8                    
// 9
//
//Next command: run (console) method is correct

    default: 
      std::cout << "Unrecognized option: " << type << std::endl;
  }

  return 0;
}
