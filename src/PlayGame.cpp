#include "../include/PlayGame.hpp"
#include <iostream>

PlayGame::PlayGame(ShootingActionComputer& ShootingActionComputer) : _ShootingActionComputer(ShootingActionComputer)
{}

bool PlayGame::checkIfWon(const Board& board) const
{
    int bSize = board.getFieldSize();

    for (int i = 1; i < bSize-1; i++)
        for(int j = 1; j < bSize-1; j++)
        {
            Position p = {i,j};
            if (board.getFieldInfo(p) == FieldStatus::SHIP)
                return false;
        }
    for (int i = 1; i < bSize-1; i++)
        for(int j = 1; j < bSize-1; j++)
        {
            Position p = {i,j};
            if (board.getFieldInfo(p) == FieldStatus::SHOT || board.getFieldInfo(p) == FieldStatus::MISSED )
                return true;
        }
    
    return false;
}


bool PlayGame::shootingAtComputer(const Position& p, BoardComputer& computerBoard, int& shipSize)
{
    shipSize = 0;
    if(computerBoard.getFieldInfo(p) == FieldStatus::SHIP
    || computerBoard.getFieldInfo(p) == FieldStatus::FREE)
    {
        ShootResult result = computerBoard.shoot(p);
        if( result == ShootResult::SUNK1 ||
            result == ShootResult::SUNK2 ||
            result == ShootResult::SUNK3 ||
            result == ShootResult::SUNK4 )
            {
                computerBoard.crossFields();
                shipSize = static_cast<int>(result);
            }
        computerBoard.setVisibleField(p, computerBoard.getFieldInfo(p));
        if(computerBoard.getFieldInfo(p)==FieldStatus::SHOT)
            return false;
        else 
            return true;
    }
    return false;
}

bool PlayGame::shootingByComputer(Board& playerBoard)
{
    Position shipPos = _ShootingActionComputer.computerShot(playerBoard);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    ShootResult result = playerBoard.shoot(shipPos);
    if ( result == ShootResult::SUNK1 ||
         result == ShootResult::SUNK2 ||
         result == ShootResult::SUNK3 ||
         result == ShootResult::SUNK4)               
            {
                _ShootingActionComputer.clearShotShip();
                return false;
            } 
    if (result == ShootResult::HIT)
    {
        _ShootingActionComputer.addUnshotShip(shipPos);
        return false;
    }
    return true;
}