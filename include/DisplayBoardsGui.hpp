#pragma once

#include "../include/BoardUser.hpp"
#include "../include/BoardComputer.hpp"
#include "../include/PlayGame.hpp"

#include <SFML/Graphics.hpp>



class DisplayBoardsGui
{
    int w = 32; 
    void alert(std::string text);
public:
    DisplayBoardsGui(BoardComputer& computer, BoardUser& player, PlayGame& playGame);
};