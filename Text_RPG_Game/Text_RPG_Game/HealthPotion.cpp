#include "HealthPotion.h"
#include <iostream> 

void HealthPotion::use(Character* character)
{
    if (character) {
        std::cout << "'" << getName() << "'��(��) ����մϴ�." << std::endl;

        character->AddHp(healthRestore);
    }
}