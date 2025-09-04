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
		cout << "레벨 최대치 도달" << endl;
		experience = 100;
	}

	if (level == 5) {
		ClassChange();
	}
}

void Character::ClassChange()
{
	int sel;
	cout << "원하는직업 (1.궁수 2.도적 3.전사):" << endl;
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
	cout << "이름: " << names << endl;
	cout << "직업: " << state->GetState() << endl;
	cout << "레벨: " << level << endl;
	cout << "경험치: " << experience << "/" << levelupExp << endl;
	cout << "현재 체력: " << health << "/" << maxHealth << endl;
	cout << "공격력: " << state->GetAttack() << endl;
	cout << "소유 골드: " << gold << endl;
}

void Character::UseGold(int value)
{
	if (value > gold) {
		cout << "잔액부족" << endl;
		return;
	}
	gold -= value;
}

void Character::SetName()
{
	do {
		cout << "이름 입력: " << endl;
		getline(cin, names);

	} while (names.empty() || all_of(names.begin(), names.end(), ::isspace));
}

//죽으면 true, 살아있으면 false
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
