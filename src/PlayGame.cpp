#include "../include/PlayGame.hpp"

PlayGame::PlayGame(std::shared_ptr<ShootingActionComputer> ShootingActionComputer, std::shared_ptr<ShootingAction> userShootingAction) : _ShootingActionComputer(ShootingActionComputer), _userShootingAction(userShootingAction)
{}

bool PlayGame::checkIfWon(Board board)
{
    int bSize = board.getFieldSize();

    for (int i = 0; i < bSize; i++)
        for(int j = 0; j < bSize; j++)
            if (board.getFieldInfo(i, j) == 1)
                return false;
    
    return true;
}

void PlayGame::shootingSession(int x, int y, BoardComputer& computerBoard, Board& playerBoard)
{
    if(computerBoard.getFieldInfo(x,y)<=1)
    {
        (*_ShootingActionComputer).shoot(x,y, computerBoard);
        computerBoard.setVisibleField(x,y,computerBoard.getFieldInfo(x, y));
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::pair <int, int> shipPos = (*_ShootingActionComputer).computerShot(playerBoard);
        (*_userShootingAction).shoot(shipPos.first, shipPos.second, playerBoard);
    }
}

bool PlayGame::pushShip(int x, int y, BoardUser& playerBoard)
{
    bool tmp = playerBoard.pushShip(x,y);
    return tmp;
}

