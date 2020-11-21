#pragma once

#include <iostream>
#include <string>
#include <list>

class Module;

class Student
{
public:
	Student(std::string name);
	virtual ~Student();

	const std::string getName();

	int getTotalEC();

	void addModule(Module& moduletoAdd);
	void removeModule(Module& moduleToRemove);

	friend bool operator==(const Student& lhs, const Student& rhs);

private:
	std::string name = "";
	int totalEC = 0;

	std::list<Module> studentModules;
};