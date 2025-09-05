#pragma once
#include "Item.h"

class HealthPotion : public Item {
private:
	string name;
	int healthRestore;
	
public:
	HealthPotion() : name("체력 포션") , healthRestore(50) {}

	string getName() override { return name; }

	void use(Character* character) override ;
	
};