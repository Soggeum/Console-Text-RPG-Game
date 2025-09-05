#pragma once
#include "Item.h"

class AttackBoost : public Item {
private:
	string name;
	int attackIncrease;

public:
	AttackBoost() : name("공격력 부스트"), attackIncrease(10) {}

	string getName() override { return name; }

	void use(Character* character) override;

};