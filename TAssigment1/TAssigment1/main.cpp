#include <iostream>
#include "Character.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

using namespace std;

int main() {
	Character hero("Hero");

	while (1) {

		cout << "==========================" << endl;
		cout << "1. 인벤토리 보기" << endl;
		cout << "2. 아이템 생성" << endl;
		cout << "3. 아이템 사용" << endl;
		cout << "4. 종료" << endl;
		cout << "==========================" << endl;

		cout << "선택: ";
		int choice;
		cin >> choice;
		system("cls");

		switch (choice) {
		case 1:
			hero.showInventory();
			break;
		case 2:
			cout << "1. 체력 포션" << endl;
			cout << "2. 공격력 부스트" << endl;
			cout << "선택: ";
			int itemChoice;
			cin >> itemChoice;
			if (itemChoice == 1) {
				Item* potion = new HealthPotion();
				hero.addItem(potion);
			}
			else if (itemChoice == 2) {
				Item* boost = new AttackBoost();
				hero.addItem(boost);
			}
			else {
				cout << "유효하지 않은 선택입니다." << endl;
			}
			break;
		case 3:
			hero.showInventory();
			cout << "사용할 아이템 번호: ";
			int index;
			cin >> index;
			hero.useItem(index - 1);
			break;
		case 4:
			return 0;
		default:
			cout << "유효하지 않은 선택입니다." << endl;
		}


	}

	return 0;
}