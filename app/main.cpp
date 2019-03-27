#include "../include/Board.hpp"
#include "../include/BoardComputer.hpp"
#include "../include/PlayGame.hpp"
#include "../include/ShootingActionComputer.hpp"
#include "../include/ShootingAction.hpp"
#include "../include/DisplayBoardsGui.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    BoardUser boardPlayer;
    BoardComputer boardComputer;
    std::shared_ptr<ShootingActionComputer> shootingActionComputer;
    std::shared_ptr<ShootingAction> userShootingAction;
    boardComputer.fillComputerField();
    
    PlayGame playGame(shootingActionComputer, userShootingAction);
    DisplayBoardsGui displayBoardsGui(boardComputer, boardPlayer, playGame);
    return 0;
}