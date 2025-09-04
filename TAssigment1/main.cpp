#include <iostream>
#include "Character.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

using namespace std;

int main() {
	Character hero("Hero");
	// 아이템 생성
	Item* potion = new HealthPotion();
	Item* boost = new AttackBoost();
	// 아이템을 인벤토리에 추가
	hero.useItem(0); // 유효하지 않은 값입니다
	// 아이템 사용
	hero.useItem(0); // 유효하지 않은 값입니다
	// 메모리 해제
	delete potion;
	delete boost;
	return 0;
}