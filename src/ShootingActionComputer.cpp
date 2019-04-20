#include "../include/ShootingActionComputer.hpp"
#include <iostream>

Position ShootingActionComputer::computerShot(const Board& board) const
{
    if(!_unshotShip.empty())
    {
        // need to be simplified after implementation of correct user input
        if (_unshotShip.size() > 1)
        {
            if(_unshotShip[0].x == _unshotShip[1].x)
            {
                Position v = checkVertical(board);
                if(v.x != -1) return v;
                return checkHorizontal(board);

            }
            else if(_unshotShip[0].y == _unshotShip[1].y)
            {
                Position h = checkHorizontal(board);
                if(h.y != -1) return h;
                return checkVertical(board);
            }
        }
        else
        {
            Position h = checkHorizontal(board);
            Position v = checkVertical(board);
            return h.x > v.x ? h : v;
        }
    }
    
    bool flag = false;
    int x, y;
    while (!flag)
    {
        x = (rand() %10)+1;
        y = (rand() %10)+1;
        Position p = {x, y};
        if(board.getFieldInfo(p) == FieldStatus::FREE || board.getFieldInfo(p) == FieldStatus::SHIP)
            flag = true;
    }
    Position p = {x,y};
    return p;
}

Position ShootingActionComputer::checkHorizontal(const Board& board) const 
{
    for(auto pos : _unshotShip)
    {
        Position p1 = {pos.x - 1, pos.y};
        if ((board.getFieldInfo(p1) == FieldStatus::FREE || 
             board.getFieldInfo(p1) == FieldStatus::SHIP) 
             && p1.x != 0                       ) return p1;
        Position p2 = {pos.x + 1, pos.y};
        if ((board.getFieldInfo(p2) == FieldStatus::FREE || 
             board.getFieldInfo(p2) == FieldStatus::SHIP) 
             && p2.x != board.getFieldSize()-1  ) return p2;
    }
    Position p0 = {-1, -1};
    return p0;
}

Position ShootingActionComputer::checkVertical(const Board& board) const 
{
    for(auto pos : _unshotShip)
    {
        Position p1 = {pos.x, pos.y-1};
        if ((board.getFieldInfo(p1) == FieldStatus::FREE || 
             board.getFieldInfo(p1) == FieldStatus::SHIP) 
             && p1.y != 0                      ) return p1;
        Position p2 = {pos.x, pos.y+1};
        if ((board.getFieldInfo(p2) == FieldStatus::FREE || 
             board.getFieldInfo(p2) == FieldStatus::SHIP) 
             && p2.y != board.getFieldSize()-1 ) return p2;
    }
    Position p0 = {-1, -1};
    return p0;
}

void ShootingActionComputer::addUnshotShip(const Position& shipPart)
{
    _unshotShip.push_back(shipPart);
}

void ShootingActionComputer::clearShotShip()
{
    _unshotShip.clear();
}