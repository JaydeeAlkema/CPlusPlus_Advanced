#include "Student.h"

Student::Student(std::string name)
{
	this->name = name;
}

Student::~Student()
{

}

const std::string Student::getName()
{
	return this->name;
}
