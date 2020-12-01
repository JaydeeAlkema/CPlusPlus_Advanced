#pragma once

#include <string>
#include <ostream>
#include "Child.h"

class Parent {
public:
	Parent(std::string name);
	Parent(const Parent& other);
	virtual ~Parent();
	Parent& operator=(const Parent& other);

	friend std::ostream& operator<<(std::ostream& os, const Parent& parent);

	std::string getName();
	void removeChild();
	int getChildCount();

private:
	std::string name;
	std::unique_ptr<Child> child;
};