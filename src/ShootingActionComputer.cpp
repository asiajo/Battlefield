#include "../include/ShootingActionComputer.hpp"
#include <iostream>

std::pair <int, int> ShootingActionComputer::computerShot(Board& board)
{
    if(!_unshotShip.empty())
    {
        if (_unshotShip.size() > 1)
        {
            if(_unshotShip[0].first == _unshotShip[1].first)
                return checkVertical(board);
            else if(_unshotShip[0].second == _unshotShip[1].second)
                return checkHorizontal(board);
        }
        else
        {
            std::pair <int, int> h = checkHorizontal(board);
            std::pair <int, int> v = checkVertical(board);
            return h.first > v.first ? h : v;
        }
    }
    
    bool flag = false;
    int x, y;
    while (!flag)
    {
        x = (rand() %10)+1;
        y = (rand() %10)+1;
        if(board.getFieldInfo(x,y) <= 1)
            flag = true;
    }
    return std::make_pair(x, y);
}

std::pair <int, int> ShootingActionComputer::checkHorizontal(Board& board)
{
    for(auto elem : _unshotShip)
    {
        if (board.getFieldInfo(elem.first -1, elem.second) <= 1) return std::make_pair(elem.first -1, elem.second);
        if (board.getFieldInfo(elem.first +1, elem.second) <= 1) return std::make_pair(elem.first +1, elem.second);
    }
    return std::make_pair(-1, -1);
}

std::pair <int, int> ShootingActionComputer::checkVertical(Board& board)
{
    for(auto elem : _unshotShip)
    {
        if (board.getFieldInfo(elem.first, elem.second -1) <= 1) return std::make_pair(elem.first, elem.second -1);
        if (board.getFieldInfo(elem.first, elem.second +1) <= 1) return std::make_pair(elem.first, elem.second +1);
    }
    return std::make_pair(-1, -1);
}

void ShootingActionComputer::addUnshotShip(std::pair <int, int> shipPart)
{
    _unshotShip.push_back(shipPart);
}

void ShootingActionComputer::clearShotShip()
{
    _unshotShip.clear();
}