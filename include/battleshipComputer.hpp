#pragma once
#include "../include/battleship.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
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
    BattleshipComputer();
    void fillComputerField();
    std::pair <int, int> computerShot(Battleship& player);
    void setVisibleField(int x, int y, int val);
    int getVisibleFieldInfo(int x, int y);
};
    