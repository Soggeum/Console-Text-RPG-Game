#pragma once
#include<string>
#include<iostream>
#include"Item.h"
#include"HealthPotion.h"
#include"AttackBoost.h"
using namespace std;
class Monster {
protected:
	string name;
	int hp;
	int attack;
public:
	Monster();
	virtual ~Monster()=default;
	int getHp() const;
	virtual void displayStatus() const;
	void setHp(int hp);
	int getAttack() const;
	string getName() const;
	virtual void takeDamage(int damage)=0;
	virtual Item* dropItem() = 0;
};