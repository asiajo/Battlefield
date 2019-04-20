#pragma once

#include "Board.hpp"
#include "Position.hpp"

  
struct BoardUser : public Board
{
    bool pushShip(const Position& p);
};
    