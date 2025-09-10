#pragma once
#include "Item.h"
#include "Character.h"

class AttackBoost : public Item {
private:
    std::string name;
    int price; // ���� ��� ���� �߰�
    int attackIncrease;

public:
    AttackBoost() : name("���ݷ� �ν�Ʈ"), price(50), attackIncrease(10) {}

    // Item.h�� ���� �Լ����� ��� ����(override)
    std::string getName() override { return name; }
    int getPrice() override { return price; }
    void use(Character* character) override;
    Item* clone() override { return new AttackBoost(*this); } // ���� �����ڸ� �̿��� ����
};