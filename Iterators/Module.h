#pragma once

#include <iostream>
#include <string>
#include <list>

#include "Teacher.h"
#include "Student.h"

class Module
{
public:
	Module(std::string name, int ec);
	virtual ~Module();

	void addStudent(Student& student);
	void removeStudent(Student& student);

	void addTeacher(Teacher& teacher);
	void removeTeacher(Teacher& teacher);

	int getECWorth();
	void changeECWorth(int EC);

	friend std::ostream& operator<<(std::ostream& os, const Module& module);
	friend bool operator==(const Module& lhs, const Module& rhs);

private:
	std::string name = "";
	int ecWorth = 0;

	std::list<Teacher> moduleTeachers;
	std::list<Student> moduleStudents;
};