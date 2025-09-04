#include "CharacterState.h"


void CharacterState::SetAttack(int atk)
{
    attack = atk;
}

string CharacterState::GetState()
{
    return state;
}