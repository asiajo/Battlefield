#pragma once

#include "../include/Board.hpp"

#include <random>

  
struct ShootingActionComputer
{
    std::pair <int, int> computerShot(Board& board);
};
    