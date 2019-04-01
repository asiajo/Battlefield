#pragma once

#include "../include/Board.hpp"
#include "../include/ShootingActionComputer.hpp"
#include "../include/BoardComputer.hpp"
#include "../include/BoardUser.hpp"
#include "../include/Board.hpp"

#include <thread>


class PlayGame
{
    ShootingActionComputer& _ShootingActionComputer;
public:
    PlayGame(ShootingActionComputer& ShootingActionComputer);
    bool checkIfWon(Board board);
    bool shootingAtComputer(int x, int y, BoardComputer& computerBoard, int& shipSize);
    bool shootingByComputer(Board& playerBoard);
};