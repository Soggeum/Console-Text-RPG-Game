#pragma once
#include"CharacterState.h"

class Warrior :public CharacterState
{
public:
	Warrior(int attack);
	~Warrior();
	// CharacterState을(를) 통해 상속됨
	int GetAttack() override;
};

