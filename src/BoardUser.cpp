#include "../include/BoardUser.hpp"

    
bool BoardUser::pushShip(const Position& p)
{
    if( p < _fieldSize-1 && p > 0 )
    {
        if(battleField[p.x][p.y] == FieldStatus::FREE)
        {
            battleField[p.x][p.y] = FieldStatus::SHIP;
            return true;
        }
    }
    return false;
}
