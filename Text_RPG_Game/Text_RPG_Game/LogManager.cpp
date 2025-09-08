#include "LogManager.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

template<typename T>
LogManager<T>::LogManager(){

}

template<typename T>
void LogManager<T>::setLogInput(string logKey, T logValue){
	logInput[logKey] = logValue;
}

template<typename T>
void LogManager<T>::displayLog(){

	int optionSellect = 0;

	while(true) {
		cout << "���ϴ� �ɼ��� ���ڸ� �Է����ּ���" << endl;
		cout << "1. �鸰 ���� Ƚ��" << endl;		// Key�� : shopCount, Value�� : int
		cout << "2. �������� ����� �ݾ�" << endl;	// Key�� : usedMoney, Value�� : int
		cout << "3. ���� ���� ��" << endl;		// Key�� : monsterCount, Value�� : int
		cout << "4. �ֱ� ����� ������" << endl;	// Key�� : currUseItem, Value�� : string
		cout << "5. �ֱ� ������ ������" << endl;	// Key�� : currBuyItem, Value�� : string
		cout << "6. ���� �޴��� ���ư���" << endl;	// ���� ȭ������ ���ư���

		cin >> optionSellect;

		if (optionSellect == 1) {
			cout << "�鸰 ���� Ƚ�� : " << logInput[shopCount] << endl;
		}
		else if (optionSellect == 2) {
			cout << "�������� ����� �ݾ� : " << logInput[usedMoney] << endl;
		}
		else if (optionSellect == 3) {
			cout << "���� ���� �� : " << logInput[mosterCount] << endl;
		}
		else if (optionSellect == 4) {
			cout << "�ֱ� ����� ������ : " << logInput[currUseItem] << endl;
		}
		else if (optionSellect == 5) {
			cout << "�ֱ� ������ ������ : " << logInput[currBuyItem] << endl;
		}
		else if (optionSellect == 6) {
			cout << "���� �޴��� ���ư��ϴ�" << endl;
			break;
		}
		else {
			cout << "�߸��� �Է� ����Դϴ�. �ٽ� �Է����ּ��� : " << endl;
		}
	}
}

