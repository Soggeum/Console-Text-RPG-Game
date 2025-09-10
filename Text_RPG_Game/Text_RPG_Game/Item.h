#pragma once
#include <string>

// 순방향 선언으로 순환 참조 문제 해결
class Character;

class Item {
public:
    virtual ~Item() {}

    virtual std::string getName() = 0;
    virtual int getPrice() = 0; // 상점에서 가격을 표시하기 위해 추가
    virtual void use(Character* character) = 0;

    // 상점에서 아이템을 팔 때, 원본은 그대로 두고 복사본을 플레이어에게 주기 위해 추가
    virtual Item* clone() = 0;
};