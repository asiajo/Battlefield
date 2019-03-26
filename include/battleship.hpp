#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <random>
#include <cstdlib>      //abs
#include <ctime>

  
class Battleship
{
protected:
    int _fieldSize;
    std::vector<std::vector<int>> battleField; 
    void fillWithZeros(std::vector<std::vector<int>>& field, int vSize);
public:
    Battleship ();
    ~Battleship ();
    int getFieldInfo(int x, int y);
    bool pushShip(int x, int y);
    bool shoot(int x, int y);
    bool checkIfWon();
    void showField();
};
    