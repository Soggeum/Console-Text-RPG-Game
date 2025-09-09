#pragma once
#include "Item.h"
#include "Character.h"
#include "LogManager.h"

class Shop {
public:
    // 생성 시 LogManager를 받아와야 로그 기록 가능
    Shop(LogManager* logManager);
    ~Shop(); // 소멸자에서 동적 할당된 메모리 해제

    // 상점의 메인 로직을 시작하는 함수
    void Begin(Character* player);

private:
    static const int ITEM_COUNT = 2; // 판매할 아이템 종류의 수 (예시)
    Item* itemsForSale[ITEM_COUNT];  // 다형성을 이용해 모든 아이템을 Item*로 관리
    LogManager* logManager;          // 로그 기록을 위한 포인터

    void purchaseLoop(Character* player);
    void showItems();
    void sellLoop(Character* player);     // 판매 루프
};