#pragma once
#include "../include/battleship.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>   //bind
#include <random>
#include <cstdlib>      //abs
#include <ctime>

  
class BattleshipComputer : public Battleship
{
    std::vector<std::vector<int>> hideBattleField; 
    std::pair <int, int> generatePosition(int dirX, int len);
    bool generateShip(int len);
    bool checkSurrounding(int x, int y);
public:
    void fillComputerField();
    std::pair <int, int> computerShot(Battleship& player);
};
    