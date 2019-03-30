#pragma once

#include "../include/Board.hpp"

#include <random>

  
class ShootingActionComputer
{
    std::vector<std::pair <int, int>> _unshotShip;
    std::pair <int, int> checkHorizontal(Board& board);
    std::pair <int, int> checkVertical(Board& board);
public:
    std::pair <int, int> computerShot(Board& board);
    void addUnshotShip(std::pair <int, int> shipPart);
    void clearShotShip();
};
    