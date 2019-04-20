#pragma once

#include "Board.hpp"
#include "Position.hpp"

#include <random>
#include <cstdlib>      //abs


class BoardComputer : public Board
{
    std::vector<std::vector<FieldStatus>> hideBattleField; 
    Position generatePosition(const int dirX, const int len);
    bool generateShip(const int len);
    bool checkSurrounding(const Position& p) const;
    void fillComputerField();
public:
    BoardComputer();
    void crossFields();
    void setVisibleField(const Position& p, const FieldStatus val);
    FieldStatus getVisibleFieldInfo(const Position& p) const;
};