#include "Thief.h"

Thief::Thief(int attack)
    :CharacterState(attack, "Thief")
{
}

void Thief::Attack(Monster* mon)
{
    //5ȸ����
    /*for (int i = 0; i < 5; i++) {
         mon.GetHp()-=attack;
    }*/
}


