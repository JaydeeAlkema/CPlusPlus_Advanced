#include "Elf.h"

Elf::Elf(std::string name)
{
	this->name = name;
}

Elf::~Elf()
{
	
}

void Elf::render()
{
	std::cout << "NPC-Elf: " << this->name << std::endl;
}
