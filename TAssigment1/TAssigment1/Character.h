#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Character {
private:
	string name;
	int health;
	int MAX_HEALTH = 200;
	int attack;
	vector<Item*> inventory;
public:
	Character(string name) {
		this->name = name;
		health = 100;
		attack = 10;
	}

	void heal(int amount);

	void increaseAttack(int amount);

	void showInventory();

	void useItem(int index);

	void addItem(Item* item);

};