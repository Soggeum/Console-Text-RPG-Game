#pragma once
#include "Item.h"
#include "Character.h"

class HealthPotion : public Item {
private:
	std::string name;
	int price;
	int healthRestore;

public:
	HealthPotion() : name("체력 포션"), price(30), healthRestore(50) {}

	std::string getName() override { return name; }
	int getPrice() override { return price; }
	void use(Character* character) override;
	Item* clone() override { return new HealthPotion(*this); }
};