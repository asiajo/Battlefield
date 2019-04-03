#pragma once

#include "../include/Board.hpp"

#include <random>

  
class ShootingActionComputer
{
    std::vector<std::pair <int, int>> _unshotShip;
    std::pair <int, int> checkHorizontal(const Board& board) const;
    std::pair <int, int> checkVertical(const Board& board) const;
public:
    std::pair <int, int> computerShot(const Board& board) const;
    void addUnshotShip(std::pair <int, int> shipPart);
    void clearShotShip();
};
    