#include "None.h"

None::None(int attack)
    :CharacterState(attack,"None")
{
}

void None::Attack(Monster* mon)
{
    //1ȸ����
    cout << "none ����" << endl;
    // mon.GetHp()-=attack;

}




