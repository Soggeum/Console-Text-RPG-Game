#include "HealthPotion.h"
#include <iostream> 

void HealthPotion::use(Character* character)
{
    if (character) {
        std::cout << "'" << getName() << "'을(를) 사용합니다." << std::endl;

        character->AddHp(healthRestore);
    }
}