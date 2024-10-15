#ifndef Board_H
#define Board_H

class Board {
public:
    Board(); //3 * 3 board
    Board(int m, int n); //m * n board
    Board(int** arr, int m, int n); //m * n board where data is stored in a 2-dimensional array
    ~Board(); //destructor
    void randomize();
    bool valueCorrect(int row, int col) const;
    void getInfo();
    void display() const;
    void slideUp();
    void slideDown();
    void slideLeft();
    void slideRight();
    void play();

private:
    int** panel;
    int numRows;
    int numCols;
    int emptyCellRow;
    int emptyCellCol;
    int numCorrect; //cell with correct position
};
#endif
