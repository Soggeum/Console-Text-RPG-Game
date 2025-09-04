#pragma once

#include "GameManager.hpp"

class Battle
{
private:
	Character* player;
	Monster* monster;
	bool& isClear;	// 보스 처치 시 true로 변경

public:
	Battle(Character* player, bool& isClear);
	~Battle();
	bool Begin();
	bool BossBegin();

private:
	Monster* generateMonster(int level);
	BossMonster* generateBossMonster(int level);
	int printOption();	// 선택지 출력 함수
};