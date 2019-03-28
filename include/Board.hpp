#pragma once

#include <vector>


class Board
{
protected:
    int _fieldSize = 12;
    std::vector<std::vector<int>> battleField; 
    void fillWithZeros(std::vector<std::vector<int>>& field, int vSize);
public:
    Board();
    int getFieldInfo(int x, int y);
    int getFieldSize();
    void SetField(int x, int y, int val);
    bool shoot(int x, int y);
};
    