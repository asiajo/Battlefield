#pragma once

#include "../include/Board.hpp"

  
struct BoardUser : public Board
{
    bool pushShip(int x, int y);
};
    