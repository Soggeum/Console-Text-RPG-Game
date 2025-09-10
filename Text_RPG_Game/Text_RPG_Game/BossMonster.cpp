#include "BossMonster.h"
#include "HealthPotion.h" 
#include "AttackBoost.h"
BossMonster::BossMonster(int level) {

	hp = (level * (rand() % 11 + 20)) * level;
	attack = (level * (rand() % 6 + 5))*level/2;
	name = "Dragon";
}
void BossMonster::takeDamage(int damage) {
	setHp(hp - damage);
}
void BossMonster::displayStatus() const {
	cout << "\033[31m보스몬스터 " << name << "의 체력: " << hp << ", 공격력 : " << attack << "\033[0m" << endl;//구형 cmd제외 빨간색
}
Item* BossMonster::dropItem() {
	int r = rand() % 100;
	if (r < 30) {
		Item* item = nullptr;
		if (r % 2 == 0) {
			item = new HealthPotion();
		  return item;
		}
		else {
			item = new AttackBoost();
			return item;
		}
	}
	return nullptr;
}