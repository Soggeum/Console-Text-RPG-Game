#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>    // time
#include <memory>
#include "Monster.h"
#include "Shop.hpp"
#include "LogManager.h"
#include "Character.h"
#include "Battle.hpp"

using namespace std;

class GameManager
{
private:
	bool isClear;
	Character* player;
	Battle* battle;
	Shop* shop;
	LogManager* logManager;

public:
	GameManager();
	~GameManager();
	void BeginGame();

private:
	Character* getCharacter(string name);
	void visitShop(Character* player);
};