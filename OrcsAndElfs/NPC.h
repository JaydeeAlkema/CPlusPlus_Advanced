#pragma once

#include <iostream>
#include <string>

class NPC
{
public:
	NPC();
	virtual ~NPC();

	virtual void render() = 0;

protected:
	std::string name;
};