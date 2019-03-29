#include "../include/PlayGame.hpp"
#include <iostream>

PlayGame::PlayGame(std::shared_ptr<ShootingActionComputer> ShootingActionComputer) : _ShootingActionComputer(ShootingActionComputer)
{}

bool PlayGame::checkIfWon(Board board)
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

void PlayGame::shootingSession(int x, int y, BoardComputer& computerBoard, Board& playerBoard)
{
    if(computerBoard.getFieldInfo(x,y)<=1)
    {
        computerBoard.shoot(x,y);
        if(computerBoard.getFieldInfo(x,y) == 2) 
            if(computerBoard.isShipShot(x, y))
                computerBoard.crossFields();
        computerBoard.setVisibleField(x,y,computerBoard.getFieldInfo(x, y));
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        std::pair <int, int> shipPos = _ShootingActionComputer -> computerShot(playerBoard);
        playerBoard.shoot(shipPos.first, shipPos.second);
        if(playerBoard.getFieldInfo(shipPos.first, shipPos.second) == 2) 
            playerBoard.isShipShot(shipPos.first, shipPos.second);
    }
}

