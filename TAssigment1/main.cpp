#include <iostream>
#include "Character.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

using namespace std;

int main() {
	Character hero("Hero");
	// ������ ����
	Item* potion = new HealthPotion();
	Item* boost = new AttackBoost();
	// �������� �κ��丮�� �߰�
	hero.useItem(0); // ��ȿ���� ���� ���Դϴ�
	// ������ ���
	hero.useItem(0); // ��ȿ���� ���� ���Դϴ�
	// �޸� ����
	delete potion;
	delete boost;
	return 0;
}