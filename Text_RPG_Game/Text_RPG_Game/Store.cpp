#include "Store.h"

void Store::enterStore() {
    cout << "상점에 들어왔습니다.\n";
}

void Store::exitStore() {
    cout << "상점을 이용하지 않습니다.\n";
}

void Store::buyItem(int choice, int gold) {
    for (;;) {
		choice = -1;
	    cout << "구매할 아이템의 번호를 선택하세요 (0번 입력시 나가기)(1-" << Test_Item_List << "): ";
	    cin >> choice;
        if (choice == 0) {
            cout << "상점을 나갑니다.\n\n";
            break;
		}else if (choice < 1 || choice > Test_Item_List) {
            cout << "잘못된 선택입니다.\n\n";
        } else if (gold >= Test_Item[choice - 1].price) {
            cout << "아이템을 구매합니다: " << Test_Item[choice - 1].name << "\n";
            gold -= Test_Item[choice - 1].price;
            cout << "남은 골드: " << gold << " Gold\n\n";
        } else {
            cout << "골드가 부족합니다.\n\n";
        }
    }
}

void Store::goldCheck(int gold) {
    if (gold < 0) {
        cout << "잘못된 금액입니다.\n";
    } else {
        cout << "현재 소지 금액: " << gold << " Gold\n";
    }
}

void Store::showItems() {
    cout << "아이템 목록:\n";
    for (int i = 0; i < Test_Item_List; i++) {
        cout << i + 1 << ". " << Test_Item[i].name << " - " << Test_Item[i].price << " Gold\n";
    }
}
