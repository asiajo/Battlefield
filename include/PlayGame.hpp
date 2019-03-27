#pragma once

#include "../include/Board.hpp"
#include "../include/ShootingActionComputer.hpp"
#include "../include/ShootingAction.hpp"
#include "../include/BoardComputer.hpp"
#include "../include/BoardUser.hpp"
#include "../include/Board.hpp"

#include <thread>


class PlayGame
{
    std::shared_ptr<ShootingActionComputer> _ShootingActionComputer;
    std::shared_ptr<ShootingAction> _userShootingAction;
public:
    PlayGame(std::shared_ptr<ShootingActionComputer> ShootingActionComputer, std::shared_ptr<ShootingAction> userShootingAction);
    bool checkIfWon(Board board);
    void shootingSession(int x, int y, BoardComputer& computerBoard, Board& playerBoard);
    bool pushShip(int x, int y, BoardUser& playerBoard);
};