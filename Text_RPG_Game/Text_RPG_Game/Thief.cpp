#include "Thief.h"

Thief::Thief(int attack)
    :CharacterState(attack, "Thief")
{
}

void Thief::Attack(Monster* mon)
{
	//5ȸ����
	for (int i = 0; i < 5; i++) {
		cout << Character::GetInstance()->getName() << "��(��) " << mon->getName() << "��(��) �����մϴ�!" << endl;

		mon->setHp(mon->getHp() - attack);
		cout << "���� ���� ü��: " << mon->getHp() << endl;
		if (mon->getHp() <= 0) {
			break;
		}
	}
}


