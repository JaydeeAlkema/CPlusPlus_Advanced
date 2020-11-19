#include <iostream>

#include "Module.h"
#include "Teacher.h"
#include "Student.h"

int main()
{
	Module Module_GameDevCore = Module("Game Development Core Module 3", 4);
	Module Module_CPlusPlusAdvanced = Module("C++ Advanced", 5);
	Module Module_ProjectHybrid = Module("Hybrid Space", 6);

	Teacher teacher_Edwin("Edwin");
	Teacher teacher_Vincent("Vincent");
	Teacher teacher_Valentijn("Valentijn");

	Student student_Jaydee("Jaydee");

	Module_GameDevCore += teacher_Vincent;
	Module_GameDevCore += teacher_Valentijn;

	Module_CPlusPlusAdvanced += teacher_Edwin;
	Module_CPlusPlusAdvanced += student_Jaydee;

	std::cout << Module_CPlusPlusAdvanced << std::endl;
}
