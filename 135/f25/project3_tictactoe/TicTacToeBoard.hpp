#ifndef TicTacToeBoard_H
#define TicTacToeBoard_H
#include <iostream> //std
#include <vector>

class TicTacToeBoard {
public:
    //default constructor creates a 3x3 board 
    TicTacToeBoard();
  
    //If givenSize is less than 3, create a 3x3 board.
    //Otherwise, initialize the board with the given size for both rows and columns.
    TicTacToeBoard(int givenSize);
  
    //Set each cell of the board to be a space character.
    //Warning: our clear method of TicTacToeBoard is different from clear method of a vector.
    //(1) clear method of a vector removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
    //(2) That is, board.clear() removes all elements of board and make board an empty vector.
    //(3) Our clear method does not change the structure of board -- its number of rows and number of columns will still keep the same -- just set each element to be a space.
    void clear();
  
    //if row and col are valid indices,
    //return the value of the cell of the board at (row, col)
    //otherwise, return 'W' (means wrong)
    //Warning: a function with non-void return type
    //needs to return a value of that return type in every execution path.
    char getValue(int row, int col) const;
      
    //Checks if the cell at (row, col) is available or not.
    //A cell is available if the following conditions satisify.
    //(1) row and col indices are valid
    //(2) the value at that cell is a space character (' ').
    //Otherwise, the cell is not available.
    bool isAvailable(int row, int col) const;
  
    //Check whether the given parameter row is valid row index or not.
    //that is, whether row is in [0, board.size()-1]
    bool isValidRow(int row) const;
  
    //Check whether the given parameter col is a valid column index or not
    //that is, whether col is in [0, board[0].size()-1]
    bool isValidCol(int col) const;
 
    //Return the number of rows of board  
    int size() const; 
  
    //IF row and col are valid indices, 
    //place symbol at board[row][col],
    //otherwise, do nothing.
    //Note that before we can use board[row][col],
    //need to make sure that row and col indices are valid.
    void mark(int row, int col, char symbol);
   
    //Return a string representation of the contents of board.
    //(1) The returned string typically formats the board in a grid layout
    //for easy display and debugging.
    //(2) 'X', 'O', and ' ' characters in the string are
    //    separated by ONLY ONE vertical bar pipe character '|'.
    //    For example, one row with values 'X', ' ', and 'O' looks like
    //    | X |  | O |
    std::string to_string() const;
  
    //If every single row, column, main diagonal, AND anti-diagonal
    //each contain both 'X' and 'O' symbols,
    //then the board is in a tie state (return true).
    //Otherwise, if any of those lines (row/col/main diagonal/anti-digonal)
    //is missing an 'X' or an 'O', a win is still possible (return false for tie status).
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
}; //do not forget ;
#endif
