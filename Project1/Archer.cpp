#include "Archer.h"

Archer::Archer(int attack)
    :CharacterState(attack, "Arhcer")
{
}

int Archer::GetAttack()
{
    return attack;
}
