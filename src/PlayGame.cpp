#include "../include/PlayGame.hpp"
#include <iostream>

PlayGame::PlayGame(ShootingActionComputer& ShootingActionComputer) : _ShootingActionComputer(ShootingActionComputer)
{}

bool PlayGame::checkIfWon(const Board& board) const
{
    int bSize = board.getFieldSize();

    for (int i = 1; i < bSize-1; i++)
        for(int j = 1; j < bSize-1; j++)
            if (board.getFieldInfo(i, j) == 1)
                return false;
    for (int i = 1; i < bSize-1; i++)
        for(int j = 1; j < bSize-1; j++)
            if (board.getFieldInfo(i, j) == 2 || board.getFieldInfo(i, j) == 3 )
                return true;
    
    return false;
}


bool PlayGame::shootingAtComputer(int x, int y, BoardComputer& computerBoard, int& shipSize)
{
    shipSize = 0;
    if(computerBoard.getFieldInfo(x,y)<=1)
    {
        computerBoard.shoot(x,y);
        if(computerBoard.getFieldInfo(x,y) == 2) 
            if(computerBoard.isShipShot(x, y, shipSize))
                computerBoard.crossFields();
        computerBoard.setVisibleField(x,y,computerBoard.getFieldInfo(x, y));
        if(computerBoard.getFieldInfo(x,y)==2)
            return false;
        else
            return true;
    }
    return false;
}

bool PlayGame::shootingByComputer(Board& playerBoard)
{
    int myShipSize;
    std::pair <int, int> shipPos = _ShootingActionComputer.computerShot(playerBoard);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    playerBoard.shoot(shipPos.first, shipPos.second);
    if(playerBoard.getFieldInfo(shipPos.first, shipPos.second) == 2) 
    {
        if(playerBoard.isShipShot(shipPos.first, shipPos.second, myShipSize))
                _ShootingActionComputer.clearShotShip();
        else
            _ShootingActionComputer.addUnshotShip(std::make_pair(shipPos.first, shipPos.second));
        return false;
    }
    else
        return true;
}