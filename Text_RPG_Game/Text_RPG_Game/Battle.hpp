#pragma once

#include "GameManager.hpp"

class Battle
{
private:
	Character* player;
	Monster* monster;
	bool& isClear;	// ���� óġ �� true�� ����

public:
	Battle(Character* player, bool& isClear);
	~Battle();
	bool Begin();
	bool BossBegin();

private:
	Monster* generateMonster(int level);
	BossMonster* generateBossMonster(int level);
	int printOption();	// ������ ��� �Լ�
};