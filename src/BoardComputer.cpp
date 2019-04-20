#include "../include/BoardComputer.hpp"

BoardComputer::BoardComputer()
{
    fillWithZeros(hideBattleField, _fieldSize);
    fillComputerField();
}

Position BoardComputer::generatePosition(const int dirX, const int len)
{
    int x;
    int y;
            
    if(dirX)
    {
        x = (rand() %(10-len))+1;
        y = (rand() %10)+1;
    }else
    {
        x = (rand() %10)+1;
        y = (rand() %(10-len))+1;
    }
    Position p = {x,y};
    return p;
}

bool BoardComputer::checkSurrounding(const Position& p) const
{
    for(int i = p.x-1; i<=p.x+1; i++)
        for(int j = p.y-1; j<=p.y+1; j++)
            if (battleField[i][j] == FieldStatus::SHIP)
                return false;
    return true;
}

bool BoardComputer::generateShip(int len)
{
    int dirX = (rand() %2);
    int dirY = abs(dirX-1);
    Position pos = generatePosition(dirX, len);
    bool isCorrect = true;
    for(int i = 0; i < len; i++)
    {
        Position p = {pos.x + dirX*i, pos.y + dirY*i};
        if (!checkSurrounding(p))
            isCorrect = false;
    }
    if (isCorrect)
    {
        for(int i=0; i<len; i++)
            battleField[pos.x+dirX*i][pos.y+dirY*i] = FieldStatus::SHIP;
        return true;
    }
    return false;
}

void BoardComputer::fillComputerField()
{
    
    int amount = 4;
    while(amount>0){
        for(int i = 0; i < 5-amount; i++)
            if(!generateShip(amount))
                i--;
        amount--;
    }
}

FieldStatus BoardComputer::getVisibleFieldInfo(const Position& p) const
{
    if( ( p.x < _fieldSize && p.x > 0 ) && ( p.y < _fieldSize && p.y > 0 ) )
        return hideBattleField[p.x][p.y];
    else return FieldStatus::OUT_OF_BOUNDS;
}

void BoardComputer::setVisibleField(const Position& p, const FieldStatus val)
{
    hideBattleField[p.x][p.y] = val;
}

void BoardComputer::crossFields()
{
    int bSize = getFieldSize();

    for (int i = 1; i < bSize-1; i++)
        for(int j = 1; j < bSize-1; j++)
        {
            Position p = {i, j};
            if (getFieldInfo(p) == FieldStatus::SHIP_SURROUNDING)
                setVisibleField(p, FieldStatus::SHIP_SURROUNDING);
        }
}