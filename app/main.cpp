#include "../include/battleship.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

/// Battleship game.
/// Version 1 - Main Logic
/// TODO: implement game
/// march 2019


int main(int argc, char* argv[])
{
    Battleship ship;  
    ship.fillComputerField();
    ship.showField();
    return 0;
}
