#include "../include/BoardComputer.hpp"

BoardComputer::BoardComputer()
{
    fillWithZeros(hideBattleField, _fieldSize);
    fillComputerField();
}

std::pair <int, int> BoardComputer::generatePosition(int dirX, int len)
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
    return std::make_pair(x,y);
}

bool BoardComputer::checkSurrounding(int x, int y)
{
    for(int i = x-1; i<=x+1; i++)
        for(int j = y-1; j<=y+1; j++)
            if (battleField[i][j] == 1)
                return false;
    return true;
}


bool BoardComputer::generateShip(int len)
{
    int dirX = (rand() %2);
    int dirY = abs(dirX-1);
    std::pair <int, int> pos = generatePosition(dirX, len);
    int x = pos.first;
    int y = pos.second;
    bool isCorrect = true;
    for(int i = 0; i < len; i++)
        if (!checkSurrounding(pos.first+dirX*i, pos.second+dirY*i))
            isCorrect = false;
    if (isCorrect)
    {
        for(int i=0; i<len; i++)
            battleField[x+dirX*i][y+dirY*i] = 1;
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

int BoardComputer::getVisibleFieldInfo(int x, int y)
{
    if( ( x < _fieldSize && x > 0 ) && ( y < _fieldSize && y > 0 ) )
        return hideBattleField[x][y];
    else return -1;
}

void BoardComputer::setVisibleField(int x, int y, int val)
{
    hideBattleField[x][y] = val;
}

