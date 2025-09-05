#include "Warrior.h"

Warrior::Warrior(int attack)
    :CharacterState(attack, "Warrior")
{
}

void Warrior::Attack(Monster* mon)
{
    
    // mon.GetHp()-=attack;
}
