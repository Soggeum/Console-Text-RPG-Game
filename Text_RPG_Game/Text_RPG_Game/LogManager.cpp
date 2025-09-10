#include "LogManager.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

LogManager::LogManager(){
	logInput["shopCount"] = "0";
	logInput["usedMoney"] = "0";
	logInput["monsterCount"] = "0";
	logInput["currUseItem"] = "����";
	logInput["currBuyItem"] = "����";
}

void LogManager::setLogInput(string logKey) {
	logInput[logKey] = to_string(stoi(logInput[logKey]) + 1);
}

void LogManager::setLogInput(string logKey, string logValue) {
	logInput[logKey] = logValue;
}

void LogManager::setLogInput(string logKey, int logValue) {
	logInput[logKey] = to_string(stoi(logInput[logKey]) + logValue);
}

void LogManager::displayLog(){

	int optionSellect = 0;

	while(true) {
		cout << "1. �鸰 ���� Ƚ��" << endl;		// Key�� : shopCount, Value�� : int
		cout << "2. �������� ����� �ݾ�" << endl;	// Key�� : usedMoney, Value�� : int
		cout << "3. ���� ���� ��" << endl;		// Key�� : monsterCount, Value�� : int
		cout << "4. �ֱ� ����� ������" << endl;	// Key�� : currUseItem, Value�� : string
		cout << "5. �ֱ� ������ ������" << endl;	// Key�� : currBuyItem, Value�� : string
		cout << "6. ���� �޴��� ���ư���" << endl;	// ���� ȭ������ ���ư���
		cout << "���ϴ� �ɼ��� ���ڸ� �Է����ּ��� : ";

		cin >> optionSellect;

		if (optionSellect == 1) {
			cout << "�鸰 ���� Ƚ�� : " << logInput["shopCount"] << "ȸ" << endl;
		}
		else if (optionSellect == 2) {
			cout << "�������� ����� �ݾ� : " << logInput["usedMoney"] << "G" << endl;
		}
		else if (optionSellect == 3) {
			cout << "���� ���� �� : " << logInput["mosterCount"] << "����" << endl;
		}
		else if (optionSellect == 4) {
			cout << "�ֱ� ����� ������ : " << logInput["currUseItem"] << endl;
		}
		else if (optionSellect == 5) {
			cout << "�ֱ� ������ ������ : " << logInput["currBuyItem"] << endl;
		}
		else if (optionSellect == 6) {
			cout << "���� �޴��� ���ư��ϴ�" << endl;
			break;
		}
		else {
			cout << "�߸��� �Է� ����Դϴ�. �ٽ� �Է����ּ��� : " << endl;
		}

		system("cls");
	}
}

