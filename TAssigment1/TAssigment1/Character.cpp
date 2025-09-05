#include "Character.h"

void Character::heal(int amount)
{
	health += amount;
	if (health > MAX_HEALTH) health = MAX_HEALTH;
	cout << name << "�� ü���� " << amount << "��ŭ ȸ���Ǿ����ϴ�. ���� ü��: " << health << endl;
}

void Character::increaseAttack(int amount)
{
	attack += amount;
	cout << name << "�� ���ݷ��� " << amount << "��ŭ �����߽��ϴ�. ���� ���ݷ�: " << attack << endl;
}

void Character::showInventory()
{
	cout << "�κ��丮" << endl;
	for (size_t i = 0; i < inventory.size(); i++) {
		cout <<  i +1  << ": " << inventory[i]->getName() << endl;
	}
	cout << endl;
}

void Character::useItem(int index)
{
	if(index < 0 || index >= inventory.size()) {
		cout << "��ȿ���� ���� ���Դϴ�" << endl;
		return;
	}

	inventory[index]->use(this);
	delete inventory[index];
	inventory.erase(inventory.begin() + index);

}

void Character::addItem(Item* item)
{
	inventory.push_back(item);
	cout << item->getName() << "��(��) ȹ���߽��ϴ�." << endl;
}
