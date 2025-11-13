#ifndef TicTacToeGame_H
#define TicTacToeGame_H
#include "TicTacToeBoard.hpp"
class TicTacToeGame {
public:
    TicTacToeGame();
	TicTacToeGame(int size);
    void runRepeat();
   	//start to play the game
	void start();
	bool isGameOver() const;
	
	//This is how the user plays:
	//Enter row and col such that
	//1. row is in [0, size-1]
	//2. col is in [0, size-1]
	//3. the corresponding cell in the board is available
	//   (hint: call board.getValue(row, col) to check the return is 0 or not).
	//As long as the input row or col is not valid
	//begin
	//   prompt what error(s) are, for example,
	//   * row is not in [0, size-1]
	//   * col is not in [0, size-1]
	//   * the corresponding cell in board is not available 
	//   prompt user to re-enter.
	//end
	//
	//Once we exit the above repetition loop,
	//row and col are valid,
	//mark the corresponding cell in the board by HUMAN_ID.
	void humanPlay();
	
 	//computer play
	//Computer checks the board from the first row to the last row. 
	//In each row, the computer checks from the first column to the last column.
	//A more sophisticated approach is to use "mark first; if unfit, then remove mark"
	//1. Try to win first.
	//   Mark an available cell by computerId, 
	//   if this leads to win by computer,
	//  take this cell and return, 
	//   otherwise, do not take this cell (that is, set this cell to be available).
	//2. Try to block the opponent from winning. 
	//   This approach is adopted after the try-to-win approach fails.
	//   Mark an available cell by userId (that is, suppose this cell is taken by userId),
	//   if this leads to win by user,
	//  mark this cell by computerId, and return.
	//   otherwise, do not take this cell (that is, set this cell to be available).
	//3. If neither one of the above two approaches works 
	//   (that is, the computer does not take a cell yet), 
	//   then mark the first available cell.
	void computerPlay();

private:
    TicTacToeBoard tttBoard;
	int currRow;
    int currCol; //the row and col the current player chooses.
	static const char HUMAN_ID = 'X';
	static const char COMPUTER_ID = 'O';
	
};
#endif
