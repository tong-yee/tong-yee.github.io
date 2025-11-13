#include <iostream>
#include <vector>
#include "TicTacToeBoard.hpp"
//g++ -o tBoard TicTacToeBoard.cpp tttBoard_main.cpp
//test default constructor using
//./tBoard A

const int NUM_COLUMNS = 4;
TicTacToeBoard* assignData(char data[][NUM_COLUMNS]);

int main(int argc, const char *argv[]) {
    if (argc != 2) {
       std::cout << "Need 'A'-'J' in command line parameter" << std::endl;
       return -1;
    }

    //unit-testing for constructors and the destructor
    char type = *argv[1];
    std::string prompt;
    TicTacToeBoard *tttBoard;
   
    if (type == 'A') {
       prompt = "default constructor TicTacToeBoard board;";
       tttBoard = new TicTacToeBoard;

//Sample output:
//Call default constructor TicTacToeBoard board;
//contents of board is
// , , ,
// , , ,
// , , ,
//
    }
    else if (type == 'B') {
        std::cout << "Enter size of the board: ";
        int size;
        std::cin >> size;
        prompt = "non-default constructor TicTacToeBoard board(" + std::to_string(size) + ");";
        tttBoard = new TicTacToeBoard(size);

//Sample input/output:
//Enter size of the board: 5
//Call non-default constructor TicTacToeBoard board(5);
//contents of board is
// , , , , ,
// , , , , ,
// , , , , ,
// , , , , ,
// , , , , ,
//

//do not take the parameter as it is,
//need to make sure that parameter size is >= 3
//another sample input/output:
//Enter size of the board: 2
//Call non-default constructor TicTacToeBoard board(2);
//contents of board is
// , , ,
// , , ,
// , , ,
//
    }
    else if (type == 'C' || type == 'D') {
        //test clear method,
        char data[][NUM_COLUMNS] = {
           {'X', 'O', 'X', ' '},
           {'O', 'X', ' ', ' '},
           {' ', 'O', 'O', ' '},
           {'X', ' ', ' ', 'X'},
        };
        
        tttBoard = assignData(data);

        if (type == 'C') {
           tttBoard->clear();
   
           //after calling clearing method, each element of board should be ' '
           bool isWrong = false;
           for (int row = 0; row < tttBoard->size() && !isWrong; row++) {
               for (int col = 0; col < tttBoard->size() && !isWrong; col++) {
                   if (tttBoard->getValue(row, col) != ' ') {
                      std::cout << "clear method is not correct. Each element should be a space character\n";
                      isWrong = true; //set a tag
                      //break; //break only can break the inner loop, the outer loop still runs
                   }
               }
           }

           if (!isWrong) {
              std::cout << "clear method is correct\n";
           }
        //expected output:
        //clear method is correct
        }
        else if (type == 'D') {
        //test to_string method
                std::cout << tttBoard->to_string();
        //expected output:
//     0   1   2   3  
//   +---+---+---+---+
// 0 | X | O | X |   |
//   +---+---+---+---+
// 1 | O | X |   |   |
//   +---+---+---+---+
// 2 |   | O | O |   |
//   +---+---+---+---+
// 3 | X |   |   | X |
//   +---+---+---+---+
        }
    }
    else if (type == 'E') {
        //test winByRow(int row, int col)
        char data[][NUM_COLUMNS] = {
           {'X', 'O', 'X', ' '},
           {'X', 'O', 'O', ' '},
           {'O', 'O', 'O', 'O'},
           {'X', 'X', 'X', ' '},
        };
        
        tttBoard = assignData(data);

        bool result;
        for (int row = 0; row < tttBoard->size(); row++) {
            for (int col = 0; col < tttBoard->size(); col++) {
                result = tttBoard->winByRow(row, col);
                if (result) { //result == true
                   std::cout << std::boolalpha << result;
                }
                std::cout << ',';
                //std::cout << std::boolalpha << tttBoard->winByRow(row, col) << ',';
            }
            std::cout << std::endl;
        }
//expected output:
//,,,,
//,,,,
//true,true,true,true,
//,,,,
    }
    else if (type == 'F') {
        //test winByCol(int row, int col)
        char data[][NUM_COLUMNS] = {
           {'O', 'X', 'O', ' '},
           {'O', 'X', 'X', 'O'},
           {'O', 'X', 'O', ' '},
           {'X', 'X', ' ', 'X'},
        };
        
        tttBoard = assignData(data);

        bool result;
        for (int row = 0; row < tttBoard->size(); row++) {
            for (int col = 0; col < tttBoard->size(); col++) {
                result = tttBoard->winByCol(row, col);
                if (result) { //result == true
                   std::cout << std::boolalpha << result;
                }
                std::cout << ',';

                //std::cout << std::boolalpha << tttBoard->winByCol(row, col) << ',';
            }
            std::cout << std::endl;
        }
//expected output:
//,true,,,
//,true,,,
//,true,,,
//,true,,,
    }
    else if (type == 'G') {
        //test winByDiagonal(int row, int col)
        char data[][NUM_COLUMNS] = {
           {'X', 'X', 'O', ' '},
           {'O', 'X', 'O', 'O'},
           {'X', 'O', 'X', ' '},
           {'O', 'X', ' ', 'X'},
        };
        
        tttBoard = assignData(data);

        bool result;
        for (int row = 0; row < tttBoard->size(); row++) {
            for (int col = 0; col < tttBoard->size(); col++) {
                result = tttBoard->winByDiagonal(row, col);
                if (result) { //result == true
                   std::cout << std::boolalpha << result;
                }
                std::cout << ',';

                //std::cout << std::boolalpha << tttBoard->winByDiagonal(row, col) << ',';
            }
            std::cout << std::endl;
        }
//expected output:
//true,,,,
//,true,,,
//,,true,,
//,,,true,
    }
    else if (type == 'H') {
        //test winByDiagonal(int row, int col)
        char data[][NUM_COLUMNS] = {
           {'X', 'X', 'O', 'O'},
           {'O', 'X', 'O', 'O'},
           {'X', 'O', ' ', 'X'},
           {'O', 'X', ' ', 'X'},
        };
        
        tttBoard = assignData(data);

        bool result;
        for (int row = 0; row < tttBoard->size(); row++) {
            for (int col = 0; col < tttBoard->size(); col++) {
                result = tttBoard->winByDiagonal(row, col);
                if (result) { //result == true
                   std::cout << std::boolalpha << result;
                }
                std::cout << ',';
            }
            std::cout << std::endl;
        }
//expected output:
//,,,true,
//,,true,,
//,true,,,
//true,,,,
    }
    else if (type == 'I') {
        //test tie()
        char data[][NUM_COLUMNS] = {
           {'X', 'X', 'O', ' '},
           {'O', 'X', 'O', 'O'},
           {'X', 'O', 'X', ' '},
           {'O', 'X', ' ', 'X'},
        };
        
        tttBoard = assignData(data);

        std::cout << std::boolalpha << tttBoard->tie() << '\n';

//expected output:
//false
    }
    else if (type == 'J') {
        //test tie()
        char data[][NUM_COLUMNS] = {
           {'X', 'X', 'O', ' '},
           {'O', 'X', 'X', 'O'},
           {'X', 'O', 'O', ' '},
           {'O', 'X', ' ', 'X'},
        };
        
        tttBoard = assignData(data);

        std::cout << std::boolalpha << tttBoard->tie() << '\n';

//expected output:
//true
    }

    //'A' for default constructor and
    //'B' for non-default constructor
    if (type == 'A' || type == 'B') {
       std::cout << "Call " << prompt << '\n';
       std::cout << "contents of board is\n";
       for (int row = 0; row < tttBoard->size(); row++) {
           for (int col = 0; col < tttBoard->size(); col++) {
               std::cout << tttBoard->getValue(row, col) << ',';
           }
           std::cout << '\n';
       }
    }

    delete tttBoard; //release dynamic allocated memory
    tttBoard = nullptr; //handle dangling pointer problem 

    return 0;
}

TicTacToeBoard* assignData(char data[][NUM_COLUMNS]) {
   TicTacToeBoard *tttBoard = new TicTacToeBoard(NUM_COLUMNS);
   
   for (int row = 0; row < tttBoard->size(); row++) {
       for (int col = 0; col < tttBoard->size(); col++) {
           tttBoard->mark(row, col, data[row][col]); //set board[row][col] of *tttBoard -- a TicTacToeBoard object -- to be data[row][col]
       }
   }

   return tttBoard;
}
