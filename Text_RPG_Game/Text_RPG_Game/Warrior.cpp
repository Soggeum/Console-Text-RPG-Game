#include "Warrior.h"

Warrior::Warrior(int attack)
    :CharacterState(attack, "Warrior")
{
}

void Warrior::Attack(Monster* mon)
{    
    cout << Character::GetInstance()->getName() << "이(가) " << mon->getName() << "을(를) 공격합니다!" << endl;
    mon->setHp(mon->getHp() - attack);
    cout << "현재 몬스터 체력: " << mon->getHp() << endl;

}
