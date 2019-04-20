#pragma once

struct Position 
{
	int x;
	int y;

	bool operator ==(const Position& other) const;
	bool operator !=(const Position& other) const;
	bool operator < (const int i) const;
	bool operator > (const int i) const;
};