#include "LogManager.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

LogManager::LogManager(){
	logInput["shopCount"] = "0";
	logInput["usedMoney"] = "0";
	logInput["monsterCount"] = "0";
	logInput["currUseItem"] = "없음";
	logInput["currBuyItem"] = "없음";
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
		cout << "1. 들린 상점 횟수" << endl;		// Key값 : shopCount, Value값 : int
		cout << "2. 상점에서 사용한 금액" << endl;	// Key값 : usedMoney, Value값 : int
		cout << "3. 잡은 몬스터 수" << endl;		// Key값 : monsterCount, Value값 : int
		cout << "4. 최근 사용한 아이템" << endl;	// Key값 : currUseItem, Value값 : string
		cout << "5. 최근 구매한 아이템" << endl;	// Key값 : currBuyItem, Value값 : string
		cout << "6. 메인 메뉴로 돌아가기" << endl;	// 메인 화면으로 돌아가기
		cout << "원하는 옵션의 숫자를 입력해주세요 : ";

		cin >> optionSellect;

		if (optionSellect == 1) {
			cout << "들린 상점 횟수 : " << logInput["shopCount"] << "회" << endl;
		}
		else if (optionSellect == 2) {
			cout << "상점에서 사용한 금액 : " << logInput["usedMoney"] << "G" << endl;
		}
		else if (optionSellect == 3) {
			cout << "잡은 몬스터 수 : " << logInput["mosterCount"] << "마리" << endl;
		}
		else if (optionSellect == 4) {
			cout << "최근 사용한 아이템 : " << logInput["currUseItem"] << endl;
		}
		else if (optionSellect == 5) {
			cout << "최근 구매한 아이템 : " << logInput["currBuyItem"] << endl;
		}
		else if (optionSellect == 6) {
			cout << "메인 메뉴로 돌아갑니다" << endl;
			break;
		}
		else {
			cout << "잘못된 입력 방식입니다. 다시 입력해주세요 : " << endl;
		}

		system("cls");
	}
}

