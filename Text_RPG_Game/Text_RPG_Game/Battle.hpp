#pragma once
#include "Monster.h"
#include "Slime.h"
#include "Goblin.h"
#include "Orc.h"
#include "Troll.h"
#include "BossMonster.h"
#include "GameManager.hpp"
#include "Character.h"

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