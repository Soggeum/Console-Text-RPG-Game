#include "AttackBoost.h"

void AttackBoost::use(Character* character)
{
	character->AddAttack(attackIncrease);
}
