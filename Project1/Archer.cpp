#include "Archer.h"

Archer::Archer(int attack)
	:CharacterState(attack, "Arhcer")
{
}

void Archer::Attack(Monster* mon)
{
	cout << "archer����" << endl;
	/*for (int i = 0; i < 3; i++) {
		 mon.GetHp()-=attack;
	}*/

}




