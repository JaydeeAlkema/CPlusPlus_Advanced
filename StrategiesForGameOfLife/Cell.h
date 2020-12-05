#pragma once

class Cell
{
public:
	Cell(int ID);
	virtual ~Cell();

	int getID();
	bool isAlive();

private:
	int id = 0;
	bool alive = false;
};