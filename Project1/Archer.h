#pragma once
#include"CharacterState.h"

class Archer :public CharacterState
{
	
public:
	Archer(int attack);
	~Archer();
	
	// CharacterState을(를) 통해 상속됨
	void Attack(Monster* mon) override;
};

