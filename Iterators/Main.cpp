#include <iostream>

#include "Module.h"
#include "Teacher.h"
#include "Student.h"

//TODO:
// fix the EC points not getting changes correctly... besides that everything works as required.

int main()
{
	//############################## VARIABLES ########################################
	Module* Module_GameDevCore = new Module("Game Development Core Module 3", 4);
	Module* Module_CPlusPlusAdvanced = new Module("C++ Advanced", 5);
	Module* Module_ProjectHybrid = new Module("Hybrid Space", 6);

	Teacher* teacher_Edwin = new Teacher("Edwin");
	Teacher* teacher_Vincent = new Teacher("Vincent");
	Teacher* teacher_Valentijn = new Teacher("Valentijn");

	Student* student_Jaydee = new Student("Jaydee");
	Student* student_Joris = new Student("Joris");
	Student* student_Merel = new Student("Merel");
	Student* student_Hicran = new Student("Hicran");
	Student* student_Danielle = new Student("Danielle");
	Student* student_Dylan = new Student("Dylan");
	Student* student_Laura = new Student("Laura");
	Student* student_Mana = new Student("Mana");
	Student* student_MichealY = new Student("Micheal. Y");
	Student* student_MichealS = new Student("Micheal. S");

	//############################## FUNCTIONS & METHODS ########################################
	// Add Teachers to the modules
	Module_CPlusPlusAdvanced->addTeacher(*teacher_Edwin);

	Module_GameDevCore->addTeacher(*teacher_Valentijn);
	Module_GameDevCore->addTeacher(*teacher_Vincent);

	Module_ProjectHybrid->addTeacher(*teacher_Valentijn);

	// Add Students to the Modules
	Module_GameDevCore->addStudent(*student_Jaydee);
	Module_GameDevCore->addStudent(*student_Mana);
	Module_GameDevCore->addStudent(*student_Joris);
	Module_GameDevCore->addStudent(*student_MichealS);
	Module_GameDevCore->addStudent(*student_MichealY);

	Module_CPlusPlusAdvanced->addStudent(*student_Jaydee);
	Module_CPlusPlusAdvanced->addStudent(*student_Mana);
	Module_CPlusPlusAdvanced->addStudent(*student_MichealS);
	Module_CPlusPlusAdvanced->addStudent(*student_MichealY);
	Module_CPlusPlusAdvanced->addStudent(*student_Dylan);

	Module_ProjectHybrid->addStudent(*student_Jaydee);
	Module_ProjectHybrid->addStudent(*student_Joris);
	Module_ProjectHybrid->addStudent(*student_Merel);
	Module_ProjectHybrid->addStudent(*student_Hicran);
	Module_ProjectHybrid->addStudent(*student_Danielle);
	Module_ProjectHybrid->addStudent(*student_Dylan);
	Module_ProjectHybrid->addStudent(*student_Laura);
	Module_ProjectHybrid->addStudent(*student_Mana);
	Module_ProjectHybrid->addStudent(*student_MichealY);
	Module_ProjectHybrid->addStudent(*student_MichealS);

	//############################## STD::COUT ########################################

	// Initial prints
	std::cout << *Module_GameDevCore << std::endl;
	std::cout << *Module_CPlusPlusAdvanced << std::endl;
	std::cout << *Module_ProjectHybrid << std::endl;

	// change EC worth of module
	Module_ProjectHybrid->changeECWorth(1);
	std::cout << *Module_ProjectHybrid << std::endl;

	// Remove student from module
	Module_ProjectHybrid->removeStudent(*student_Jaydee);
	std::cout << *Module_ProjectHybrid << std::endl;

	//############################## CLEANUP ########################################

	delete Module_GameDevCore;
	delete Module_CPlusPlusAdvanced;
	delete Module_ProjectHybrid;

	delete teacher_Edwin;
	delete teacher_Vincent;
	delete teacher_Valentijn;

	delete student_Jaydee;
	delete student_Joris;
	delete student_Merel;
	delete student_Hicran;
	delete student_Danielle;
	delete student_Dylan;
	delete student_Laura;
	delete student_Mana;
	delete student_MichealY;
	delete student_MichealS;
}
