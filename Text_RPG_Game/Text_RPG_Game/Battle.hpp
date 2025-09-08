#pragma once
#include "Slime.h"
#include "Goblin.h"
#include "Orc.h"
#include "Troll.h"
#include "BossMonster.h"
#include "Character.h"
#include "LogManager.h"

class Battle
{
private:
	Character* player;
	Monster* monster;
	bool& isClear;	// ���� óġ �� true�� ����
	LogManager* logManager;

public:
	Battle(Character* player, bool& isClear, LogManager* logManager);
	~Battle();
	void Init();
	bool Begin();
	bool BossBegin();

private:
	Monster* generateMonster(int level);
	BossMonster* generateBossMonster(int level);
	int printOption();	// ������ ��� �Լ�
};