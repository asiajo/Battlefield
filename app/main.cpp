#include "../include/battleship.hpp"
#include "../include/gui.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    Battleship computer;
    Battleship player;
    srand(time(NULL));

    computer.fillComputerField();
    Gui gui(computer, player);
    return 0;
}
