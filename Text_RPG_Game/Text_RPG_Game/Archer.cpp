#include "Archer.h"
#include "Character.h"

Archer::Archer(int attack)
	:CharacterState(attack, "Arhcer")
{
}

void Archer::Attack(Monster* mon)
{
	for (int i = 0; i < 3; i++) {
		 mon->setHp(mon->getHp()-attack);
		 cout << "���� ���� ü��: " << mon->getHp() << endl;
	}
}




