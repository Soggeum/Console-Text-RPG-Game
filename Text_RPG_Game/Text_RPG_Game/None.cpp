#include "None.h"

None::None(int attack)
    :CharacterState(attack,"None")
{
}

void None::Attack(Monster* mon)
{
    //1ȸ����
    cout << Character::GetInstance()->getName() << "��(��) " << mon->getName() << "��(��) �����մϴ�!" << endl;

    mon->setHp(mon->getHp()-attack);

}




