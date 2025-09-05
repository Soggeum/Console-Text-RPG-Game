#include "Healthpotion.h"
#include "Character.h"

void HealthPotion::use(Character* character)
{
	character->heal(healthRestore);
}
