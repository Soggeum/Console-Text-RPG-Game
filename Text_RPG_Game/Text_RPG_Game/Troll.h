#pragma once
#include"Monster.h"
class Troll:public Monster
{
public:
	Troll() = default;
	Troll(int level);
	void takeDamage(int damage) override;
	Item* dropItem() override;
};

