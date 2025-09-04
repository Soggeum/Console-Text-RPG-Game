#include "None.h"

None::None(int attack)
    :CharacterState(attack,"None")
{
}

int None::GetAttack()
{
    return attack;
}



