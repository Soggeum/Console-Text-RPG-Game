#include "LogManager.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

LogManager::LogManager(){
	logInput["shopCount"] = "0";
	logInput["usedMoney"] = "0";
	logInput["monsterCount"] = "0";
	logInput["useHPCount"] = "0";
	logInput["useABCount"] = "0";
	logInput["buyHPCount"] = "0";
	logInput["buyABCount"] = "0";
	logInput["currUseItem"] = "����";
	logInput["currBuyItem"] = "����";
}

void LogManager::setLogInput(string logKey) {
	logInput[logKey] = to_string(stoi(logInput[logKey]) + 1);
}

void LogManager::setLogInput(string logKey, string logValue) {
	logInput[logKey] = logValue;
	if (logKey == "currUseItem") {
		if (logValue == "ü�� ����") {
			logInput["useHPCount"] = to_string(stoi(logInput["useHPCount"]) + 1);
		}
		else if (logValue == "���ݷ� �ν�Ʈ") {
			logInput["useABCount"] = to_string(stoi(logInput["useABCount"]) + 1);
		}
	}
	else if (logKey == "currBuyItem") {
		if (logValue == "ü�� ����") {
			logInput["buyHPCount"] = to_string(stoi(logInput["buyHPCount"]) + 1);
		}
		else if (logValue == "���ݷ� �ν�Ʈ") {
			logInput["buyABCount"] = to_string(stoi(logInput["buyABCount"]) + 1);
		}
	}
}

void LogManager::setLogInput(string logKey, int logValue) {
	logInput[logKey] = to_string(stoi(logInput[logKey]) + logValue);
}

void LogManager::displayLog(){

	int optionSellect = 0;

	while(true) {
		system("cls");
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
			system("pause");
		}
		else if (optionSellect == 2) {
			cout << "�������� ����� �ݾ� : " << logInput["usedMoney"] << " Gold" << endl;
			system("pause");
		}
		else if (optionSellect == 3) {
			cout << "���� ���� �� : " << logInput["mosterCount"] << "����" << endl;
			system("pause");
		}
		else if (optionSellect == 4) {
			cout << "�ֱ� ����� ������ : " << logInput["currUseItem"] << endl;
			system("pause");
		}
		else if (optionSellect == 5) {
			cout << "�ֱ� ������ ������ : " << logInput["currBuyItem"] << endl;
			system("pause");
		}
		else if (optionSellect == 6) {
			cout << "���� �޴��� ���ư��ϴ�" << endl;
			system("pause");
			break;
		}
		else {
			cout << "�߸��� �Է� ����Դϴ�." << endl;
			system("pause");
		}
	}
}

void LogManager::displayAllLog() {
	cout << "�鸰 ���� Ƚ�� : " << logInput["shopCount"] << "ȸ" << endl;
	cout << "�������� ����� �ݾ� : " << logInput["usedMoney"] << " Gold" << endl;
	cout << "���� ���� �� : " << logInput["mosterCount"] << "����" << endl;
	cout << endl;
	cout << "����� ü�� ���� : " << logInput["useHPCount"] << "��" << endl;
	cout << "����� ���ݷ� �ν�Ʈ : " << logInput["useABCount"] << "��" << endl;
	cout << endl;
	cout << "������ ü�� ���� : " << logInput["buyHPCount"] << "��" << endl;
	cout << "������ ���ݷ� �ν�Ʈ : " << logInput["buyABCount"] << "��" << endl;
}

