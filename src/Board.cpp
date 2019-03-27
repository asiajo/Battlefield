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