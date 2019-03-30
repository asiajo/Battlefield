#pragma once

#include "../include/Board.hpp"
#include "../include/ShootingActionComputer.hpp"
#include "../include/BoardComputer.hpp"
#include "../include/BoardUser.hpp"
#include "../include/Board.hpp"

#include <thread>


class PlayGame
{
    std::shared_ptr<ShootingActionComputer> _ShootingActionComputer;
public:
    PlayGame(std::shared_ptr<ShootingActionComputer> ShootingActionComputer);
    bool checkIfWon(Board board);
    void shootingSession(int x, int y, BoardComputer& computerBoard, Board& playerBoard);
};