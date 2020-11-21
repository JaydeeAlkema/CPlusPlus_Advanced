#pragma once

#include <iostream>
#include <string>

class Teacher
{
public:
	Teacher(std::string name);
	virtual ~Teacher();

	const std::string getName();

	friend bool operator==(const Teacher& lhs, const Teacher& rhs);

private:
	std::string name = "";
};