#include "TicTacToeBoard.hpp"

//Do not forget TicTacToeBoard:: before constructors and methods of TicTacToeBoard class
//TODO: default constructor creates a 3x3 board 
TicTacToeBoard::TicTacToeBoard() {

}

//TODO: If givenSize is less than 3, create a 3x3 board.
//Otherwise, initialize the board with the given size for both rows and columns.
TicTacToeBoard::TicTacToeBoard(int givenSize) {

}

//TODO: set each cell of the board to be a space character.
//Warning: our clear method of TicTacToeBoard is different from clear method of a vector.
//(1) clear method of a vector removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
//(2) That is, board.clear() removes all elements of board and make board an empty vector.
//(3) Our clear method does not change the structure of board -- its number of rows and number of columns will still keep the same -- just set each element to be a space.
void TicTacToeBoard::clear() {

}

//TODO: if row and col are valid indices,
//return the value of the cell of the board at (row, col)
//otherwise, return 'W' (means wrong)
//Warning: a function with non-void return type
//needs to return a value of that return type in every execution path.
char TicTacToeBoard::getValue(int row, int col) const {
    return ' '; //TODO: placeholder
}

//TODO: Checks if the cell at (row, col) is available or not.
//A cell is available if the following conditions satisify.
//(1) row and col indices are valid 
//(2) the value at that cell is a space character (' ').
//Otherwise, the cell is not available.
bool TicTacToeBoard::isAvailable(int row, int col) const {
    return false; //TODO: placeholder
}

//TODO: Check whether the given parameter row is valid row index or not.
//that is, whether row is in [0, board.size()-1]
bool TicTacToeBoard::isValidRow(int row) const {
    return false; //TODO: placeholder
}

//TODO: Check whether the given parameter col is a valid column index or not
//that is, whether col is in [0, board[0].size()-1]
bool TicTacToeBoard::isValidCol(int col) const {
    return false; //TODO: placeholder
}

//Finish first!!
//TODO: Return the number of rows of board  
int TicTacToeBoard::size() const {
    return 3; //TODO: placeholder, we may have 4x4, 5x5, ... board
}

//TODO: IF row and col are valid indices, 
//place symbol at board[row][col],
//otherwise, do nothing.
//Note that before we can use board[row][col],
//need to make sure that row and col indices are valid.
void TicTacToeBoard::mark(int row, int col, char symbol) {
    
}

//TODO: Return a string representation of the contents of board.
//(1) The returned string typically formats the board in a grid layout
//for easy display and debugging.
//(2) 'X', 'O', and ' ' characters in the string are
//    separated by ONLY ONE vertical bar pipe character '|'.
//    For example, one row with values 'X', ' ', and 'O' looks like
//    | X |  | O |
std::string TicTacToeBoard::to_string() const {
   return ""; //TODO: placeholder
}

//TODO: If every single row, column, main diagonal, AND anti-diagonal 
//each contain both 'X' and 'O' symbols,
//then the board is in a tie state (return true).
//Otherwise, if any of those lines (row/col/main diagonal/anti-digonal)
//is missing an 'X' or an 'O', a win is still possible (return false for tie status).
bool TicTacToeBoard::tie() const {
    return false; //TODO: placeholder
}

//TODO: Check whether the player at row and col wins.
//If there is any win in horizonal, vertical,
//diagonal, or anti-diagonal direction, return true,
//otherwise, return false.
bool TicTacToeBoard::win(int row, int col) const {
    return false; //TODO: placeholder
}

//TODO: Check Horizontal Win: 
//Evaluate the row containing the cell (row, col). 
//If the current player's symbol forms a continuous, 
//unbroken sequence of the required length within this row, 
//the function returns true (win found); otherwise, it returns false.
//Check whether the player at (row, col) can win that row or not.
bool TicTacToeBoard::winByRow(int row, int col) const {
    return false; //TODO: placeholder
}

//TODO: Check Vertical Win: 
//Evaluate the column containing the cell (row, col). 
//If the current player's symbol forms a continuous, 
//unbroken sequence of the required length within this column, 
//the function returns true (win found); otherwise, it returns false.
bool TicTacToeBoard::winByCol(int row, int col) const {
   return false; //TODO: placeholder
}

//TODO: Check Digonal (including both diagonal and anti-diagonal) Win: 
//If the cell (row, col) is not in diagonal or anti-diagonal, return false.
//If the cell (row, col) is in the diagonal,
//evaluate the diagonal containing the cell (row, col). 
//If the current player's symbol forms a continuous, 
//unbroken sequence of the required length within this diagonal, 
//the function returns true (win found); 
//otherwise, evaluate the anti-diagonal containing the cell (row, col). 
//If the current player's symbol forms a continuous, 
//unbroken sequence of the required length within this anti-diagonal, 
//the function returns true (win found); otherwise, return false. 
bool TicTacToeBoard::winByDiagonal(int row, int col) const {
   return false; //TODO: placeholder
}
