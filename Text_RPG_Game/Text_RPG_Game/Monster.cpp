#include "Monster.h"
#include "HealthPotion.h" 
#include "AttackBoost.h"
Monster::Monster() {
	name = "몬스터";
	hp = 100;
	attack = 10;
}
int Monster::getAttack() const{
	return attack;
}
int Monster::getHp() const{
	return hp;
}
string Monster::getName() const{
	return name;
}
void Monster::setHp(int hp) {
	if (hp < 0) {
		hp = 0;
	}
	this->hp = hp;
}
void Monster::displayStatus() const {
	cout << name << "의 체력: " << hp << ", 공격력 : " << attack << endl;
}