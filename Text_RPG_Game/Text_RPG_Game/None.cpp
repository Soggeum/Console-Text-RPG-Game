#include "None.h"

None::None(int attack)
    :CharacterState(attack,"None")
{
}

void None::Attack(Monster* mon)
{
    //1회공격
    cout << Character::GetInstance()->getName() << "이(가) " << mon->getName() << "을(를) 공격합니다!" << endl;

    mon->setHp(mon->getHp()-attack);

}




