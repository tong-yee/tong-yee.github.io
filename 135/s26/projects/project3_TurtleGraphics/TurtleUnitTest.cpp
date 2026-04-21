//file name: TurtleUnitTest.cpp
#include <iostream>
#include <cstdlib> //srand
#include <ctime> //time
#include "Turtle.hpp"
//g++ -o turtle Turtle.cpp TurtleUnitTest.cpp
//test default constructor using
//./turtle A

int main(int argc, const char *argv[]) {
  if (argc != 2) {
     std::cout << "Need 'A'-'G' in command line parameter" << std::endl;
     return -1;
  }

  //unit-testing for methods of Turtle class, which has no constructors 
  char type = *argv[1];
  std::string prompt;

  srand(time(NULL));
  const int SIZE = 20;
  switch (type) {
    case 'A': { //test reset method
      Turtle tur;
      tur.reset();
      if (tur.isPenUp() && tur.getRow() == 0 && tur.getCol() == 0 && tur.getHeading() == Direction::EAST) {
        std::cout << "reset method is correct" << std::endl;
      }
      else {
        std::cout << "reset method is not correct" << std::endl;
      }
      break;
    }
//When running ./turtle A, 
//where turtle obtained by 
//g++ -o turtle TurtleUnitTest.cpp Turtle.cpp
//expected output is as follows 
//reset method is correct


    case 'B': { //test isPenUp, liftUpPen, and putDownPen methods
      Turtle tur;
      tur.liftUpPen();
      bool penUpTrue = tur.isPenUp();

      tur.putDownPen();
      bool penUpFalse = tur.isPenUp();
     
      if (penUpTrue && penUpFalse == false) {
        std::cout << "isPenUp, liftUpPen, and putDownPen methods are correct" << std::endl;
      }
      else {
        std::cout << "isPenUp, liftUpPen, and putDownPen methods are not correct" << std::endl;
      }

      break;
    }
//Running the following two comands
//g++ -o turble TurtleUnitTest.cpp Turtle.cpp
//./turtle B
//expected output: isPenUp, liftUpPen, and putDownPen methods are correct

    case 'C': { //test setRow and getRow methods
      Turtle tur;
      int row = rand() % SIZE;
      tur.setRow(row);
      if (tur.getRow() == row) {
        std::cout << "setRow and getRow methods are correct" << std::endl;
      }
      else {
        std::cout << "setRow and getRow methods are not correct" << std::endl;
      }

      break;
    }
//expected output after running ./turtle C
//setRow and getRow methods are correct

    case 'D': { //test setCol and getCol methods
      Turtle tur;
      int col = rand() % SIZE;
      tur.setCol(col);
      if (tur.getCol() == col) {
        std::cout << "setCol and getCol methods are correct" << std::endl;
      }
      else {
        std::cout << "setCol and getCol methods are not correct" << std::endl;
      }

      break;
    }
//expected output after running ./turtle D
//setCol and getCol methods are correct

    case 'E': { //test turnLeft, setHeading and getHeading methods
      Turtle tur;

      tur.setHeading(Direction::EAST);
      tur.turnLeft();
      if (tur.getHeading() != Direction::NORTH) {
        std::cout << "When direction is EAST, turnLeft method is not correct." << std::endl;
        break;
      }
 
      tur.setHeading(Direction::WEST);
      tur.turnLeft();
      if (tur.getHeading() != Direction::SOUTH) {
        std::cout << "When direction is WEST, turnLeft method is not correct." << std::endl;
        break;
      }

      tur.setHeading(Direction::NORTH);
      tur.turnLeft();
      if (tur.getHeading() != Direction::WEST) {
        std::cout << "When direction is NORTH, turnLeft method is not correct." << std::endl;
        break;
      }

      tur.setHeading(Direction::SOUTH);
      tur.turnLeft();
      if (tur.getHeading() != Direction::EAST) {
        std::cout << "When direction is SOUTH, turnLeft method is not correct." << std::endl;
        break;
      }
     
      std::cout << "turnLeft method is correct." << std::endl;
      break;
    }
//expected output after running ./turtle E:
//turnLeft method is correct.

    case 'F': { //test turnRight, setHeading and getHeading methods
      Turtle tur;

      tur.setHeading(Direction::EAST);
      tur.turnRight();
      if (tur.getHeading() != Direction::SOUTH) {
        std::cout << "When direction is EAST, turnRight method is not correct." << std::endl;
        break;
      }
 
      tur.setHeading(Direction::WEST);
      tur.turnRight();
      if (tur.getHeading() != Direction::NORTH) {
        std::cout << "When direction is WEST, turnRight method is not correct." << std::endl;
        break;
      }

      tur.setHeading(Direction::NORTH);
      tur.turnRight();
      if (tur.getHeading() != Direction::EAST) {
        std::cout << "When direction is NORTH, turnRight method is not correct." << std::endl;
        break;
      }

      tur.setHeading(Direction::SOUTH);
      tur.turnRight();
      if (tur.getHeading() != Direction::WEST) {
        std::cout << "When direction is SOUTH, turnRight method is not correct." << std::endl;
        break;
      }
     
      std::cout << "turnRight method is correct." << std::endl;
      break;
    }
//expected output after running ./turtle F:
//turnRight method is correct.

    case 'G': { //  void move(int steps);
      Turtle tur;
      
      //move in east direction 
      tur.setHeading(Direction::EAST);
      int numStepsEast = 0;
      while (numStepsEast == 0) {
        numStepsEast = rand() % SIZE;
      }
      //Make sure numStepsEast is not zero.

      tur.move(numStepsEast);

      if (tur.getRow() != 0 || tur.getCol() != numStepsEast) {
        std::cout << "When direction is Direction::EAST, move method of " << numStepsEast << " steps is wrong." << std::endl;
        break;
      }

      //move in south direction from (0, numStepsEast)
      tur.setHeading(Direction::SOUTH);
      int numStepsSouth = 0;
      while (numStepsSouth == 0) {
        numStepsSouth = rand() % SIZE;
      }
      //Make sure numStepsSouth is not zero.

      tur.move(numStepsSouth);
      if (tur.getRow() != numStepsSouth || tur.getCol() != numStepsEast) {
        std::cout << "When direction is Direction::SOUTH, move method of " << numStepsSouth << " steps is wrong." << std::endl;
        break;
      }

      //set tur to the rightmost position of the first row, where row index is 0 and column index is SIZE-1.
      tur.setRow(0);
      tur.setCol(SIZE-1); 

      //move in west direction
      tur.setHeading(Direction::WEST);

      int numStepsWest = 0;
      while (numStepsWest == 0) {
        numStepsWest = rand() % SIZE;
      }
      //Make sure numStepsWest is not zero.

      tur.move(numStepsWest);
      if (tur.getRow() != 0 || tur.getCol() != SIZE -1 -numStepsWest) {
        std::cout << "When direction is Direction::WEST, move method of " << numStepsWest << " steps is wrong." << std::endl;
        break;
      }

      //set tur to the bottom right position in the grid, where row index is SIZE-1 and column index is SIZE-1.
      tur.setRow(SIZE-1);
      tur.setCol(SIZE-1);

      //move in north direction
      tur.setHeading(Direction::NORTH);
      int numStepsNorth = 0;
      while (numStepsNorth == 0) {
        numStepsNorth = rand() % SIZE;
      }
      //Make sure numStepsNorth is not zero.

      tur.move(numStepsNorth);
      if (tur.getRow() != SIZE -1 -numStepsNorth || tur.getCol() != SIZE -1) {
        std::cout << "When direction is Direction::NORTH, move method of " << numStepsNorth << " steps is wrong." << std::endl;
        break;
      }

      std::cout << "move method is correct" << std::endl; 

      break;
    }
//expected output after running ./turtle G:
//move method is correct

    default: 
      std::cout << "Unrecognized option: " << type << std::endl;
  }

  return 0;
}
