#include "Teacher.h"

Teacher::Teacher(std::string name)
{
	this->name = name;
}

Teacher::~Teacher()
{
}

const std::string Teacher::getName()
{
	return this->name;
}

bool operator==(const Teacher& lhs, const Teacher& rhs)
{
	return lhs.name == rhs.name;
}
