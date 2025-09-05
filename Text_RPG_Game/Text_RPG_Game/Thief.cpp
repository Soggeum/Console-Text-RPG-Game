#include "Thief.h"

Thief::Thief(int attack)
    :CharacterState(attack, "Thief")
{
}

void Thief::Attack(Monster* mon)
{
	//5회공격
	cout << "Thief공격" << endl;
	for (int i = 0; i < 5; i++) {
		mon->setHp(mon->getHp() - attack);
		cout << "현재 몬스터 체력: " << mon->getHp() << endl;
	}
}


