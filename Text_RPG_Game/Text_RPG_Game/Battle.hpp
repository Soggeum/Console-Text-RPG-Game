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
	bool& isClear;	// 보스 처치 시 true로 변경
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
	int printOption();	// 선택지 출력 함수
};