#pragma once

#include "NPC.h"

class Decorator : public NPC
{
public:
	Decorator(NPC* npc);
	virtual ~Decorator();

	virtual void render();

private:
	NPC* theNPC;
};