#pragma once
#include"Character.h"

class None : public CharacterState
{
public:
	None(int attack);
	// CharacterState��(��) ���� ��ӵ�
	void Attack(Monster* mon) override;

private:
	// CharacterState��(��) ���� ��ӵ�
};

