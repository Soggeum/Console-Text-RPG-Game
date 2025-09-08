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
		cout << "원하는 옵션의 숫자를 입력해주세요" << endl;
		cout << "1. 들린 상점 횟수" << endl;		// Key값 : shopCount, Value값 : int
		cout << "2. 상점에서 사용한 금액" << endl;	// Key값 : usedMoney, Value값 : int
		cout << "3. 잡은 몬스터 수" << endl;		// Key값 : monsterCount, Value값 : int
		cout << "4. 최근 사용한 아이템" << endl;	// Key값 : currUseItem, Value값 : string
		cout << "5. 최근 구매한 아이템" << endl;	// Key값 : currBuyItem, Value값 : string
		cout << "6. 메인 메뉴로 돌아가기" << endl;	// 메인 화면으로 돌아가기

		cin >> optionSellect;

		if (optionSellect == 1) {
			cout << "들린 상점 횟수 : " << logInput[shopCount] << endl;
		}
		else if (optionSellect == 2) {
			cout << "상점에서 사용한 금액 : " << logInput[usedMoney] << endl;
		}
		else if (optionSellect == 3) {
			cout << "잡은 몬스터 수 : " << logInput[mosterCount] << endl;
		}
		else if (optionSellect == 4) {
			cout << "최근 사용한 아이템 : " << logInput[currUseItem] << endl;
		}
		else if (optionSellect == 5) {
			cout << "최근 구매한 아이템 : " << logInput[currBuyItem] << endl;
		}
		else if (optionSellect == 6) {
			cout << "메인 메뉴로 돌아갑니다" << endl;
			break;
		}
		else {
			cout << "잘못된 입력 방식입니다. 다시 입력해주세요 : " << endl;
		}
	}
}

