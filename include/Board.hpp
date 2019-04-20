#pragma once

#include <vector>
#include <algorithm>
#include "FieldStatus.hpp"
#include "ShootResult.hpp"
#include "Position.hpp"

class Board
{
    ShootResult isShipShot(const Position& p);
    bool checkSurroundingForUnshotShip(const Position& p) const;
    void checkSurroundingForShotShip( const Position& p, std::vector<Position>& ship);
    void checkSurroundingForShotShips(const Position& p, std::vector<Position>& ship);
    void fillSuroundingOfShotShip(std::vector<Position>& ship);

protected:
    int _fieldSize = 12;
    std::vector<std::vector<FieldStatus>> battleField; 
    void fillWithZeros(std::vector<std::vector<FieldStatus>>& field, const int vSize);

public:
    Board();
    virtual ~Board() = 0;
    FieldStatus getFieldInfo(const Position& p) const;
    int getFieldSize() const;
    void SetField(const Position& p, const FieldStatus val);
    ShootResult shoot(const Position& p);
    
};
    