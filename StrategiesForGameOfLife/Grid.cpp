#include "Grid.h"

Grid::Grid()
{

}

Grid::~Grid()
{
}

std::vector<Cell> Grid::getNeighbours(int x, int y)
{
	std::vector<Cell> neighbours;
	neighbours.push_back(this->cells[x - 1][y - 1].isAlive());
}

