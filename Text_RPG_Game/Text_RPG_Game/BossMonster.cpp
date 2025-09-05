#include "BossMonster.h"
BossMonster::BossMonster(int level) {
	hp = (level * (rand() % 11 + 20)) * 1.5;//�Ҽ�������
	attack = (level * (rand() % 6 + 5))*1.5;//�Ҽ�������
	name = "�巡��";
}
void BossMonster::takeDamage(int damage) {
	setHp(hp - damage);
}
void BossMonster::displayStatus() const {
	cout << "\033[31m �������� " << name << "�� ü��: " << hp << ", ���ݷ� : " << attack << "\033[0m" << endl;//���� cmd���� ������
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