#pragma once
#include"CharacterState.h"

class Thief :public CharacterState
{
public:
	Thief(int attack);
	~Thief();
	// CharacterState��(��) ���� ��ӵ�
	int GetAttack() override;
};

