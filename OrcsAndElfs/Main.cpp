/// The names used within the project are Generated from:
/// https://www.fantasynamegenerators.com/elf_names.php
/// https://www.fantasynamegenerators.com/orc_names.php

#include <iostream>

#include "Elf.h"
#include "Orc.h"
#include "FarmerDecorator.h"
#include "SoldierDecorator.h"
#include "ShamanDecorator.h"

int main()
{
	NPC* elf_Farmer = new FarmerDecorator(new Elf("Thessalia Inadan"));
	elf_Farmer->render();
	std::cout << std::endl;

	NPC* elf_Shaman = new ShamanDecorator(new Elf("Maeralya Yesmenor"));
	elf_Shaman->render();
	std::cout << std::endl;

	NPC* elf_ShamanSoliderFarmer = new ShamanDecorator(new SoldierDecorator(new FarmerDecorator(new Elf("Elred Miraqirelle"))));
	elf_ShamanSoliderFarmer->render();
	std::cout << std::endl;

	NPC* orc_Soldier = new SoldierDecorator(new Orc("Bugdurash"));
	orc_Soldier->render();
	std::cout << std::endl;

	NPC* orc_SoldierFarmer = new SoldierDecorator(new FarmerDecorator(new Orc("Tuggug")));
	orc_SoldierFarmer->render();
	std::cout << std::endl;

	delete elf_Farmer;
	delete elf_Shaman;
	delete elf_ShamanSoliderFarmer;
	delete orc_Soldier;
	delete orc_SoldierFarmer;
}
