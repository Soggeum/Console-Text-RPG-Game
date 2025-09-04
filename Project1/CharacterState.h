#pragma once
#include<string>

using namespace std;

class CharacterState
{
public:
	CharacterState(int attack,string state) :attack(attack),state(state) {};
	virtual int GetAttack()=0;
	string GetState();
	void SetAttack(int atk);
protected:
	int attack;
	string state;

};

