#pragma once

class Cell
{
public:
	Cell(int ID);
	virtual ~Cell();

	int getID();

private:
	int id = 0;

};