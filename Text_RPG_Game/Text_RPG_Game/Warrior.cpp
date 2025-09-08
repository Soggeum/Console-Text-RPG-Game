#include "Warrior.h"

Warrior::Warrior(int attack)
    :CharacterState(attack, "Warrior")
{
}

void Warrior::Attack(Monster* mon)
{    
    cout << Character::GetInstance()->getName() << "��(��) " << mon->getName() << "��(��) �����մϴ�!" << endl;
    mon->setHp(mon->getHp() - attack);
    cout << "���� ���� ü��: " << mon->getHp() << endl;

}
