#include "Thief.h"

Thief::Thief(int attack)
    :CharacterState(attack, "Thief")
{
}

void Thief::Attack(Monster* mon)
{
	//5ȸ����
	cout << "Thief����" << endl;
	for (int i = 0; i < 5; i++) {
		mon->setHp(mon->getHp() - attack);
		cout << "���� ���� ü��: " << mon->getHp() << endl;
	}
}


