#pragma once

#include "../include/Board.hpp"
#include "../include/ShootingAction.hpp"

#include <random>

  
struct ShootingActionComputer : public ShootingAction
{
    std::pair <int, int> computerShot(Board& board);
};
    