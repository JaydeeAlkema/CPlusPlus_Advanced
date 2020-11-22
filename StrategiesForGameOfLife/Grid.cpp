#include "Grid.h"

Grid::Grid()
{
}

Grid::~Grid()
{
}

void Grid::initializeGrid()
{
	std::vector<std::vector<Cell>> newCellsGrid(width, std::vector<Cell>(height, 0));

	for (int x = 0; x < width - 1; x++)
	{
		for (int y = 0; y < height - 1; y++)
		{
			Cell cell = Cell(x + y);
			newCellsGrid[x][y] = cell;
			cells.push_back(cell);
		}
	}
}
