#include "Thief.h"

Thief::Thief(int attack)
    :CharacterState(attack, "Thief")
{
}

int Thief::GetAttack()
{
    return attack;
}
