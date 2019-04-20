#pragma once

#include "Board.hpp"
#include "ShootingActionComputer.hpp"
#include "BoardComputer.hpp"
#include "BoardUser.hpp"
#include "Board.hpp"
#include "Position.hpp"

#include <thread>


class PlayGame
{
    ShootingActionComputer& _ShootingActionComputer;
public:
    PlayGame(ShootingActionComputer& ShootingActionComputer);
    bool checkIfWon(const Board& board) const;
    bool shootingAtComputer(const Position& p, BoardComputer& computerBoard, int& shipSize);
    bool shootingByComputer(Board& playerBoard);
};