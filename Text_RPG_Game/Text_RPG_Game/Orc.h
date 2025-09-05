#pragma once
#include "Monster.h"
class Orc:public Monster
{
public:
	Orc() = default;
	Orc(int level);
	void takeDamage(int damage) override;
//	Item* dropItem()	override;
};

