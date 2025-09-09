#pragma once
#include "Item.h"
#include "Character.h"
#include "LogManager.h"

class Shop {
public:
    // ���� �� LogManager�� �޾ƿ;� �α� ��� ����
    Shop(LogManager* logManager);
    ~Shop(); // �Ҹ��ڿ��� ���� �Ҵ�� �޸� ����

    // ������ ���� ������ �����ϴ� �Լ�
    void Begin(Character* player);

private:
    static const int ITEM_COUNT = 2; // �Ǹ��� ������ ������ �� (����)
    Item* itemsForSale[ITEM_COUNT];  // �������� �̿��� ��� �������� Item*�� ����
    LogManager* logManager;          // �α� ����� ���� ������

    void purchaseLoop(Character* player);
    void showItems();
    void sellLoop(Character* player);     // �Ǹ� ����
};