#include "Shop.hpp"
#include "HealthPotion.h" // �������� �� �����۵��� ����� ����
#include "AttackBoost.h"

#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::endl;

// ������: LogManager�� �ް�, �Ǹ��� ������ ��ü���� ����
Shop::Shop(LogManager* logManager) : logManager(logManager) {
    itemsForSale[0] = new HealthPotion();
    itemsForSale[1] = new AttackBoost();
    // ���⿡ ���ο� �������� �߰��� �� �ֽ��ϴ�. (ITEM_COUNT�� �Բ� ����)
}

// �Ҹ���: �����ڿ��� new�� ������ �����۵��� �޸𸮸� ����
Shop::~Shop() {
    for (int i = 0; i < ITEM_COUNT; ++i) {
        if (itemsForSale[i] != nullptr) {
            delete itemsForSale[i];
        }
    }
}

// ���� ���� �Լ�
void Shop::Begin(Character* player) {
    while (true) {
        system("cls");
        cout << "���� ����!" << endl;
        cout << "���� ���� �ݾ�: " << player->GetGold() << " Gold" << endl;
        cout << "--------------------------" << endl;
        cout << "1. ������ ����" << endl;
        cout << "2. ������ �Ǹ�" << endl;
        cout << "0. ���� ������" << endl;
        cout << "--------------------------" << endl;
        cout << "��ȣ �Է�: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cout << "\n[����] �߸��� �Է��Դϴ�. ���ڸ� �Է����ּ���.\n" << endl;
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
            cout << "\n���� ����\n" << endl;
            return; // �Լ� ����
        default:
            cout << "\n[����] �߸��� ��ȣ�Դϴ�. �ٽ� �������ּ���.\n" << endl;
            system("pause");
            break;
        }
    }
}
void Shop::sellLoop(Character* player)
{
    while (true) {
        system("cls");
        cout << "== ������ �Ǹ� ==" << endl;
        cout << "���� ���� �ݾ�: " << player->GetGold() << " Gold" << endl;
        cout << "--------------------------" << endl;

        player->showInventory(); // �÷��̾� �κ��丮 ǥ��

        if (player->GetItemFromInventory(0) == nullptr) { // �κ��丮�� ������� Ȯ��
            cout << "�Ǹ��� �������� �����ϴ�." << endl;
            system("pause");
            break; // �Ǹ� ���� ����
        }

        cout << "--------------------------" << endl;
        cout << "�Ǹ��� �������� ��ȣ�� �����ϼ��� (0�� �Է� �� �ڷΰ���): ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cout << "\n[����] �߸��� �Է��Դϴ�. ���ڸ� �Է����ּ���.\n" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("pause");
            continue;
        }

        if (choice == 0) {
            break; // �Ǹ� ���� ����, ���� �޴��� ���ư�
        }

        int itemIndex = choice - 1;
        Item* selectedItem = player->GetItemFromInventory(itemIndex);

        if (selectedItem == nullptr) {
            cout << "\n[����] �߸��� ��ȣ�Դϴ�. �ٽ� �������ּ���.\n" << endl;
            system("pause");
        }
        else {
            int sellPrice = selectedItem->getPrice() / 4; // �Ǹ� ���� ���
            cout << "\n'" << selectedItem->getName() << "'��(��) " << sellPrice << " Gold�� �Ǹ��Ͻðڽ��ϱ�? (Y/N): ";

            char confirm;
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                string itemName = selectedItem->getName(); // ������ �̸��� �̸� ����

                player->AddGold(sellPrice); // �÷��̾�� ��� ����
                player->RemoveItemFromInventory(itemIndex); // �κ��丮���� ������ ���� (�޸� ���� ����)

                cout << "\n'" << itemName << "'��(��) �Ǹ��߽��ϴ�." << endl;
                system("pause");

            }
            else {
                cout << "\n�ǸŸ� ����߽��ϴ�." << endl;
                system("pause");
            }
        }
    }
}

// ������ ���� ����
void Shop::purchaseLoop(Character* player)
{
    while (true) {
        system("cls"); // ���� ���� ���� �� ȭ���� �����ϰ�
        cout << "== ������ ���� ==" << endl;
        cout << "���� ���� �ݾ�: " << player->GetGold() << " Gold" << endl;
        cout << "--------------------------" << endl;
        showItems();

        cout << "������ �������� ��ȣ�� �����ϼ��� (0�� �Է� �� �ڷΰ���): ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cout << "\n[����] �߸��� �Է��Դϴ�. ���ڸ� �Է����ּ���.\n" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("pause");
            continue;
        }

        if (choice == 0) {
            break; // ���� ���� ����
        }
        else if (choice < 1 || choice > ITEM_COUNT) {
            cout << "\n[����] �߸��� ��ȣ�Դϴ�. �ٽ� �������ּ���.\n" << endl;
            system("pause");
        }
        else {
            int itemIndex = choice - 1;
            Item* selectedItem = itemsForSale[itemIndex];

            // ================== ������ġ 1: selectedItem Ȯ�� ==================
            if (selectedItem == nullptr) {
                cout << "\n[ġ���� ����] ���õ� ������(selectedItem)�� nullptr�Դϴ�. Shop �����ڸ� Ȯ���ϼ���.\n" << endl;
                system("pause");
                continue; // ������ ó������
            }
            // ====================================================================

            int price = selectedItem->getPrice();

            if (player->GetGold() >= price) {
                player->UseGold(price);
                cout << "\n'" << selectedItem->getName() << "'��(��) �����߽��ϴ�." << endl;

                Item* newItem = selectedItem->clone();

                // ================== ������ġ 2: newItem (clone ���) Ȯ�� ==================
                if (newItem == nullptr) {
                    cout << "\n[ġ���� ����] ������ ����(clone) ����� nullptr�Դϴ�. " << selectedItem->getName() << "�� clone() �Լ��� Ȯ���ϼ���.\n" << endl;
                    system("pause");
                    player->AddGold(price); // ���� ��� �� ȯ��
                    continue;
                }
                // ==========================================================================

                player->AddItem(newItem);

                // ================== ������ġ 3: logManager Ȯ�� ==================
                if (logManager == nullptr) {
                    cout << "\n[���] logManager�� nullptr�̶� �α׸� ����� �� �����ϴ�.\n" << endl;
                }
                else {
                    logManager->setLogInput("usedMoney", price);
                    logManager->setLogInput("currBuyItem", selectedItem->getName());
                }
                // =================================================================

                system("pause"); // ���� �� ��� ����
            }
            else {
                cout << "\n[����] ��尡 �����Ͽ� �������� ������ �� �����ϴ�.\n" << endl;
                system("pause");
            }
        }
    }
}

// �Ǹ� ������ ��� ǥ��
void Shop::showItems() {
    cout << "������ ���:" << endl;
    for (int i = 0; i < ITEM_COUNT; ++i) {
        if (itemsForSale[i] != nullptr) {
            cout << i + 1 << ". " << itemsForSale[i]->getName()
                << " - " << itemsForSale[i]->getPrice() << " Gold" << endl;
        }
    }
    cout << "--------------------------" << endl;
}