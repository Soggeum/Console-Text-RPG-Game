#pragma once
#include"CharacterState.h"

class Warrior :public CharacterState
{
public:
	Warrior(int attack);
	~Warrior();
	// CharacterState��(��) ���� ��ӵ�
	int GetAttack() override;
};

