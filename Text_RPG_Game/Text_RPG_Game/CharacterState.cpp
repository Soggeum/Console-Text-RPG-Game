#include "CharacterState.h"


void CharacterState::SetAttack(int atk)
{
    attack = atk;
}

string CharacterState::GetState()
{
    return state;
}

int CharacterState::GetAttack()
{
    return attack;
}

void CharacterState::AddAttack(int atk)
{
    attack += atk;
}
