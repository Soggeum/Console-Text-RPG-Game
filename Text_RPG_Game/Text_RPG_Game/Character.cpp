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
		cout << "레벨이 올랐습니다!"<<level-1<<"->"<<level << endl;
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
	if (index < 0 || index >= inventory.size()) {
		cout << "유효하지 않은 값입니다" << endl;
		return;
	}

	inventory[index]->use(this);
	delete inventory[index];
	inventory.erase(inventory.begin() + index);
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
		cout << "이름 입력: ";
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

void Character::SetHp(int dmg)
{
	health = dmg;
}

void Character::AddHp(int hp)
{
	health += hp;
	if (health > maxHealth) health = maxHealth;
	cout << names << "의 체력이 " << hp << "만큼 회복되었습니다. 현재 체력: " << health << endl;
}

void Character::AddAttack(int atk)
{
	state->AddAttack(atk);
	cout << names << "의 공격력이 " << atk << "만큼 증가했습니다. 현재 공격력: " << state->GetAttack() << endl;

}

void Character::showInventory() {
	cout << "인벤토리" << endl;
	for (size_t i = 0; i < inventory.size(); i++) {
		cout << i + 1 << ": " << inventory[i]->getName() << endl;
	}
	cout << endl;
}


void Character::GetReward(int money, int exp)
{
	gold += money;
	experience += exp;	
	cout << names << "이(가) 50 EXP와 " << money << " 골드를 획득했습니다.현재 EXP : "
		<< experience << " / 100, 골드 : " << gold << endl;
	if (experience >= levelupExp) {
		LevelUp();
	}
}

void Character::LevelUpCheck()
{
	
}

void Character::AddItem(Item* item) {
	inventory.push_back(item);
	cout << item->getName() << "을(를) 획득했습니다." << endl;
}

