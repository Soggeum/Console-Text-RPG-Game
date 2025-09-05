#include "Goblin.h"
#include "HealthPotion.h" 
#include "AttackBoost.h"
Goblin::Goblin(int level) {
	hp = level*(rand()%11+20);
	attack = level*(rand()%6+5);
	name = "고블린";
}
void Goblin::takeDamage(int damage) {
	setHp(hp - damage);
}
Item* Goblin::dropItem() {
	int r = rand() % 100;
	if (r < 30) {
		Item* item=nullptr;
		if (r % 2 == 0) {
			item = new HealthPotion();
			return item;//체력물약
		}
		else {
			item = new AttackBoost();
			return item;//버프물약
		}
	}
	return nullptr;
}