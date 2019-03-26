#include "../include/battleship.hpp"

Battleship::Battleship()
{
    _fieldSize = 12;
    fillWithZeros(battleField, _fieldSize);
}

Battleship::~Battleship(){}

int Battleship::getFieldInfo(int x, int y)
{
    if( ( x < _fieldSize && x > 0 ) && ( y < _fieldSize && y > 0 ) )
        return battleField[x][y];
    else return -1;
}
    
bool Battleship::pushShip(int x, int y)
{
    if( ( x < _fieldSize-1 && x > 0 ) && ( y < _fieldSize-1 && y > 0 ) )
    {
        if(battleField[x][y] == 0)
        {
            battleField[x][y] = 1;
            return true;
        }
    }
    return false;
}

bool Battleship::shoot(int x, int y)
{
    if( ( x < _fieldSize && x > 0 ) && ( y < _fieldSize && y > 0 ) )
    {
        if(getFieldInfo(x, y) == 1)
        {
            battleField[x][y] = 2;
            return true;
        }
        else if (getFieldInfo(x, y) == 0)
        {
            battleField[x][y] = 3;
            return false;
        }
    }
    return false;
}

bool Battleship::checkIfWon()
{
    for(auto vect : battleField)
        if(std::find(begin(vect), end(vect), 1) != end(vect)) return false;
    
    return true; 
}

void Battleship::showField()
{
    std::for_each(begin(battleField), end(battleField), [](std::vector<int> v){
        for(auto e : v)
        {
            std::cout.width(4);
            std::cout << e;
        }
    std::cout << std::endl;});
}

void Battleship::fillWithZeros(std::vector<std::vector<int>>& field, int vSize)
{
    field.resize(vSize);
    for(int i =0; i<vSize; i++)
        field[i].resize(vSize, 0); 
}