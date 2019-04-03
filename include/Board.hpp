#pragma once

#include <vector>
#include <algorithm>

class Board
{
protected:
    int _fieldSize = 12;
    std::vector<std::vector<int>> battleField; 
    void fillWithZeros(std::vector<std::vector<int>>& field, int vSize);
    bool checkSurroundingForUnshotShip(int x, int y) const;
    void checkSurroundingForShotShip( int x, int y, std::vector<std::pair<int, int>>& ship);
    void checkSurroundingForShotShips(int x, int y, std::vector<std::pair<int, int>>& ship);
    void fillSuroundingOfShotShip(std::vector<std::pair<int, int>>& ship);
public:
    Board();
    virtual ~Board() = 0;
    int getFieldInfo(int x, int y) const;
    int getFieldSize() const;
    void SetField(int x, int y, int val);
    bool shoot(int x, int y);
    bool isShipShot(int x, int y, int& shipSize);
    
};
    