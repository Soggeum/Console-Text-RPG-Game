#pragma once
#include<iostream>
#include<string>
#include"Monster.h"

using namespace std;

class Monster;

class CharacterState
{
public:
	CharacterState(int attack,string state) :attack(attack),state(state) {};
	virtual void Attack(Monster* mon) = 0;
	int GetAttack();
	string GetState();
	void SetAttack(int atk);
	void AddAttack(int atk);
protected:
	int attack;
	string state;

};

