#pragma once

#include "../include/battleship.hpp"
#include "../include/battleshipComputer.hpp"

#include <SFML/Graphics.hpp>
#include <thread>


class Gui
{
   int w = 32; 
public:
    Gui(BattleshipComputer& computer, Battleship& player);
    void setGraphic(sf::Sprite& s, sf::RenderWindow& app, Battleship& player, int move);
    void alert(std::string text);
};