#pragma once
#include"CharacterState.h"

class None : public CharacterState
{
public:
	None(int attack);
	// CharacterState��(��) ���� ��ӵ�
	int GetAttack() override;
private:
};

