#include <iostream>
#include "Parent.h"

Parent::Parent(std::string name) {
	this->name = name;
	std::string childName = "ChildOf" + name;
	this->child = std::make_unique<Child>(childName);
}

Parent::Parent(const Parent& other) {
	std::cout << "Parent cctor" << std::endl;
	this->name = other.name;
	this->child = std::make_unique<Child>(*other.child);
}

Parent::~Parent() {
	std::cout << "Parent dtor : " << this->name << std::endl;
}

Parent& Parent::operator=(const Parent& other) {
	std::cout << "Parent assignment" << std::endl;

	if (this == &other) return *this;

	this->name = other.name;
	this->child = std::make_unique<Child>(*other.child);

	return *this;
}

std::string Parent::getName()
{
	return this->name;
}

void Parent::removeChild()
{
	this->child.reset();
}

int Parent::getChildCount()
{
	if (this->child.get() != nullptr)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


std::ostream& operator<<(std::ostream& os, const Parent& parent) {
	os << "parent name: " << parent.name << "," << *parent.child;
	return os;
}