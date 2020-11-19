#pragma once

#include <string>

class Teacher
{
public:
	Teacher(std::string name);
	~Teacher();

	const std::string getName();

private:
	std::string name;
};