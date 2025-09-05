#pragma once
#include"Monster.h"
class Goblin:public Monster
{
public:
	Goblin() = default;
	Goblin(int level);
	void takeDamage(int damage) override;
	Item* dropItem()	override;
};

