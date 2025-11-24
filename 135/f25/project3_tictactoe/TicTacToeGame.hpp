#ifndef TicTacToeGame_H
#define TicTacToeGame_H
#include "TicTacToeBoard.hpp"
class TicTacToeGame {
public:
    TicTacToeGame();
	TicTacToeGame(int size);

    //Play a game. 
    //Once it finishes, ask the user whether they want to play again,
    //"Do you want to continue (yes/no): ",
    //Continue the game as long as the user enters "yes" or 'y'.
    //Reset each cell of the board to be a space character
    //by calling clear method of TicTacToeBoard.
    void runRepeat();

    //(1) Print the empty board.
    //(2) The human plays first, followed by the computer.
    //(3) Start round by 1.
    //(4) In each round, a player selects a cell.
    //(5) Continue until the game ends.
	void start(); //start to play the game

    //Return true if the game has ended -- either by a win or a tie.
    //If the human wins, print "Human wins. Yay!!!".
    //If the computer wins, print "Computer wins. Yuck.".
    //If the game ends in a tie, print "It is a tie.".
	bool isGameOver() const;
	
	//This is how the user plays:
	//Enter row and col such that
	//1. row is in [0, size-1]
	//2. col is in [0, size-1]
	//3. the corresponding cell in tttBoard is available
   	//   (hint: call isAvailable method of tttBoard).
	//As long as the input row or col is not valid or is not available
	
    //begin
	//   prompt what error(s) are, for example,
	//   (1) row is not in [0, size-1] or
	//   (2) col is not in [0, size-1] or
	//   (3) the corresponding cell in tttBoard is not available 
	//   prompt user to re-enter.
	//end
	//
	//Once we exit the above repetition loop,
	//row and col are valid,
	//mark the corresponding cell in tttBoard by HUMAN_ID.
	void humanPlay();
	
 	//computer play
	//Computer checks tttBoard from the first row to the last row. 
	//In each row, the computer checks from the first column to the last column.
	//A more sophisticated approach is to use "mark first; if unfit, then remove mark"
	//1. Try to win first.
	//   Mark an available cell by computerId, 
	//   if this leads to win by computer,
	//   take this cell and return, 
	//   otherwise, do not take this cell (that is, set this cell to be available).
	//2. Try to block the opponent from winning. 
	//   This approach is adopted after the try-to-win approach fails.
	//   Mark an available cell by userId (that is, suppose this cell is taken by userId),
	//   if this leads to win by user,
	//   mark this cell by computerId, and return.
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
