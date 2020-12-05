#pragma once

#include <vector>
#include <iostream>

#include "Cell.h"

class Grid
{
public:
	Grid();
	virtual ~Grid();

	std::vector<Cell> getNeighbours(int posX, int posY);

private:
	Cell cells[25][25];
};