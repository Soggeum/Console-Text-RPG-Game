#pragma once
#include"CharacterState.h"

class Thief :public CharacterState
{
public:
	Thief(int attack);
	~Thief();

	// CharacterState��(��) ���� ��ӵ�
	void Attack(Monster* mon) override;
	// CharacterState��(��) ���� ��ӵ�
	//int GetAttack() override;
};

