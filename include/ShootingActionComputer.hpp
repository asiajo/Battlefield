#pragma once

#include "../include/Board.hpp"
#include "Position.hpp"

#include <random>

  
class ShootingActionComputer
{
    std::vector<Position> _unshotShip;
    Position checkHorizontal(const Board& board) const;
    Position checkVertical(const Board& board) const;
public:
    Position computerShot(const Board& board) const;
    void addUnshotShip(const Position& shipPart);
    void clearShotShip();
};
    