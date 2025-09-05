#include <iostream>
#include "Character.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

using namespace std;

int main() {
	Character hero("Hero");

	while (1) {

		cout << "==========================" << endl;
		cout << "1. �κ��丮 ����" << endl;
		cout << "2. ������ ����" << endl;
		cout << "3. ������ ���" << endl;
		cout << "4. ����" << endl;
		cout << "==========================" << endl;

		cout << "����: ";
		int choice;
		cin >> choice;
		system("cls");

		switch (choice) {
		case 1:
			hero.showInventory();
			break;
		case 2:
			cout << "1. ü�� ����" << endl;
			cout << "2. ���ݷ� �ν�Ʈ" << endl;
			cout << "����: ";
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
				cout << "��ȿ���� ���� �����Դϴ�." << endl;
			}
			break;
		case 3:
			hero.showInventory();
			cout << "����� ������ ��ȣ: ";
			int index;
			cin >> index;
			hero.useItem(index - 1);
			break;
		case 4:
			return 0;
		default:
			cout << "��ȿ���� ���� �����Դϴ�." << endl;
		}


	}

	return 0;
}