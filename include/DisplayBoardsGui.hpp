#pragma once

#include "BoardUser.hpp"
#include "BoardComputer.hpp"
#include "PlayGame.hpp"
#include "Position.hpp"

#include <SFML/Graphics.hpp>
#include <sstream>


class DisplayBoardsGui
{
    sf::Font font;
    sf::Text atext;
    std::ostringstream os;
    int w = 50; 
    void alert(sf::RenderWindow& app,std::string text);
    void displayFields(sf::RenderWindow& app, const BoardComputer& computer, const BoardUser& player, sf::Sprite& s, int w);
    void displayShipsCounter(sf::RenderWindow& app, int ship4, int ship3, int ship2, int ship1);
public:
    DisplayBoardsGui(BoardComputer& computer, BoardUser& player, PlayGame& playGame);
    
};