#pragma once
#include<string>
#include<iostream>
using namespace std;
class Item;
class HealthPotion;
class AttackBoost;
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