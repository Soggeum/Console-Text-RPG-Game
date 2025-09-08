#pragma once
#include<iostream>
#include<vector>
#include<string>
#include "CharacterState.h"
#include "Archer.h"
#include "None.h"
#include "Thief.h"
#include "Warrior.h"
#include "Item.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

using namespace std;

class Character 
{
public:

	static Character* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new Character();
		}
		return instance;
	}

	static void Destroy()
	{
		if (instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}
		
	}

	
	int GetHP();
	string getName() { return names; }
	int GetEXP() { return experience; }
	int GetGold() { return gold; }
	//플레이어 공격력 반환
	int GetAttack();
	//플레이어가 몬스터 공격
	void Attack(Monster* mon);
	void TakeDamage(int dmg);
	void LevelUp();
	void PrintStat();
	void UseGold(int value);
	void SetName();
	bool IsDead();
	int GetLevel();
	void SetHp(int dmg);

	void showInventory();
	void UseItem(int index);
	void AddHp(int hp);
	void AddAttack(int atk);
	void AddItem(Item* item);

	void GetReward(int money,int exp);

	void LevelUpCheck();

	//전직
	void ClassChange();
private:
	Character();
	~Character();
	static Character* instance;
	string names;
	int level;
	int health;
	int maxHealth;
	const int maxLevel = 10;
	const int levelupExp = 100;
	int experience;
	int gold;
	vector<Item*> inventory;
	CharacterState* state;
};

