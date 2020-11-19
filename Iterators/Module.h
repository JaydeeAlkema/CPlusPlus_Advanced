#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Teacher.h"
#include "Student.h"

class Module
{
public:
	Module(std::string name, int ec);
	Module(Teacher teacherToAdd);
	Module(Student studentToAdd);
	virtual ~Module();

	Module operator+(const Teacher& teacher) const;
	Module operator-(const Teacher& teacher) const;
	Module& operator+=(const Teacher& teacher);

	Module operator+(const Student& student) const;
	Module operator-(const Student& student) const;
	Module& operator+=(const Student& student);

	friend std::ostream& operator<<(std::ostream& os, const Module& module);

	//TODO: 
	//1. Add functionality to instantly add a whole vector of teachers and/or students at once.
	//2. Add functionality to remove a Teacher or Student via operator-= overload.

private:
	std::string name;
	int ecWorth;

	std::vector<Teacher> moduleTeachers;
	std::vector<Student> moduleStudents;
};