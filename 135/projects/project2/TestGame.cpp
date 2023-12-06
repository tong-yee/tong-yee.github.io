//File name: /Users/laptopuser/Documents/courses/cs135/cs135_codes_f23/minecraft/TestGame.cpp
//name: Tong Yi
//email: ty680@hunter.cuny.edu
#include <iostream>
#include "Field.hpp"
#include "Game.hpp"
using namespace std;

int main()
{
    ////call default constructor using
    Game minesweeper;
    ////Game minesweeper(9, 3);
    //int num = minesweeper.input();
    //cout << "num = " << num << endl;

    //num = minesweeper.input();
    //cout << "num = " << num << endl;
    minesweeper.play();

    //Test answer_string method of Field class
    //Field area;
    //cout << area.answer_string() << endl;
    //cout << area.get_size() << endl;
    //cout << area.get_num_mines() << endl;

    //area.mark_checked(1);
    //cout << area.is_checked(1) << endl;
    //cout << area.is_checked(3) << endl;

    return 0;
}
