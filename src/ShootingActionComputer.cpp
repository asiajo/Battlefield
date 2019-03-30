#include "../include/ShootingActionComputer.hpp"


std::pair <int, int> ShootingActionComputer::computerShot(Board& board)
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
        if(board.getFieldInfo(x1,y1) <= 1)
            flag = true;
    }
    // increase chances of computer
    if (board.getFieldInfo(x3,y3) == 1) output = std::make_pair(x3, y3);
    else if (board.getFieldInfo(x2,y2) == 1) output = std::make_pair(x2, y2);
    else output = std::make_pair(x1, y1);
    return output;
}

