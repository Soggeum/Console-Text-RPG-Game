#pragma once
#include "Item.h"

class HealthPotion : public Item {
private:
	string name;
	int healthRestore;
	
public:
	HealthPotion() : name("ü�� ����") , healthRestore(50) {}

	string getName() override { return name; }

	void use(Character* character) override ;
	
};