#include "Troll.h"
Troll::Troll(int level) {
	hp = level * rand() % 11 + 20;
	attack = level * rand() % 6 + 5;
	name = "슬라임";
}
void Troll::takeDamage(int damage) {
	setHp(hp - damage);
}
Item* Troll::dropItem() {
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