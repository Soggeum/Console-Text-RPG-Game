#pragma once
#include"CharacterState.h"
#include"Character.h"
class Archer :public CharacterState
{
	
public:
	Archer(int attack);
	~Archer();
	
	// CharacterState��(��) ���� ��ӵ�
	void Attack(Monster* mon) override;
};

