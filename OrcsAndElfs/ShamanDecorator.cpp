#include "ShamanDecorator.h"

ShamanDecorator::ShamanDecorator(NPC* npc) : Decorator(npc)
{
}

ShamanDecorator::~ShamanDecorator()
{
}

void ShamanDecorator::render()
{
	Decorator::render();
	std::cout << "- Added: Shaman Decorator" << std::endl;
}
