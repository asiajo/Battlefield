#include "../include/BoardUser.hpp"

    
bool BoardUser::pushShip(int x, int y)
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
