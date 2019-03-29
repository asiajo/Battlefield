#include "../include/Board.hpp"
#include <iostream>

Board::Board()
{
    fillWithZeros(battleField, _fieldSize);
}

void Board::fillWithZeros(std::vector<std::vector<int>>& field, int vSize)
{
    field.resize(vSize);
    for(int i =0; i<vSize; i++)
        field[i].resize(vSize, 0);
}

int Board::getFieldInfo(int x, int y)
{
    if( ( x < _fieldSize && x > 0 ) && ( y < _fieldSize && y > 0 ) )
        return battleField[x][y];
    else return -1;
}

int Board::getFieldSize()
{
    return _fieldSize;
}

void Board::SetField(int x, int y, int val)
{
    battleField[x][y] = val;
}

bool Board::shoot(int x, int y)
{
    int vSize = getFieldSize();
    if( ( x < vSize && x > 0 ) && ( y < vSize && y > 0 ) )
    {
        if(getFieldInfo(x, y) == 1)
        {
           SetField(x, y, 2);
            return true;
        }
        else if (getFieldInfo(x, y) == 0)
        {
            SetField(x, y, 3);
            return false;
        }
    }
    return false;
}

bool Board::checkSurroundingForUnshotShip(int x, int y)
{
    if(getFieldInfo(x+1, y  ) == 1) return false;
    if(getFieldInfo(x-1, y  ) == 1) return false;
    if(getFieldInfo(x  , y+1) == 1) return false;
    if(getFieldInfo(x  , y-1) == 1) return false; 
    return true;
}

void Board::checkSurroundingForShotShip(int x, int y, std::vector<std::pair<int, int>>& ship)
{
    if(getFieldInfo(x, y) == 2 && std::find(begin(ship), end(ship), std::make_pair(x,y)) == end(ship)) 
    {
        ship.push_back(std::make_pair(x,y));
        checkSurroundingForShotShips(x,y, ship);
    }
}

void Board::checkSurroundingForShotShips(int x, int y, std::vector<std::pair<int, int>>& ship)
{
    checkSurroundingForShotShip(x+1, y  , ship);
    checkSurroundingForShotShip(x-1, y  , ship);
    checkSurroundingForShotShip(x  , y+1, ship);
    checkSurroundingForShotShip(x  , y-1, ship);
}

bool Board::isShipShot(int x, int y){
    
    std::vector<std::pair<int, int>> ship{std::make_pair(x,y)};
    checkSurroundingForShotShips(x,y, ship);
    for(std::pair<int, int> elem : ship)
        if(!checkSurroundingForUnshotShip(elem.first, elem.second))
            return false;
    fillSuroundingOfShotShip(ship);
    return true; 
}

void Board::fillSuroundingOfShotShip(std::vector<std::pair<int, int>>& ship)
{
    for(std::pair<int, int> elem : ship)
    {   int x = elem.first;
        int y = elem.second;
        if(getFieldInfo(x+1, y  ) == 0) SetField(x+1, y  , 8);
        if(getFieldInfo(x-1, y  ) == 0) SetField(x-1, y  , 8);
        if(getFieldInfo(x,   y+1) == 0) SetField(x,   y+1, 8);
        if(getFieldInfo(x,   y-1) == 0) SetField(x,   y-1, 8);
        if(getFieldInfo(x+1, y+1) == 0) SetField(x+1, y+1, 8);
        if(getFieldInfo(x-1, y-1) == 0) SetField(x-1, y-1, 8);
        if(getFieldInfo(x-1, y+1) == 0) SetField(x-1, y+1, 8);
        if(getFieldInfo(x+1, y-1) == 0) SetField(x+1, y-1, 8);
    }
}