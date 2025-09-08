#pragma once
#include"CharacterState.h"
#include"Character.h"
class Warrior :public CharacterState
{
public:
	Warrior(int attack);
	~Warrior();
	void Attack(Monster* mon) override;
};

