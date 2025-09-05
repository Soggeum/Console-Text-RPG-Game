#include "None.h"

None::None(int attack)
    :CharacterState(attack,"None")
{
}

void None::Attack(Monster* mon)
{
    //1회공격
    cout << "none 공격" << endl;
    // mon.GetHp()-=attack;

}




