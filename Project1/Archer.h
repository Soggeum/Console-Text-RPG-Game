#pragma once
#include"CharacterState.h"

class Archer :public CharacterState
{
	
public:
	Archer(int attack);
	~Archer();
	
	// CharacterState��(��) ���� ��ӵ�
	void Attack(Monster* mon) override;
};

