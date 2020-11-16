#include "Orc.h"

Orc::Orc(std::string name)
{
	this->name = name;
}

Orc::~Orc()
{
}

void Orc::render()
{
	std::cout << "NPC-Orc: " << this->name << std::endl;
}
