#pragma once
#include"CharacterState.h"
#include"Character.h"
class Thief :public CharacterState
{
public:
	Thief(int attack);
	~Thief();

	// CharacterState을(를) 통해 상속됨
	void Attack(Monster* mon) override;
	// CharacterState을(를) 통해 상속됨
	//int GetAttack() override;
};

