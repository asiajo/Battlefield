#pragma once

#include "../include/Board.hpp"

#include <random>
#include <cstdlib>      //abs


class BoardComputer : public Board
{
    std::vector<std::vector<int>> hideBattleField; 
    std::pair <int, int> generatePosition(int dirX, int len);
    bool generateShip(int len);
    bool checkSurrounding(int x, int y);
public:
    BoardComputer();
    void fillComputerField();
    void setVisibleField(int x, int y, int val);
    int getVisibleFieldInfo(int x, int y);
};