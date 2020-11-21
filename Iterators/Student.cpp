#include "Student.h"
#include "Module.h"

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

int Student::getTotalEC()
{
	for (auto& it : this->studentModules)
	{
		this->totalEC += it.getECWorth();
	}

	return this->totalEC;
}

void Student::addModule(Module& moduletoAdd)
{
	this->studentModules.push_back(moduletoAdd);
}

void Student::removeModule(Module& moduleToRemove)
{
	this->studentModules.remove(moduleToRemove);
}

bool operator==(const Student& lhs, const Student& rhs)
{
	return lhs.name == rhs.name;
}
