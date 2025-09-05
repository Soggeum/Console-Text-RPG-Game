#include "AttackBoost.h"
#include "Character.h"

void AttackBoost::use(Character* character)
{
	character->increaseAttack(attackIncrease);
}
