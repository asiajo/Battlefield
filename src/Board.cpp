#include "../include/Board.hpp"

Board::Board()
{
    fillWithZeros(battleField, _fieldSize);
}

Board::~Board(){}

void Board::fillWithZeros(std::vector<std::vector<FieldStatus>>& field, const int vSize)
{
    field.resize(vSize);
    std::for_each(begin(field), end(field), [&](std::vector<FieldStatus> &f){ f.resize(vSize, FieldStatus::FREE); });
}

FieldStatus Board::getFieldInfo(const Position& p) const
{
    if( p < _fieldSize && p > 0 )
        return battleField[p.x][p.y];
    else return FieldStatus::OUT_OF_BOUNDS;
}

int Board::getFieldSize() const
{
    return _fieldSize;
}

void Board::SetField(const Position& p, const FieldStatus val)
{
    battleField[p.x][p.y] = val;
}

ShootResult Board::shoot(const Position& p)
{
    int vSize = getFieldSize();
    if( p < vSize && p > 0 )
    {
        if(getFieldInfo(p) == FieldStatus::SHIP)
        {
            SetField(p, FieldStatus::SHOT);
            return isShipShot(p);
        }
        else if (getFieldInfo(p) == FieldStatus::FREE)
        {
            SetField(p, FieldStatus::MISSED);
            return ShootResult::MISS;
        }
    }
    return ShootResult::FAIL;
}

bool Board::checkSurroundingForUnshotShip(const Position& p) const
{
    Position p1 = {p.x+1, p.y};
    if(getFieldInfo(p1) == FieldStatus::SHIP) return false;
    Position p2 = {p.x-1, p.y};
    if(getFieldInfo(p2) == FieldStatus::SHIP) return false;
    Position p3 = {p.x, p.y+1};
    if(getFieldInfo(p3) == FieldStatus::SHIP) return false;
    Position p4 = {p.x, p.y-1};
    if(getFieldInfo(p4) == FieldStatus::SHIP) return false; 
    return true;
}

void Board::checkSurroundingForShotShip(const Position& p, std::vector<Position>& ship)
{
    if(getFieldInfo(p) == FieldStatus::SHOT && std::find(begin(ship), end(ship), p) == end(ship)) 
    {
        ship.push_back(p);
        checkSurroundingForShotShips(p, ship);
    }
}

void Board::checkSurroundingForShotShips(const Position& p, std::vector<Position>& ship)
{
    Position p1 = {p.x+1, p.y};
    checkSurroundingForShotShip(p1, ship);
    Position p2 = {p.x-1, p.y};
    checkSurroundingForShotShip(p2, ship);
    Position p3 = {p.x, p.y+1};
    checkSurroundingForShotShip(p3, ship);
    Position p4 = {p.x, p.y-1};
    checkSurroundingForShotShip(p4, ship);
}

ShootResult Board::isShipShot(const Position& p)
{   
    std::vector<Position> ship{p};
    checkSurroundingForShotShips(p, ship);
    for(Position pos : ship)
        if(!checkSurroundingForUnshotShip(pos))
            return ShootResult::HIT;
    fillSuroundingOfShotShip(ship);
    return static_cast<ShootResult>(std::min((int)ship.size(), 4)); // just in case the user created ships not according to rules
}

void Board::fillSuroundingOfShotShip(std::vector<Position>& ship)
{
    for(Position elem : ship)
    {   
        for( int x = elem.x-1; x <= elem.x+1; x ++)
            for(int y = elem.y-1; y <= elem.y+1; y++)
            {
                Position p = {x, y};
                if(getFieldInfo(p) == FieldStatus::FREE) SetField(p , FieldStatus::SHIP_SURROUNDING);
            }

    }
}