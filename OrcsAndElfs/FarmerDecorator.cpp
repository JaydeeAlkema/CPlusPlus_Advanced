#include "FarmerDecorator.h"

FarmerDecorator::FarmerDecorator(NPC* npc) : Decorator(npc)
{
}

FarmerDecorator::~FarmerDecorator()
{
}

void FarmerDecorator::render()
{
	Decorator::render();
	std::cout << "- Added: Farmer Decorator" << std::endl;
}
