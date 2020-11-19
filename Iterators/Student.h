#pragma once

#include <string>

class Student
{
public:
	Student(std::string name);
	~Student();

	const std::string getName();

private:
	std::string name;
};