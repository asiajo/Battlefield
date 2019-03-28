#include "../include/Board.hpp"

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
    int vSize = this -> getFieldSize();
    if( ( x < vSize && x > 0 ) && ( y < vSize && y > 0 ) )
    {
        if(this -> getFieldInfo(x, y) == 1)
        {
           this -> SetField(x, y, 2);
            return true;
        }
        else if (this -> getFieldInfo(x, y) == 0)
        {
            this -> SetField(x, y, 3);
            return false;
        }
    }
    return false;
}