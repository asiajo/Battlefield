#include "../include/ShootingAction.hpp"

bool ShootingAction::shoot(int x, int y, Board& board)
{
    int vSize = board.getFieldSize();
    if( ( x < vSize && x > 0 ) && ( y < vSize && y > 0 ) )
    {
        if(board.getFieldInfo(x, y) == 1)
        {
            board.SetField(x, y, 2);
            return true;
        }
        else if (board.getFieldInfo(x, y) == 0)
        {
            board.SetField(x, y, 3);
            return false;
        }
    }
    return false;
}