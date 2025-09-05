#include "Warrior.h"

Warrior::Warrior(int attack)
    :CharacterState(attack, "Warrior")
{
}

void Warrior::Attack(Monster* mon)
{    
    cout << "Warrior ����" << endl;
    mon->setHp(mon->getHp() - attack);
}
