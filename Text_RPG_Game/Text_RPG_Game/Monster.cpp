#include "Monster.h"
Monster::Monster() {
	name = "∏ÛΩ∫≈Õ";
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