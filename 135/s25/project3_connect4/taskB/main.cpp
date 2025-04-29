/*********************************************
Title         :   main.cpp
Author         :   Tong Yi 
Description   :   Autograder Driver for CSCI 135 Spring 2025 Project
*********************************************/

#include <iostream>
#include <vector>
#include "Board.hpp"
//g++ -std=c++11 Board.cpp main.cpp -o test
//test different methods using
//./test 1 or ./test '1'
//./test 2 or ./test '2'
//...
//./test 9 or ./test '9'

int main(int argc, const char *argv[]) {
    if (argc != 2) {
       std::cout << "Need 'A'-'C' in parameters" << std::endl;
       return -1;
    }

    //unit-testing for constructors and the destructor
    char type = *argv[1];
    std::string prompt;
    Board *game;
    int player = -2; //a not-exist value

    if (type == '1') {
       //test player 0 wins in winInHorizontal
       game = new Board; //default constructor
       game->grid[5].push_back(0);
       //game->display();
       game->grid[0].push_back(1);
       //game->display();
       game->grid[4].push_back(0);
       //game->display();
       game->grid[0].push_back(1);
       //game->display();
       game->grid[3].push_back(0);
       //game->display();
       game->grid[0].push_back(1);
       //game->display();
       game->grid[2].push_back(0);
       //game->display();

       player = game->winInHorizontal(2);
       prompt = " in horizontal";

       //game->display();
//Sample output:
//player 0 wins in horizontal
// , , , , , ,
//1, , , , , ,
//1, , , , , ,
//1, ,2,2,2,2,
//+--+--+--+--+--+--+
//|  |  |  |  |  |  |
//+--+--+--+--+--+--+
//|⬟ |  |  |  |  |  |
//+--+--+--+--+--+--+
//|⬟ |  |  |  |  |  |
//+--+--+--+--+--+--+
//|⬟ |  |◉ |◉ |◉ |◉ |
//+--+--+--+--+--+--+
//  0  1  2  3  4  5
    }
    else if (type == '2') {
       //test no one wins in winInHorizontal
       game = new Board; //default constructor
       game->grid[5].push_back(0);
       game->grid[0].push_back(1);
       game->grid[4].push_back(0);
       game->grid[0].push_back(1);
       game->grid[3].push_back(0);
       game->grid[0].push_back(1);

       player = game->winInHorizontal(0);
       prompt = " in horizontal";
       //game->display();
//Sample output:
//no player wins in horizontal
// , , , , , ,
//1, , , , , ,
//1, , , , , ,
//1, , ,0,0,0,
//Visual result
//+--+--+--+--+--+--+
//|  |  |  |  |  |  |
//+--+--+--+--+--+--+
//|⬟ |  |  |  |  |  |
//+--+--+--+--+--+--+
//|⬟ |  |  |  |  |  |
//+--+--+--+--+--+--+
//|⬟ |  |  |⬤ |⬤ |⬤ |
//+--+--+--+--+--+--+
//  0  1  2  3  4  5
    }
    else if (type == '3') {
        //win in vertical
        game = new Board;

        game->grid[0].push_back(0);
        game->grid[1].push_back(1);
        game->grid[0].push_back(0);
        game->grid[1].push_back(1);
        game->grid[0].push_back(0);
        game->grid[1].push_back(1);
        game->grid[3].push_back(0);
        game->grid[1].push_back(1);
        //game->display();

        player = game->winInVertical(1);
        prompt = " in vertical";

//sample output:
//player 1 wins in vertical
// ,3, , , , ,
//0,3, , , , ,
//0,3, , , , ,
//0,3, ,0, , ,
//+--+--+--+--+--+--+
//|  |⭔ |  |  |  |  |
//+--+--+--+--+--+--+
//|⬤ |⭔ |  |  |  |  |
//+--+--+--+--+--+--+
//|⬤ |⭔ |  |  |  |  |
//+--+--+--+--+--+--+
//|⬤ |⭔ |  |⬤ |  |  |
//+--+--+--+--+--+--+
//  0  1  2  3  4  5
    }
    else if (type == '4') {
        //no win in vertical
        game = new Board;

        game->grid[0].push_back(0);
        game->grid[1].push_back(1);
        game->grid[0].push_back(0);
        game->grid[1].push_back(1);
        game->grid[0].push_back(0);
        game->grid[1].push_back(1);
        //game->display();

        player = game->winInVertical(1);
        prompt = " in vertical";
//Sample output:
//+--+--+--+--+--+--+
//|  |  |  |  |  |  |
//+--+--+--+--+--+--+
//|⬤ |⬟ |  |  |  |  |
//+--+--+--+--+--+--+
//|⬤ |⬟ |  |  |  |  |
//+--+--+--+--+--+--+
//|⬤ |⬟ |  |  |  |  |
//+--+--+--+--+--+--+
//  0  1  2  3  4  5
//no player wins in vertical
// , , , , , ,
//0,1, , , , ,
//0,1, , , , ,
//0,1, , , , ,
    }
    else if (type == '5') {
        //win in diagonal
        game = new Board;
        game->grid[0].push_back(0);
        game->grid[1].push_back(1);
        game->grid[1].push_back(0);
        game->grid[2].push_back(1);
        game->grid[3].push_back(0);
        game->grid[2].push_back(1);
        game->grid[2].push_back(0);
        game->grid[3].push_back(1);
        game->grid[3].push_back(0);
        game->grid[4].push_back(1);
        game->grid[3].push_back(0);

        player = game->winInDiagonal(0);
        prompt = " in diagonal";

        //game->display();

//Sample output:
//player 0 wins in diagonal
// , , ,2, , ,
// , ,2,0, , ,
// ,2,1,1, , ,
//2,1,1,0,1, ,
//+--+--+--+--+--+--+
//|  |  |  |◉ |  |  |
//+--+--+--+--+--+--+
//|  |  |◉ |⬤ |  |  |
//+--+--+--+--+--+--+
//|  |◉ |⬟ |⬟ |  |  |
//+--+--+--+--+--+--+
//|◉ |⬟ |⬟ |⬤ |⬟ |  |
//+--+--+--+--+--+--+
//  0  1  2  3  4  5
    }
    else if (type == '6') {
            //win in anti-diagonal
        game = new Board;
        game->grid[0].push_back(0);
        game->grid[1].push_back(1);
        game->grid[2].push_back(0);
        game->grid[3].push_back(1);
        game->grid[0].push_back(0);
        game->grid[2].push_back(1);
        game->grid[0].push_back(0);
        game->grid[0].push_back(1);
        game->grid[1].push_back(0);
        game->grid[1].push_back(1);

        player = game->winInDiagonal(1);
        prompt = " in anti-diagonal";

        //game->display();

//sample output:
//+--+--+--+--+--+--+
//|⭔ |  |  |  |  |  |
//+--+--+--+--+--+--+
//|⬤ |⭔ |  |  |  |  |
//+--+--+--+--+--+--+
//|⬤ |⬤ |⭔ |  |  |  |
//+--+--+--+--+--+--+
//|⬤ |⬟ |⬤ |⭔ |  |  |
//+--+--+--+--+--+--+
//  0  1  2  3  4  5
//player 1 wins in anti-diagonal
//3, , , , , ,
//0,3, , , , ,
//0,0,3, , , ,
//0,1,0,3, , ,
    }
    else if (type == '7') {
        //no win, a tie
        //msg = '0 1  0 2 0  0 3 1 2 1 1 2 3  3 5  3 5 5 4 4 4 5  4  2\n'
        game = new Board;
        game->grid[0].push_back(0);
        game->grid[1].push_back(1);
        game->grid[0].push_back(0);
        game->grid[2].push_back(1);
        game->grid[0].push_back(0);
        game->grid[0].push_back(1);
        game->grid[3].push_back(0);
        game->grid[1].push_back(1);
        game->grid[2].push_back(0);
        game->grid[1].push_back(1);
        game->grid[1].push_back(0);
        game->grid[2].push_back(1);
        game->grid[3].push_back(0);
        game->grid[3].push_back(1);
        game->grid[5].push_back(0);
        game->grid[3].push_back(1);
        game->grid[5].push_back(0);
        game->grid[5].push_back(1);
        game->grid[4].push_back(0);
        game->grid[4].push_back(1);
        game->grid[4].push_back(0);
        game->grid[5].push_back(1);
        game->grid[4].push_back(0);
        game->grid[2].push_back(1);

        player = game->win(1);

        //game->display();
//sample output:
//+--+--+--+--+--+--+
//|⬟ |⬤ |⬟ |⬟ |⬤ |⬟ |
//+--+--+--+--+--+--+
//|⬤ |⬟ |⬟ |⬟ |⬤ |⬟ |
//+--+--+--+--+--+--+
//|⬤ |⬟ |⬤ |⬤ |⬟ |⬤ |
//+--+--+--+--+--+--+
//|⬤ |⬟ |⬟ |⬤ |⬤ |⬤ |
//+--+--+--+--+--+--+
//  0  1  2  3  4  5
//no player wins
//1,0,1,1,0,1,
//0,1,1,1,0,1,
//0,1,0,0,1,0,
//0,1,1,0,0,0,
    }
    else if (type == '8') {
        //msg = '0 1 0 2 1 3 0 4\n'
        game = new Board;
        game->grid[0].push_back(0);
        game->grid[1].push_back(1);
        game->grid[0].push_back(0);
        game->grid[2].push_back(1);
        game->grid[1].push_back(0);
        game->grid[3].push_back(1);
        game->grid[0].push_back(0);
        game->grid[4].push_back(1);

        player = game->win(4); //4 is the most recent bin with balls added

        //game->display();
//sample output:
//+--+--+--+--+--+--+
//|  |  |  |  |  |  |
//+--+--+--+--+--+--+
//|⬤ |  |  |  |  |  |
//+--+--+--+--+--+--+
//|⬤ |⬤ |  |  |  |  |
//+--+--+--+--+--+--+
//|⬤ |⭔ |⭔ |⭔ |⭔ |  |
//+--+--+--+--+--+--+
//  0  1  2  3  4  5
//player 1 wins
// , , , , , ,
//0, , , , , ,
//0,0, , , , ,
//0,3,3,3,3, ,
    }
    else if (type == '9') {
        //msg = '1 0 1 2 1 3 1\n'
        game = new Board;
        game->grid[1].push_back(0);
        game->grid[0].push_back(1);
        game->grid[1].push_back(0);
        game->grid[2].push_back(1);
        game->grid[1].push_back(0);
        game->grid[3].push_back(1);
        game->grid[1].push_back(0);

        player = game->win(1); //1 is the most recent bin with balls added

//        game->display();
//sample output:
//+--+--+--+--+--+--+
//|  |◉ |  |  |  |  |
//+--+--+--+--+--+--+
//|  |◉ |  |  |  |  |
//+--+--+--+--+--+--+
//|  |◉ |  |  |  |  |
//+--+--+--+--+--+--+
//|⬟ |◉ |⬟ |⬟ |  |  |
//+--+--+--+--+--+--+
//  0  1  2  3  4  5
//player 0 wins
// ,2, , , , ,
// ,2, , , , ,
// ,2, , , , ,
//1,2,1,1, , ,
    }

    if (player != -1)
       std::cout << "player " << player << " wins";
    else std::cout << "no player wins";

    std::cout << prompt << std::endl;

    for (int j = game->capacity-1; j>=0; j--) {
           for (int i = 0; i < game->numBins; i++) {
               if (j < game->grid[i].size())
                  std::cout << game->grid[i][j] << ",";
               else std::cout << " ,";
           }
           std::cout << std::endl;
       }

    delete game;
    game = nullptr;

    return 0;
}
