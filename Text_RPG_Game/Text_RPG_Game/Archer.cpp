#include "Archer.h"

Archer::Archer(int attack)
	:CharacterState(attack, "Arhcer")
{
}

void Archer::Attack(Monster* mon)
{
	for (int i = 0; i < 3; i++) {
		cout << Character::GetInstance()->getName() << "이(가) " << mon->getName() << "을(를) 공격합니다!"<<endl;

		mon->setHp(mon->getHp() - attack);
		cout << "현재 몬스터 체력: " << mon->getHp() << endl;

		if (mon->getHp() <= 0) {
			break;
		}
	}
}
