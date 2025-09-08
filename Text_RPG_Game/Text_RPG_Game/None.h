#pragma once
#include"Character.h"

class None : public CharacterState
{
public:
	None(int attack);
	// CharacterState을(를) 통해 상속됨
	void Attack(Monster* mon) override;

private:
	// CharacterState을(를) 통해 상속됨
};

