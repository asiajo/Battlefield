#pragma once

#include "../include/BoardUser.hpp"
#include "../include/BoardComputer.hpp"
#include "../include/PlayGame.hpp"

#include <SFML/Graphics.hpp>
#include <sstream>


class DisplayBoardsGui
{
    int w = 50; 
    void alert(std::string text);
    void displayFields(BoardComputer& computer, BoardUser& player, sf::RenderWindow& app, sf::Sprite& s, int w);
    void displayShipsCounter(sf::RenderWindow& app, int ship4, int ship3, int ship2, int ship1);
public:
    DisplayBoardsGui(BoardComputer& computer, BoardUser& player, PlayGame& playGame);
    
};