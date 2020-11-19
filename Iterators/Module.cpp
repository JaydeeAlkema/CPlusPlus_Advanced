#include "Module.h"

Module::Module(std::string name, int ec)
{
	this->name = name;
	this->ecWorth = ec;
}

Module::Module(Teacher teacherToAdd)
{
	moduleTeachers.push_back(teacherToAdd);
}

Module::Module(Student studentToAdd)
{
	moduleStudents.push_back(studentToAdd);
}

Module::~Module()
{
}

#pragma region Operator Overloads - TEACHER
Module Module::operator+(const Teacher& teacher) const
{
	return Module(teacher);
}

Module Module::operator-(const Teacher& teacher) const
{
	Module module = *this;

	auto it = std::find(module.moduleTeachers.begin(), module.moduleTeachers.end(), teacher);
	int index = 0;

	if (it != module.moduleTeachers.end())
	{
		index = it - module.moduleTeachers.begin();
	}

	module.moduleTeachers.erase(it);

	return module;
}

Module& Module::operator+=(const Teacher& teacher)
{
	this->moduleTeachers.push_back(teacher);
	return *this;
}
#pragma endregion

#pragma region Operator Overloads - STUDENT
Module Module::operator+(const Student& student) const
{
	return Module(student);
}

Module Module::operator-(const Student& student) const
{
	Module module = *this;

	std::vector<Student>::iterator it = std::find(module.moduleStudents.begin(), module.moduleStudents.end(), student);
	int index = 0;

	if (it != module.moduleStudents.end())
	{
		index = it - module.moduleStudents.begin();
	}

	module.moduleStudents.erase(it);

	return module;
}

Module& Module::operator+=(const Student& student)
{
	this->moduleStudents.push_back(student);
	return *this;
}
#pragma endregion

std::ostream& operator<<(std::ostream& os, const Module& module)
{
	std::vector<Teacher> teachers = module.moduleTeachers;
	std::vector<Student> students = module.moduleStudents;

	os << "\nModule Teachers= " << std::endl;
	for (std::vector<Teacher>::iterator it = teachers.begin(); it != teachers.end(); it++)
	{
		Teacher t = *it;
		os << "Teacher= " << t.getName() << std::endl;
	}

	os << "\nModule Students= " << std::endl;
	for (std::vector<Student>::iterator it = students.begin(); it != students.end(); it++)
	{
		Student st = *it;
		os << "Student= " << st.getName() << std::endl;
	}

	return os;
}
