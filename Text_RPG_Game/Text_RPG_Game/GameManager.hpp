#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>    // time
#include <memory>

#include "Monster.h"
#include "Battle.hpp"
#include "Shop.hpp"
#include "Character.hpp"


using namespace std;

class GameManager
{
private:
	bool isClear;
	Character* player;
	Shop* shop;

public:
	GameManager();
	~GameManager();
	void BeginGame();

private:
	Character* getCharacter(string name);
	void visitShop(Character* player);
};