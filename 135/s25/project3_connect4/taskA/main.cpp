/****************************************************************************************************************************
Title         :   main.cpp
Auhor         :   Tong Yi 
Description   :   Autograder Driver for CSCI 135 Spring 2025 Project
****************************************************************************************************************************/

#include <iostream>
#include <vector>
#include "Board.hpp"
//g++ -std=c++11 Board.cpp main.cpp
//test default constructor using
//./a.out A or ./a.out 'A'
//./a.out B or ./a.out 'B'

int main(int argc, const char *argv[]) {
    if (argc != 2) {
       std::cout << "Need 'A'-'C' in parameters" << std::endl;
       return -1;
    }

    //unit-testing for constructors and the destructor
    char type = *argv[1];
    std::string prompt;
    Board *game;
    int** arr;
   
    if (type == 'A') {
       prompt = "default constructor,";
       game = new Board;

//Sample output:
//After default constructor, data member numBins is 6
//After default constructor, data member capacity is 4
//number of elements of bin 0 is: 0
//number of elements of bin 1 is: 0
//number of elements of bin 2 is: 0
//number of elements of bin 3 is: 0
//number of elements of bin 4 is: 0
//number of elements of bin 5 is: 0
    }
    else if (type == 'B') {
        prompt = "Board game(7, 5);";
        game = new Board(7, 5);

//Sample output:
//After Board game(7, 5); data member numBins is 7
//After Board game(7, 5); data member capacity is 5
//number of elements of bin 0 is: 0
//number of elements of bin 1 is: 0
//number of elements of bin 2 is: 0
//number of elements of bin 3 is: 0
//number of elements of bin 4 is: 0
//number of elements of bin 5 is: 0
//number of elements of bin 6 is: 0
    }
    else if (type == 'C') {
        prompt = "Board game(5, 1);";
        game = new Board(5, 1);

//sample output:
//After Board game(5, 1); data member numBins is 5
//After Board game(5, 1); data member capacity is 4
//number of elements of bin 0 is: 0
//number of elements of bin 1 is: 0
//number of elements of bin 2 is: 0
//number of elements of bin 3 is: 0
//number of elements of bin 4 is: 0
    }
    else if (type == 'D') {
        game = new Board;

        game->grid[0].push_back(0);
        game->grid[0].push_back(1);
        game->grid[1].push_back(0);
        game->grid[1].push_back(1);
        game->grid[2].push_back(0);
        game->grid[3].push_back(1);
        game->display();

//sample output:
//+--+--+--+--+--+--+
//|  |  |  |  |  |  |
//+--+--+--+--+--+--+
//|  |  |  |  |  |  |
//+--+--+--+--+--+--+
//|⬟ |⬟ |  |  |  |  |
//+--+--+--+--+--+--+
//|⬤ |⬤ |⬤ |⬟ |  |  |
//+--+--+--+--+--+--+
//  0  1  2  3  4  5
    }
    else if (type == 'E') {
        game = new Board;

        game->grid[0].push_back(2);
        game->grid[0].push_back(1);
        game->grid[1].push_back(2);
        game->grid[1].push_back(1);
        game->grid[2].push_back(2);
        game->grid[2].push_back(1);
        game->grid[3].push_back(2);
        game->display();
//sample output:
//+--+--+--+--+--+--+
//|  |  |  |  |  |  |
//+--+--+--+--+--+--+
//|  |  |  |  |  |  |
//+--+--+--+--+--+--+
//|⬟ |⬟ |⬟ |  |  |  |
//+--+--+--+--+--+--+
//|◉ |◉ |◉ |◉ |  |  |
//+--+--+--+--+--+--+
//  0  1  2  3  4  5
    }
    else if (type == 'F') {
        game = new Board;

        game->grid[0].push_back(0);
        game->grid[1].push_back(3);
        game->grid[0].push_back(0);
        game->grid[1].push_back(3);
        game->grid[0].push_back(0);
        game->grid[1].push_back(3);
        game->grid[3].push_back(0);
        game->grid[1].push_back(3);
        game->display();

//sample output:
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
    else if (type == 'G') {
        game = new Board;
        int bin = game->add(0); //choose a bin for player with id 0
        int bin2 = game->add(1); //choose a bin for player with id 1

        std::cout << "The layout of the bins are as follows." << std::endl;
        for (int i = 0; i < game->numBins; i++) {
        if (game->grid[i].size() == 0)
           std::cout << "empty" << std::endl;
        else {
               for (int j = 0; j < game->grid[i].size(); j++)
                   std::cout << game->grid[i][j] << " ";
               std::cout << std::endl;
        }
    }

//sample output:
//Enter a bin index in [0, 6) that is not full: -1
//invalid bin index, needs to be in [0, 6)
//Re-enter a bin index in [0, 6) that is not full: 7
//invalid bin index, needs to be in [0, 6)
//Re-enter a bin index in [0, 6) that is not full: 0
//Enter a bin index in [0, 6) that is not full: -2
//invalid bin index, needs to be in [0, 6)
//Re-enter a bin index in [0, 6) that is not full: 10
//invalid bin index, needs to be in [0, 6)
//Re-enter a bin index in [0, 6) that is not full: 1
//The layout of the bins are as follows.
//0 
//1 
//empty
//empty
//empty
//empty
    }
    else if (type == 'H') {
        //When a bin is full, cannot add more element to it.
        game = new Board;
        game->grid[0].push_back(0);
        game->grid[0].push_back(1);
        game->grid[0].push_back(0);
        game->grid[0].push_back(1);
        int bin = game->add(0); //choose a bin for player with id 0

        std::cout << "The layout of the bins are as follows." << std::endl;
        for (int i = 0; i < game->numBins; i++) {
        if (game->grid[i].size() == 0)
           std::cout << "empty" << std::endl;
        else {
               for (int j = 0; j < game->grid[i].size(); j++)
                   std::cout << game->grid[i][j] << " ";
               std::cout << std::endl;
        }
    }
//sample output:
//Enter a bin index in [0, 6) that is not full: 0
//the bin is full
//Re-enter a bin index in [0, 6) that is not full: 1
//The layout of the bins are as follows.
//0 1 0 1 
//0 
//empty
//empty
//empty
//empty
    }

    if (type == 'A' || type == 'B' || type == 'C') {
       std::cout << "After " << prompt 
            << " data member numBins is " << game->numBins << std::endl;
       std::cout << "After " << prompt
            << " data member capacity is " << game->capacity << std::endl;
    
       for (int i = 0; i < game->numBins; i++) {
           std::cout << "number of elements of bin "
               << i << " is: " 
               << game->grid[i].size() << std::endl;
    
        }
    }
    
    delete game;
    game = nullptr;

    return 0;
}
