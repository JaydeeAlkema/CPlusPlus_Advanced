#include "Cell.h"

Cell::Cell(int ID)
{
	this->id = ID;
}

Cell::~Cell()
{
}

int Cell::getID()
{
	return this->id;
}