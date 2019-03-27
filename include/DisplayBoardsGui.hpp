#pragma once

#include "../include/BoardUser.hpp"
#include "../include/BoardComputer.hpp"
#include "../include/PlayGame.hpp"

#include <SFML/Graphics.hpp>



class DisplayBoardsGui
{
    int w = 50; 
    void alert(std::string text);
    void displayFields(BoardComputer& computer, BoardUser& player, sf::RenderWindow& app, sf::Sprite& s, int w, sf::Sprite sBackground);
public:
    DisplayBoardsGui(BoardComputer& computer, BoardUser& player, PlayGame& playGame);
};