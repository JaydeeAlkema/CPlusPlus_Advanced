#include "Module.h"

Module::Module(std::string name, int ec)
{
	this->name = name;
	this->ecWorth = ec;
}

Module::~Module()
{
}

void Module::addStudent(Student& student)
{
	student.addModule(*this);
	this->moduleStudents.push_back(student);
}

void Module::removeStudent(Student& student)
{
	student.removeModule(*this);
	this->moduleStudents.remove(student);
}

void Module::addTeacher(Teacher& teacher)
{
	this->moduleTeachers.push_back(teacher);
}

void Module::removeTeacher(Teacher& teacher)
{
	this->moduleTeachers.remove(teacher);
}

int Module::getECWorth()
{
	return this->ecWorth;
}

void Module::changeECWorth(int EC)
{
	this->ecWorth = EC;
}

std::ostream& operator<<(std::ostream& os, const Module& module)
{
	std::list<Teacher> teachers = module.moduleTeachers;
	std::list<Student> students = module.moduleStudents;

	int teacherIndex = 1;
	int studentIndex = 1;

	std::cout << "MODULE: " << module.name << " | " << "EC Worth: " << module.ecWorth << std::endl;
	os << "\nModule Teachers: " << std::endl;
	for (std::list<Teacher>::iterator it = teachers.begin(); it != teachers.end(); it++)
	{
		Teacher teacher = *it;
		os << teacherIndex << ". " << teacher.getName() << std::endl;

		teacherIndex++;
	}

	os << "\nModule Students: " << std::endl;
	for (std::list<Student>::iterator it = students.begin(); it != students.end(); it++)
	{
		Student student = *it;
		os << studentIndex << ". " << student.getName() << ", EC: " << student.getTotalEC() << std::endl;

		studentIndex++;
	}

	std::cout << "#####################################################" << std::endl;

	return os;
}

bool operator==(const Module& lhs, const Module& rhs)
{
	return lhs.name == rhs.name;
}
