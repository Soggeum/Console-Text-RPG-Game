#include <algorithm>
#include "Character.h"

Character* Character::instance = nullptr;

Character::Character()
	:maxHealth(200), level(1), health(200), experience(0), gold(0)
{
	if (state == nullptr) {
		state = new None(30);
	}
}

Character::~Character()
{
	if (state != nullptr) {
		delete state;
		state = nullptr;
	}
	Destroy();
}

int Character::GetHP()
{
	return health;
}

int Character::GetAttack()
{
	return state->GetAttack();
}

void Character::Attack(Monster* mon)
{
	state->Attack(mon);
}

void Character::TakeDamage(int dmg)
{
	health -= dmg;
}

void Character::LevelUp()
{
	if (level < maxLevel) {
		++level;
		experience = experience-levelupExp;
		maxHealth = (maxHealth + (level * 20));
		state->SetAttack(state->GetAttack() + (level * 5));
		health = maxHealth;
		cout << "������ �ö����ϴ�!"<<level-1<<"->"<<level << endl;
	}
	else {
		cout << "���� �ִ�ġ ����" << endl;
		experience = 100;
	}

	if (level == 5) {
		ClassChange();
	}
}

void Character::ClassChange()
{
	int sel;
	cout << "���ϴ����� (1.�ü� 2.���� 3.����):" << endl;
	cin >> sel;
	CharacterState* newState = nullptr;
	switch (sel) {
	case 1:
		newState = new Archer(GetAttack()/3);		
		break;
	case 2:
		newState = new Thief(GetAttack() / 3);		
		break;
	case 3:
		newState = new Warrior(GetAttack());		
		break;
	}
	if (state != nullptr) {
		delete state;
		state = nullptr;
	}
	state = newState;
}

void Character::UseItem(int index)
{
	if (index < 0 || index >= inventory.size()) {
		cout << "��ȿ���� ���� ���Դϴ�" << endl;
		return;
	}

	inventory[index]->use(this);
	delete inventory[index];
	inventory.erase(inventory.begin() + index);
}

void Character::PrintStat()
{
	cout << "�̸�: " << names << endl;
	cout << "����: " << state->GetState() << endl;
	cout << "����: " << level << endl;
	cout << "����ġ: " << experience << "/" << levelupExp << endl;
	cout << "���� ü��: " << health << "/" << maxHealth << endl;
	cout << "���ݷ�: " << state->GetAttack() << endl;
	cout << "���� ���: " << gold << endl;
}

void Character::UseGold(int value)
{
	if (value > gold) {
		cout << "�ܾ׺���" << endl;
		return;
	}
	gold -= value;
}

void Character::SetName()
{
	do {
		cout << "�̸� �Է�: ";
		getline(cin, names);

	} while (names.empty() || all_of(names.begin(), names.end(), ::isspace));
}

//������ true, ��������� false
bool Character::IsDead()
{
	if (health <= 0)
		return true;
	else
		return false;
}

int Character::GetLevel()
{
	return level;
}

void Character::SetHp(int dmg)
{
	health = dmg;
}

void Character::AddHp(int hp)
{
	health += hp;
	if (health > maxHealth) health = maxHealth;
	cout << names << "�� ü���� " << hp << "��ŭ ȸ���Ǿ����ϴ�. ���� ü��: " << health << endl;
}

void Character::AddAttack(int atk)
{
	state->AddAttack(atk);
	cout << names << "�� ���ݷ��� " << atk << "��ŭ �����߽��ϴ�. ���� ���ݷ�: " << state->GetAttack() << endl;

}

void Character::showInventory() {
	cout << "�κ��丮" << endl;
	for (size_t i = 0; i < inventory.size(); i++) {
		cout << i + 1 << ": " << inventory[i]->getName() << endl;
	}
	cout << endl;
}


void Character::GetReward(int money, int exp)
{
	gold += money;
	experience += exp;	
	cout << names << "��(��) 50 EXP�� " << money << " ��带 ȹ���߽��ϴ�.���� EXP : "
		<< experience << " / 100, ��� : " << gold << endl;
	if (experience >= levelupExp) {
		LevelUp();
	}
}

void Character::LevelUpCheck()
{
	
}

void Character::AddItem(Item* item) {
	inventory.push_back(item);
	cout << item->getName() << "��(��) ȹ���߽��ϴ�." << endl;
}

