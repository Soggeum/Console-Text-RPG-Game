#include "Warrior.h"

Warrior::Warrior(int attack)
    :CharacterState(attack, "Warrior")
{
}

int Warrior::GetAttack()
{
    return attack;
}
