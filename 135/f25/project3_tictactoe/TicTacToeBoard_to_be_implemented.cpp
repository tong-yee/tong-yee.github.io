#include "TicTacToeBoard.hpp"

//Do not forget TicTacToeBoard:: before constructors and methods of TicTacToeBoard class
//TODO: default constructor
TicTacToeBoard::TicTacToeBoard() {

}

//TODO: non-default constructor
TicTacToeBoard::TicTacToeBoard(int givenSize) {

}

//TODO
void TicTacToeBoard::clear() {

}

//TODO: get the value of the cell at (row, col)
char TicTacToeBoard::getValue(int row, int col) const {
    return ' '; //TODO: placeholder
}

//TODO: Checks if the cell at (row, col) is available.
//A cell is available if its value is a space character (' ').
bool TicTacToeBoard::isAvailable(int row, int col) const {
    return false; //TODO: placeholder
}

//Check whether the given parameter row is valid row index or not.
//that is, whether row is in [0, board.size()-1]
bool TicTacToeBoard::isValidRow(int row) const {
    return false; //TODO: placeholder
}

//Check whether the given parameter col is a valid column index or not
//that is, whether col is in [0, board.size()-1]
bool TicTacToeBoard::isValidCol(int col) const {
    return false; //TODO: placeholder
}

//Finish first!!
//Return the size of tic tac toe board
int TicTacToeBoard::size() const {
    return 3; //TODO: placeholder
}

//TODO: Place playerId at board[row][col].
void TicTacToeBoard::mark(int row, int col, char playerId) {
    
}

std::string TicTacToeBoard::to_string() const {
   return ""; //TODO: placeholder
}

bool TicTacToeBoard::tie() const {
    return false; //TODO: placeholder
}

bool TicTacToeBoard::win(int row, int col) const {
    return false; //TODO: placeholder
}

bool TicTacToeBoard::winByRow(int row, int col) const {
    return false; //TODO: placeholder
}

bool TicTacToeBoard::winByCol(int row, int col) const {
   return false; //TODO: placeholder
}

bool TicTacToeBoard::winByDiagonal(int row, int col) const {
   return false; //TODO: placeholder
}
