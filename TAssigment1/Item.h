#pragma once
#include <iostream>
#include <string>

using namespace std;

class Character;

class Item {
public:
	virtual string getName() = 0;
	virtual void use(Character* character) = 0;
};