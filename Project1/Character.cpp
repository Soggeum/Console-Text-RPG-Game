#include <algorithm>
#include "Character.h"

Character* Character::instance = nullptr;

Character::Character()
	:maxHealth(100), level(1), health(200), experience(0), gold(0)
{
	if (state == nullptr) {
		state = new None(30);
	}
	SetName();	
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
		cout << "�̸� �Է�: " << endl;
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

void Character::GetReward(int money, int exp)
{
	gold += money;
	experience += exp;
	if (experience >= levelupExp) {
		LevelUp();
	}
}
