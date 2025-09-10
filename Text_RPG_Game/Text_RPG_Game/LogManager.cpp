#include "LogManager.h"


using namespace std;

LogManager::LogManager(){
	logInput["shopCount"] = "0";
	logInput["usedMoney"] = "0";
	logInput["monsterCount"] = "0";
	logInput["useHPCount"] = "0";
	logInput["useABCount"] = "0";
	logInput["buyHPCount"] = "0";
	logInput["buyABCount"] = "0";
	logInput["currUseItem"] = "없음";
	logInput["currBuyItem"] = "없음";
}

void LogManager::setLogInput(string logKey) {
	logInput[logKey] = to_string(stoi(logInput[logKey]) + 1);
}

void LogManager::setLogInput(string logKey, string logValue) {
	logInput[logKey] = logValue;
	if (logKey == "currUseItem") {
		if (logValue == "체력 포션") {
			logInput["useHPCount"] = to_string(stoi(logInput["useHPCount"]) + 1);
		}
		else if (logValue == "공격력 부스트") {
			logInput["useABCount"] = to_string(stoi(logInput["useABCount"]) + 1);
		}
	}
	else if (logKey == "currBuyItem") {
		if (logValue == "체력 포션") {
			logInput["buyHPCount"] = to_string(stoi(logInput["buyHPCount"]) + 1);
		}
		else if (logValue == "공격력 부스트") {
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
			system("pause");
		}
		else if (optionSellect == 2) {
			cout << "상점에서 사용한 금액 : " << logInput["usedMoney"] << " Gold" << endl;
			system("pause");
		}
		else if (optionSellect == 3) {
			cout << "잡은 몬스터 수 : " << logInput["mosterCount"] << "마리" << endl;
			system("pause");
		}
		else if (optionSellect == 4) {
			cout << "최근 사용한 아이템 : " << logInput["currUseItem"] << endl;
			system("pause");
		}
		else if (optionSellect == 5) {
			cout << "최근 구매한 아이템 : " << logInput["currBuyItem"] << endl;
			system("pause");
		}
		else if (optionSellect == 6) {
			cout << "메인 메뉴로 돌아갑니다" << endl;
			break;
		}
		else {
			cout << "잘못된 입력 방식입니다." << endl;
			system("pause");
		}
	}
}

void LogManager::displayAllLog() {
	cout << "들린 상점 횟수 : " << logInput["shopCount"] << "회" << endl;
	cout << "상점에서 사용한 금액 : " << logInput["usedMoney"] << " Gold" << endl;
	cout << "잡은 몬스터 수 : " << logInput["mosterCount"] << "마리" << endl;
	cout << endl;
	cout << "사용한 체력 포션 : " << logInput["useHPCount"] << "번" << endl;
	cout << "사용한 공격력 부스트 : " << logInput["useABCount"] << "번" << endl;
	cout << endl;
	cout << "구매한 체력 포션 : " << logInput["buyHPCount"] << "번" << endl;
	cout << "구매한 공격력 부스트 : " << logInput["buyABCount"] << "번" << endl;
}

