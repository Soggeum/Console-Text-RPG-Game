#pragma once
#include<iostream>
#include<vector>
#include<string>
#include "CharacterState.h"
#include "Archer.h"
#include "None.h"
#include "Thief.h"
#include "Warrior.h"

using namespace std;

class Item;

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

	template <typename T>
	static void ChangeInstance() {
		delete instance;

		instance = new T();
	}
	
	int GetHP();
	//�÷��̾� ���ݷ� ��ȯ
	int GetAttack();
	void TakeDamage(int dmg);
	void LevelUp();
	void UseItem(int index);
	void PrintStat();
	void UseGold(int value);
	void SetName();
	bool IsDead();
	int GetLevel();

	//����
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

