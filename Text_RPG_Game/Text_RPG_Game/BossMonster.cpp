#include "BossMonster.h"
BossMonster::BossMonster(int level) {
	hp = (level * rand() % 11 + 20) * 1.5;//소수점버림
	attack = (level * rand() % 6 + 5)*1.5;//소수점버림
	name = "보스몬스터";
}
void BossMonster::takeDamage(int damage) {
	setHp(hp - damage);
}
Item* BossMonster::dropItem() {
	int r = rand() % 100;
	if (r < 30) {
		Item* item = nullptr;
		if (r % 2 == 0) {
			item = new HealthPotion();
			return item;//체력물약
		}
		else {
			item = new AttackBoost();
			return item;//버프물약
		}
	}
}