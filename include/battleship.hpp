#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>   //bind
#include <random>
#include <cstdlib>      //abs
#include <ctime>

  
class Battleship
{
    int _fieldSize;
    std::vector<std::vector<int>> battleField; 
    std::vector<std::vector<int>> hideBattleField; 
    std::pair <int, int> generatePosition(int dirX, int len);
    bool generateShip(int len);
    bool checkSurrounding(int x, int y);
public:
    Battleship ();
    ~Battleship ();
    int getFieldInfo(int x, int y);
    bool pushShip(int x, int y);
    bool shoot(int x, int y);
    bool checkIfWon();
    void fillComputerField();
    void showField();
    int getFieldSize();
    std::pair <int, int> computerShot(Battleship& player);
};
    