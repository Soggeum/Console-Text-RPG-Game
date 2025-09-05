// teamPJ1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include "Store.h"
using namespace std;


int main() {
    int choice;   // 행동(1234 등의 숫자로 캐릭터 행동을 컨트롤 할 것 같으므로 아스키코드를 이용)
    char input;   // 문자 입력 받기
	int gold = 500; // 초기 골드 설정
    cout << "상점에 입장 하시겠습니까? (y/n)\n";
    cin >> input;

    choice = (int)input;   // 문자 → 아스키 코드 변환

	Store store;

    if (choice == 'Y' || choice == 'y') {
        store.enterStore();
        store.goldCheck(gold);
		store.showItems();
		store.buyItem(1, gold); // 예시로 첫 번째 아이템 구매 시도

    } else if (choice == 'N' || choice == 'n') {
		store.exitStore();
    }
    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
