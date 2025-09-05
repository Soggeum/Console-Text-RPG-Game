#include "Healthpotion.h"

void HealthPotion::use(Character* character)
{
	character->AddHp(healthRestore);
}
