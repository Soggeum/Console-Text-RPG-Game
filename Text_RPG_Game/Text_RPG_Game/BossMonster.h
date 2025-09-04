#pragma once
#include "Monster.h"
class BossMonster:public Monster
{
	BossMonster() = default;
	BossMonster(int level);
	void takeDamage(int damage) override;
	Item* dropItem() override;
};

