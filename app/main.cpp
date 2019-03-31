#include "../include/Board.hpp"
#include "../include/BoardComputer.hpp"
#include "../include/PlayGame.hpp"
#include "../include/ShootingActionComputer.hpp"
#include "../include/DisplayBoardsGui.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    srand(time(0));
    BoardUser boardPlayer;
    BoardComputer boardComputer;
    ShootingActionComputer shootingActionComputer;
    
    PlayGame playGame(shootingActionComputer);
    DisplayBoardsGui displayBoardsGui(boardComputer, boardPlayer, playGame);
    return 0;
}