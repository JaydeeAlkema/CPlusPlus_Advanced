#pragma once

#include <vector>
#include <list>
#include <iostream>

#include "Cell.h"

class Grid
{
public:
	Grid();
	virtual ~Grid();

	void initializeGrid();

private:
	int width = 25;
	int height = 25;

	std::list<Cell> cells;
};