#include "Character.h"

void Character::heal(int amount)
{
	health += amount;
	if (health > MAX_HEALTH) health = MAX_HEALTH;
	cout << name << "의 체력이 " << amount << "만큼 회복되었습니다. 현재 체력: " << health << endl;
}

void Character::increaseAttack(int amount)
{
	attack += amount;
	cout << name << "의 공격력이 " << amount << "만큼 증가했습니다. 현재 공격력: " << attack << endl;
}

void Character::showInventory()
{
	cout << "인벤토리" << endl;
	for (size_t i = 0; i < inventory.size(); i++) {
		cout <<  i +1  << ": " << inventory[i]->getName() << endl;
	}
	cout << endl;
}

void Character::useItem(int index)
{
	if(index < 0 || index >= inventory.size()) {
		cout << "유효하지 않은 값입니다" << endl;
		return;
	}

	inventory[index]->use(this);
	delete inventory[index];
	inventory.erase(inventory.begin() + index);

}

void Character::addItem(Item* item)
{
	inventory.push_back(item);
	cout << item->getName() << "을(를) 획득했습니다." << endl;
}
