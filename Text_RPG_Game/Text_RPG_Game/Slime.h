#pragma once
#include"Monster.h"
class Slime:public Monster
{
public:
	Slime() = default;
	Slime(int level);
	void takeDamage(int damage) override;
	//Item* dropItem() override;
};

