#include "../include/battleshipComputer.hpp"

BattleshipComputer::BattleshipComputer()
{
    fillWithZeros(hideBattleField, _fieldSize);
}

std::pair <int, int> BattleshipComputer::generatePosition(int dirX, int len)
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

bool BattleshipComputer::checkSurrounding(int x, int y)
{
    for(int i = x-1; i<=x+1; i++)
        for(int j = y-1; j<=y+1; j++)
            if (battleField[i][j] == 1)
                return false;
    return true;
}


bool BattleshipComputer::generateShip(int len)
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

void BattleshipComputer::fillComputerField()
{
    
    int amount = 4;
    while(amount>0){
        for(int i = 0; i < 5-amount; i++)
            if(!generateShip(amount))
                i--;
        amount--;
    }
}

std::pair <int, int> BattleshipComputer::computerShot(Battleship& player)
{
    bool flag = false;
    int x1,y1, x2, y2, x3, y3;
    std::pair<int, int> output;
    while (!flag)
    {
        x1 = (rand() %10)+1;
        y1 = (rand() %10)+1;
        x2 = (rand() %10)+1;
        y2 = (rand() %10)+1;
        x3 = (rand() %10)+1;
        y3 = (rand() %10)+1;
        if(player.getFieldInfo(x1,y1) <= 1)
            flag = true;
    }
    // increase chances of computer
    if (player.getFieldInfo(x3,y3) == 1) output = std::make_pair(x3, y3);
    else if (player.getFieldInfo(x2,y2) == 1) output = std::make_pair(x2, y2);
    else output = std::make_pair(x1, y1);
    return output;
}

int BattleshipComputer::getVisibleFieldInfo(int x, int y)
{
    if( ( x < _fieldSize && x > 0 ) && ( y < _fieldSize && y > 0 ) )
        return hideBattleField[x][y];
    else return -1;
}

void BattleshipComputer::setVisibleField(int x, int y, int val)
{
    hideBattleField[x][y] = val;
}