#include "../include/battleship.hpp"

Battleship::Battleship()
{
    _fieldSize = 12;
    battleField.resize(_fieldSize);
    battleField.resize(_fieldSize);
    for(int i =0; i<_fieldSize; i++)
    {
        battleField[i].resize(_fieldSize, 0); 
        battleField[i].resize(_fieldSize, 0); 
    }
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

std::pair <int, int> Battleship::generatePosition(int dirX, int len)
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

bool Battleship::checkSurrounding(int x, int y)
{
    for(int i = x-1; i<=x+1; i++)
        for(int j = y-1; j<=y+1; j++)
            if (battleField[i][j] == 1)
                return false;
    return true;
}


bool Battleship::generateShip(int len)
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

void Battleship::fillComputerField()
{
    
    int amount = 4;
    while(amount>0){
        for(int i = 0; i < 5-amount; i++)
            if(!generateShip(amount))
                i--;
        amount--;
    }
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

std::pair <int, int> Battleship::computerShot(Battleship& player)
{
    bool flag = false;
    int x,y;
    while (!flag)
    {
        x = (rand() %10)+1;
        y = (rand() %10)+1;
        if(player.getFieldInfo(x,y) <=1)
            flag = true;
    }
    return std::make_pair(x, y);
}
