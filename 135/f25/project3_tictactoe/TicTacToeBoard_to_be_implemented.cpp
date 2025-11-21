#include "TicTacToeBoard.hpp"

//Do not forget TicTacToeBoard:: before constructors and methods of TicTacToeBoard class
//TODO: default constructor
TicTacToeBoard::TicTacToeBoard() {

}

//TODO: non-default constructor
TicTacToeBoard::TicTacToeBoard(int givenSize) {

}

//TODO: set each cell of the board to be a space character.
//Warning: our clear method of TicTacToeBoard is different from clear method of a vector.
//(1) clear method of a vector removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
//(2) That is, board.clear() removes all elements of board and make board an empty vector.
//(3) Our clear method does not change the structure of board -- its number of rows and number of columns will still keep the same -- just set each element to be a space.
void TicTacToeBoard::clear() {

}

//TODO: get the value of the cell at (row, col)
char TicTacToeBoard::getValue(int row, int col) const {
    return ' '; //TODO: placeholder
}

//TODO: Checks if the cell at (row, col) is available.
//A cell is available if the following conditions satisify.
//(1) row and col indices are valid 
//(2) the value at that cell is a space character (' ').
//Otherwise, the cell is not available.
bool TicTacToeBoard::isAvailable(int row, int col) const {
    return false; //TODO: placeholder
}

//Check whether the given parameter row is valid row index or not.
//that is, whether row is in [0, board.size()-1]
bool TicTacToeBoard::isValidRow(int row) const {
    return false; //TODO: placeholder
}

//Check whether the given parameter col is a valid column index or not
//that is, whether col is in [0, board[0].size()-1]
bool TicTacToeBoard::isValidCol(int col) const {
    return false; //TODO: placeholder
}

//Finish first!!
//Return the size of tic tac toe board
int TicTacToeBoard::size() const {
    return 3; //TODO: placeholder
}

//TODO: if row and col are valid indices, 
//place symbol at board[row][col].
//Note that before we can use board[row][col],
//need to make sure that row and col indices are valid.
void TicTacToeBoard::mark(int row, int col, char symbol) {
    
}

//Return a string representation of the contents of board.
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
