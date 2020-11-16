#pragma once

#include "NPC.h"

class Orc : public NPC
{
public:
	Orc(std::string name);
	virtual ~Orc();

	void render();
};
