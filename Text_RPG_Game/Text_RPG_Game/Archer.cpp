#include "Archer.h"

Archer::Archer(int attack)
	:CharacterState(attack, "Arhcer")
{
}

void Archer::Attack(Monster* mon)
{
	for (int i = 0; i < 3; i++) {
		cout << Character::GetInstance()->getName() << "��(��) " << mon->getName() << "��(��) �����մϴ�!"<<endl;

		mon->setHp(mon->getHp() - attack);
		cout << "���� ���� ü��: " << mon->getHp() << endl;

		if (mon->getHp() <= 0) {
			break;
		}
	}
}
