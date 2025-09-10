#include "Orc.h"
#include "HealthPotion.h" 
#include "AttackBoost.h"
Orc::Orc(int level) {
	hp = level * (rand() % 11 + 20)*level/2;
	attack = level * (rand() % 6 + 5)*level/2;
	name = "��ũ";
}
void Orc::takeDamage(int damage){
	setHp(hp - damage);
}
Item* Orc::dropItem() {
	int r = rand() % 100;
	if (r < 30) {
		Item* item = nullptr;
		if (r % 2 == 0) {
			item = new HealthPotion();
			return item;//ü�¹���
		}
		else {
			item = new AttackBoost();
			return item;//��������
		}
	}
	return nullptr;
}