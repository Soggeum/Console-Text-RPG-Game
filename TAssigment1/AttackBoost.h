#pragma once
#include "Item.h"

class AttackBoost : public Item {
private:
	string name;
	int attackIncrease;

public:
	AttackBoost() : name("Attack Boost"), attackIncrease(10) {}

	string getName() override { return name; }

	void use(Character* character) override;

};