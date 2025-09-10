#pragma once
#include <string>

// ������ �������� ��ȯ ���� ���� �ذ�
class Character;

class Item {
public:
    virtual ~Item() {}

    virtual std::string getName() = 0;
    virtual int getPrice() = 0; // �������� ������ ǥ���ϱ� ���� �߰�
    virtual void use(Character* character) = 0;

    // �������� �������� �� ��, ������ �״�� �ΰ� ���纻�� �÷��̾�� �ֱ� ���� �߰�
    virtual Item* clone() = 0;
};