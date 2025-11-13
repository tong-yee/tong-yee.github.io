#ifndef TicTacToeBoard_H
#define TicTacToeBoard_H
#include <iostream> //std
#include <vector>

class TicTacToeBoard {
public:
    //a default 3x3 TicTacToe board 
    TicTacToeBoard();
  
    //If the provided size is less than 3, default to creating a 3x3 board.
    //Otherwise, initialize the board with the given size for both rows and columns.
    TicTacToeBoard(int givenSize);
  
    //Set each element of the board to be a space (' ').
    void clear();
  
    //Return the value at cell (row, col)
    char getValue(int row, int col) const;
      
    // Checks if the cell at (row, col) is available.
    //A cell is available if its value is a space character (' ').
    bool isAvailable(int row, int col) const;
  
    //Check whether the given parameter row is valid row index or not.
    //that is, whether row is in [0, board.size()-1]
    bool isValidRow(int row) const;
  
    //Check whether the given parameter col is a valid column index or not
    //that is, whether col is in [0, board.size()-1]
    bool isValidCol(int col) const;
  
    //Return the size of tic tac toe board  
    int size() const; 
  
    //Place playerId at board[row][col].
    void mark(int row, int col, char playerId);
   
    //Returns a string that visually represents the current layout of the board's elements.
    std::string to_string() const;
  
    //If every single row, column, main diagonal, AND anti-diagonal 
    //each contain both 'X' and 'O' symbols,
    //then the board is in a tie state (return true).
    //Otherwise, if any of those lines (row/col/diagonals) is missing 
    //an 'X' or an 'O', it means a win is still possible (return false).
    bool tie() const;
  
    //Check whether the player at row and col wins. 
    //If there is any win in horizonal, vertical, 
    //diagonal, or anti-diagonal direction, return true,
    //otherwise, return false.
    bool win(int row, int col) const;
   
    //Check Horizontal Win: 
    //Evaluate the row containing the cell (row, col). 
    //If the current player's symbol forms a continuous, 
    //unbroken sequence of the required length within this row, 
    //the function returns true (win found); otherwise, it returns false.
    //Check whether the player at (row, col) can win that row or not.
    bool winByRow(int row, int col) const;
    //Check Vertical Win: 
    //Evaluate the column containing the cell (row, col). 
    //If the current player's symbol forms a continuous, 
    //unbroken sequence of the required length within this column, 
    //the function returns true (win found); otherwise, it returns false.
    bool winByCol(int row, int col) const;
  	//Check Digonal (including both diagonal and anti-diagonal) Win: 
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
    bool winByDiagonal(int row, int col) const;

private:
    std::vector<std::vector<char>> board; //board is a 2d array of chars
};
#endif
