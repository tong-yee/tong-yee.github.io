//#pragma once
#ifndef GAME_H
#define GAME_H
#include "Field.hpp"
class Game {
    private:
        Field area; 
    public:
        Game();
        Game(int size, int num_mines);
        int input() const;
        void play();
};
#endif
