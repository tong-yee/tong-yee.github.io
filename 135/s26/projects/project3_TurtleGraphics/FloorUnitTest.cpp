#include <iostream>
#include <vector>
#include <cstdlib> //srand
#include <ctime> //time
#include <sstream> //std::ostringstream
#include "Floor.hpp"
//g++ -o floor Floor.cpp FloorUnitTest.cpp
//test default constructor using
//./floor A

const int SIZE = 16;
Floor assignData(char data[][SIZE]);
void printCanvas(const Floor& canvas, const std::string& prompt);

int main(int argc, const char *argv[]) {
    if (argc != 2) {
       std::cout << "Need 'A'-'G' in command line parameter" << std::endl;
       return -1;
    }

    //unit-testing for constructors and methods of Floor class 
    char type = *argv[1];
    std::string prompt;

    //IMPORTANT: If your output is inconsistent, temporarily replace srand(time(NULL)) with srand(0).
    srand(time(NULL));

    //'A' for default constructor and
    //'B' for non-default constructor
    if (type == 'A' || type == 'B') {
      if (type == 'A') {
        prompt = "Call default constructor Floor canvas;";
        Floor canvas;
        printCanvas(canvas, prompt);
//Sample output:
//Call default constructor Floor canvas;
//num of rows: 20
//num of cols: 20
//contents of canvas is
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,

      }
      else if (type == 'B') {
             std::cout << "Enter size of the canvas (needs to be at least 10, otherwise, convert it to 20): ";
             int size;
             std::cin >> size;
             prompt = "Call non-default constructor Floor canvas(" + std::to_string(size) + ");";
             Floor canvas(size);
             printCanvas(canvas, prompt);

//Enter size of the canvas (needs to be at least 10, otherwise, convert it to 20): 11
//Call non-default constructor Floor canvas(11);
//num of rows: 11
//num of cols: 11
//contents of canvas is
// , , , , , , , , , , ,
// , , , , , , , , , , ,
// , , , , , , , , , , ,
// , , , , , , , , , , ,
// , , , , , , , , , , ,
// , , , , , , , , , , ,
// , , , , , , , , , , ,
// , , , , , , , , , , ,
// , , , , , , , , , , ,
// , , , , , , , , , , ,
// , , , , , , , , , , ,
//

//do not take the parameter as it is,
//need to make sure that parameter size is >= 10
//Sample input/output:
//Enter size of the canvas (needs to be at least 10, otherwise, convert it to 20): 5
//Call non-default constructor Floor canvas(5);
//num of rows: 20
//num of cols: 20
//contents of canvas is
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
// , , , , , , , , , , , , , , , , , , , ,
//
      }
    }
    else if (type >= 'C' && type <= 'E') {
        char data[SIZE][SIZE];
        
        //set some random values for data
        char chosenValues[] = {'*', ' '};
        int numChosenValues = sizeof(chosenValues) / sizeof(chosenValues[0]);
        for (int row = 0; row < SIZE; row++) {
          for (int col = 0; col < SIZE; col++) {
            data[row][col] = chosenValues[rand() % numChosenValues]; 
          }
        }
        Floor canvas = assignData(data);

        if (type == 'C') {
           //test clear method,
           canvas.clear();
   
           //after calling clearing method, each element of board should be ' '
           bool isWrong = false;
           for (int row = 0; row < canvas.getNumRows() && !isWrong; row++) {
             for (int col = 0; col < canvas.getNumCols() && !isWrong; col++) {
               if (canvas.at(row, col) != ' ') {
                 std::cout << "clear method is not correct. Each element should be a space character\n";
                 isWrong = true; //set a tag
                 //break; //break only can break the inner loop, the outer loop still runs
               }
             }
           }

           if (!isWrong) {
             std::cout << "clear method is correct\n";
           }
           else {
             std::cout << "clear method is not correct\n";
           }
        //expected output:
        //clear method is correct
        }
        else if (type == 'D') {
           //test at method
           bool isWrong = false;
           for (int row = 0; row < canvas.getNumRows() && !isWrong; row++) {
               for (int col = 0; col < canvas.getNumCols() && !isWrong; col++) {
                   if (canvas.at(row, col) != data[row][col]) {
                      std::cout << "at method is not correct. The expected value is '" << data[row][col] << "'" 
                         << ", however, the actual value is '" << canvas.at(row, col) << "'\n";
                      isWrong = true; //set a tag
                      //break; //break only can break the inner loop, the outer loop still runs
                   }
               }
           }

           if (!isWrong) {
              std::cout << "at method is correct\n";
           }
           else {
             std::cout << "at method is not correct\n";
           }
        }
        else if (type == 'E') {
               //canvas.print(); //debug purpose

               // build expected output manually from data[][]
               std::ostringstream expected;
             
               // print actual via stream
               std::string actual = canvas.to_string();
             
               // build expected string from data[][]
               expected << "  ";
               for (int col = 0; col < SIZE; col++) {
                 if (col % 10 == 0 && col / 10 >= 1) {
                   expected << col / 10;
                 }
                 else {
                   expected << ' ';
                 }
               }
               expected << '\n';
             
               expected << "  ";
               for (int col = 0; col < SIZE; col++) {
                 expected << col % 10;
               }
               expected << '\n';
             
               for (int row = 0; row < SIZE; row++) {
                 expected << (row % 10 == 0 && row / 10 >= 1 ? char('0' + row / 10) : ' ');
                 expected << row % 10;
                 for (int col = 0; col < SIZE; col++) {
                   expected << data[row][col];
                 }
                 expected << '\n';
               }
            
               //std::cout << "'" << actual << "'\n\n";
               //std::cout << "'" << expected.str() << "'\n";
               if (actual == expected.str()) {
                 std::cout << "to_string method is correct\n";
               }
               else {
                 std::cout << "to_string method is not correct\n";
               }
         //expected output:
         //to_string method is correct
        }
    }
    else if (type == 'F') {
      //test mark method of Floor class
      Floor canvas(SIZE);
      canvas.mark(0, 0, '*');           // top-left corner
      canvas.mark(SIZE-1, SIZE-1, '*');           // bottom-right corner, minimum size is 10
      bool cornersCorrect = canvas.at(0,0) == '*' && canvas.at(SIZE-1, SIZE-1) == '*';

      canvas.mark(-1, 0, '*');       // out of bounds, should do nothing
      canvas.mark(0, SIZE, '*');     // out of bounds, should do nothing
      canvas.mark(SIZE, 0, '*');     // out of bounds, should do nothing 
      canvas.mark(SIZE, SIZE, '*');  // out of bounds, should do nothing

      // at() should return '\0' for invalid indices 
      bool outOfBoundsCorrect = canvas.at(-1,0) == '\0' && 
        canvas.at(0,SIZE) == '\0' && canvas.at(SIZE,0) == '\0' &&  canvas.at(SIZE,SIZE) == '\0';

      int row = SIZE / 2;
      int col = SIZE / 2;
      canvas.mark(SIZE/2, SIZE/2, '*');  // out of bounds, should do nothing
      bool centerCorrect = canvas.at(row, col) == '*';

      row = rand() % SIZE;
      col = rand() % SIZE;
      canvas.mark(row, col, '*'); // ok even if (row,col) overlaps (0,0) or (SIZE-1, SIZE-1) since they are already '*'


      bool randomCorrect = canvas.at(row, col) == '*';
      if (cornersCorrect && outOfBoundsCorrect && centerCorrect && randomCorrect) {
        std::cout << "mark method is correct\n";
      }
      else {
        std::cout << "mark method is not correct\n";
      }

//sample output:
//mark method is correct
    }
    else {
      std::cout << "Unrecognized option: " << type << std::endl;
      return -1;
    }

    return 0;
}

Floor assignData(char data[][SIZE]) {
   Floor canvas(SIZE);
   
   for (int row = 0; row < canvas.getNumRows(); row++) {
       for (int col = 0; col < canvas.getNumCols(); col++) {
           canvas.mark(row, col, data[row][col]); //set board[row][col] of *canvasPtr -- a Floor object -- to be data[row][col]
       }
   }

   return canvas;
}

void printCanvas(const Floor& canvas, const std::string& prompt) {
   std::cout << prompt << '\n';
   std::cout << "num of rows: " << canvas.getNumRows() << '\n';
   std::cout << "num of cols: " << canvas.getNumCols() << '\n';
   std::cout << "contents of canvas is\n";
   for (int row = 0; row < canvas.getNumRows(); row++) {
       for (int col = 0; col < canvas.getNumCols(); col++) {
           std::cout << canvas.at(row, col) << ',';
       }
       std::cout << '\n';
   }
}
