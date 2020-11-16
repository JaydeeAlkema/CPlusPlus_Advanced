#include "SoldierDecorator.h"

SoldierDecorator::SoldierDecorator(NPC* npc) : Decorator(npc)
{
}

SoldierDecorator::~SoldierDecorator()
{
}

void SoldierDecorator::render()
{
	Decorator::render();
	std::cout << "- Added: Soldier Decorator" << std::endl;
}
