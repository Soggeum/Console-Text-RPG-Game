#pragma once
#include "Item.h"
#include "Character.h"

class AttackBoost : public Item {
private:
    std::string name;
    int price; // 가격 멤버 변수 추가
    int attackIncrease;

public:
    AttackBoost() : name("공격력 부스트"), price(50), attackIncrease(10) {}

    // Item.h의 가상 함수들을 모두 구현(override)
    std::string getName() override { return name; }
    int getPrice() override { return price; }
    void use(Character* character) override;
    Item* clone() override { return new AttackBoost(*this); } // 복사 생성자를 이용한 복제
};