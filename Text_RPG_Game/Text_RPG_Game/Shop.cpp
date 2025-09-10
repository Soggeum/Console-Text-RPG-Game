#include "Shop.hpp"
#include "HealthPotion.h" // 상점에서 팔 아이템들의 헤더를 포함
#include "AttackBoost.h"

#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::endl;

// 생성자: LogManager를 받고, 판매할 아이템 객체들을 생성
Shop::Shop(LogManager* logManager) : logManager(logManager) {
    itemsForSale[0] = new HealthPotion();
    itemsForSale[1] = new AttackBoost();
    // 여기에 새로운 아이템을 추가할 수 있습니다. (ITEM_COUNT도 함께 수정)
}

// 소멸자: 생성자에서 new로 생성한 아이템들의 메모리를 해제
Shop::~Shop() {
    for (int i = 0; i < ITEM_COUNT; ++i) {
        if (itemsForSale[i] != nullptr) {
            delete itemsForSale[i];
        }
    }
}

// 상점 메인 함수
void Shop::Begin(Character* player) {
    while (true) {
        system("cls");
        cout << "상점 입장!" << endl;
        cout << "현재 소지 금액: " << player->GetGold() << " Gold" << endl;
        cout << "--------------------------" << endl;
        cout << "1. 아이템 구매" << endl;
        cout << "2. 아이템 판매" << endl;
        cout << "0. 상점 나가기" << endl;
        cout << "--------------------------" << endl;
        cout << "번호 입력: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cout << "\n[오류] 잘못된 입력입니다. 숫자를 입력해주세요.\n" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("pause");
            continue;
        }

        switch (choice) {
        case 1:
            purchaseLoop(player);
            break;
        case 2:
            sellLoop(player);
            break;
        case 0:
            cout << "\n상점 퇴장\n" << endl;
            return; // 함수 종료
        default:
            cout << "\n[오류] 잘못된 번호입니다. 다시 선택해주세요.\n" << endl;
            system("pause");
            break;
        }
    }
}
void Shop::sellLoop(Character* player)
{
    while (true) {
        system("cls");
        cout << "== 아이템 판매 ==" << endl;
        cout << "현재 소지 금액: " << player->GetGold() << " Gold" << endl;
        cout << "--------------------------" << endl;

        player->showInventory(); // 플레이어 인벤토리 표시

        if (player->GetItemFromInventory(0) == nullptr) { // 인벤토리가 비었는지 확인
            cout << "판매할 아이템이 없습니다." << endl;
            system("pause");
            break; // 판매 루프 종료
        }

        cout << "--------------------------" << endl;
        cout << "판매할 아이템의 번호를 선택하세요 (0번 입력 시 뒤로가기): ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cout << "\n[오류] 잘못된 입력입니다. 숫자를 입력해주세요.\n" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("pause");
            continue;
        }

        if (choice == 0) {
            break; // 판매 루프 종료, 메인 메뉴로 돌아감
        }

        int itemIndex = choice - 1;
        Item* selectedItem = player->GetItemFromInventory(itemIndex);

        if (selectedItem == nullptr) {
            cout << "\n[오류] 잘못된 번호입니다. 다시 선택해주세요.\n" << endl;
            system("pause");
        }
        else {
            int sellPrice = selectedItem->getPrice() / 4; // 판매 가격 계산
            cout << "\n'" << selectedItem->getName() << "'을(를) " << sellPrice << " Gold에 판매하시겠습니까? (Y/N): ";

            char confirm;
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                string itemName = selectedItem->getName(); // 아이템 이름을 미리 저장

                player->AddGold(sellPrice); // 플레이어에게 골드 지급
                player->RemoveItemFromInventory(itemIndex); // 인벤토리에서 아이템 제거 (메모리 해제 포함)

                cout << "\n'" << itemName << "'을(를) 판매했습니다." << endl;
                system("pause");

            }
            else {
                cout << "\n판매를 취소했습니다." << endl;
                system("pause");
            }
        }
    }
}

// 아이템 구매 로직
void Shop::purchaseLoop(Character* player)
{
    while (true) {
        system("cls"); // 구매 루프 진입 시 화면을 깨끗하게
        cout << "== 아이템 구매 ==" << endl;
        cout << "현재 소지 금액: " << player->GetGold() << " Gold" << endl;
        cout << "--------------------------" << endl;
        showItems();

        cout << "구매할 아이템의 번호를 선택하세요 (0번 입력 시 뒤로가기): ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cout << "\n[오류] 잘못된 입력입니다. 숫자를 입력해주세요.\n" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("pause");
            continue;
        }

        if (choice == 0) {
            break; // 구매 루프 종료
        }
        else if (choice < 1 || choice > ITEM_COUNT) {
            cout << "\n[오류] 잘못된 번호입니다. 다시 선택해주세요.\n" << endl;
            system("pause");
        }
        else {
            int itemIndex = choice - 1;
            Item* selectedItem = itemsForSale[itemIndex];

            // ================== 안전장치 1: selectedItem 확인 ==================
            if (selectedItem == nullptr) {
                cout << "\n[치명적 오류] 선택된 아이템(selectedItem)이 nullptr입니다. Shop 생성자를 확인하세요.\n" << endl;
                system("pause");
                continue; // 루프의 처음으로
            }
            // ====================================================================

            int price = selectedItem->getPrice();

            if (player->GetGold() >= price) {
                player->UseGold(price);
                cout << "\n'" << selectedItem->getName() << "'을(를) 구매했습니다." << endl;

                Item* newItem = selectedItem->clone();

                // ================== 안전장치 2: newItem (clone 결과) 확인 ==================
                if (newItem == nullptr) {
                    cout << "\n[치명적 오류] 아이템 복제(clone) 결과가 nullptr입니다. " << selectedItem->getName() << "의 clone() 함수를 확인하세요.\n" << endl;
                    system("pause");
                    player->AddGold(price); // 구매 취소 및 환불
                    continue;
                }
                // ==========================================================================

                player->AddItem(newItem);

                // ================== 안전장치 3: logManager 확인 ==================
                if (logManager == nullptr) {
                    cout << "\n[경고] logManager가 nullptr이라 로그를 기록할 수 없습니다.\n" << endl;
                }
                else {
                    logManager->setLogInput("usedMoney", price);
                    logManager->setLogInput("currBuyItem", selectedItem->getName());
                }
                // =================================================================

                system("pause"); // 구매 후 잠시 멈춤
            }
            else {
                cout << "\n[오류] 골드가 부족하여 아이템을 구매할 수 없습니다.\n" << endl;
                system("pause");
            }
        }
    }
}

// 판매 아이템 목록 표시
void Shop::showItems() {
    cout << "아이템 목록:" << endl;
    for (int i = 0; i < ITEM_COUNT; ++i) {
        if (itemsForSale[i] != nullptr) {
            cout << i + 1 << ". " << itemsForSale[i]->getName()
                << " - " << itemsForSale[i]->getPrice() << " Gold" << endl;
        }
    }
    cout << "--------------------------" << endl;
}