
#include "../include/Position.hpp"

bool Position::operator ==(const Position& other) const 
{
	return (this->x == other.x) && (this->y == other.y);
}

bool Position::operator !=(const Position& other) const 
{
	return !(*this == other);
}

bool Position::operator < (const int i) const
{
	return (this->x < i) && (this->y < i);
}
bool Position::operator > (const int i) const
{
	return (this->x > i) && (this->y > i);
}