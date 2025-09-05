#include "Battle.hpp"

Battle::Battle(Character* player, bool& isClear) : player(player), isClear(isClear)
{
	system("cls");
	if (player->GetLevel() < 10) {
		monster = generateMonster(player->GetLevel());
		cout << "���� " << monster->getName() << " ����!ü��: " << monster->getHp() << ", ���ݷ� : " << monster->getAttack() << endl;

		// ���� ���� �� Ŭ���� ����
		isClear = Begin();
	}

	else {
		monster = generateBossMonster(player->GetLevel());
		cout << "���� ���� " << monster->getName() << " ����! ü��: " << monster->getHp()<< ", ���ݷ�: " << monster->getAttack() << endl;

		// ���� ���� �� Ŭ���� ����
		isClear = BossBegin();
	}
}

Battle::~Battle()
{
	delete monster;
}

bool Battle::Begin()
{
	int choice;
	while (true) {
		// ������ ��� (1. ���� / 2. ���� Ȯ�� ...)
		choice = printOption();

		// 1. ���� �ó�����
		if (choice == 1) {
			player->Attack(monster);
			cout << player->getName() << "��(��) " << monster->getName() << "��(��) �����մϴ�!";

			// ���� ���
			if (monster->getHp() <= 0) {
				cout << monster->getName() << " óġ!\n";
				int money = (rand() % 11) + 10;
				player->GetReward(money, 50);
				cout << player->getName() << "��(��) 50 EXP�� " << money << " ��带 ȹ���߽��ϴ�.���� EXP : "
					<< player->GetEXP() << " / 100, ��� : " << player->GetGold() << endl;

				// --- ���� ������ ---

				
				system("pause");
				return false;
			}

			// ������ ����
			else {
				cout << monster->getName() << "��(��) " << player->getName() << "��(��) �����մϴ�!";
				player->TakeDamage(monster->getAttack());

				cout << player->getName() << " ü�� : " << player->GetHP() << endl;

				// �÷��̾� ���
				if (player->IsDead()) {
					cout << player->getName() << "��(��) ����߽��ϴ�. ���� ����!";
					system("pause");
					return false;
				}
				system("pause");
			}

			// �ٽ� ó������ �ݺ�
			system("cls");
			continue;
		}

		// 2. �÷��̾� ���� Ȯ��
		else if (choice == 2) {
			player->PrintStat();
			system("pause");
			continue;
		}

		// 3. �� ���� Ȯ��
		else if (choice == 3) {
			//monster->displayStatus();
			system("pause");
			continue;
		}

		// 4. �κ��丮 Ȯ��
		else if (choice == 4) {
			//player->displayInventory();
			system("pause");
			continue;
		}

		// 5. ������ ���
		else if (choice == 5) {
			// ������ ��� �Լ�
			// ----------------------------------------//
			system("pause");
			continue;
		}

		else {
			cout << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���." << endl;
			system("pause");
			continue;
		}
	}

	return false;
}

bool Battle::BossBegin()
{
	int choice;
	while (true) {
		// ������ ��� (1. ���� / 2. ���� Ȯ�� ...)
		choice = printOption();

		// 1. ���� �ó�����
		if (choice == 1) {
			monster->takeDamage(player->GetAttack());
			cout << player->getName() << "��(��) " << monster->getName() << "��(��) �����մϴ�!";

			// ���� ���
			if (monster->getHp() <= 0) {
				cout << monster->getName() << " óġ!\n";
				cout << "�����մϴ�! ���� ����" << monster->getName() << "�� óġ�ϰ� ������ Ŭ�����߽��ϴ�!" << endl;
				system("pause");
				return true;
			}

			// ������ ����
			else {
				cout << monster->getName() << "��(��) " << player->getName() << "��(��) �����մϴ�!";
				player->TakeDamage(monster->getAttack());

				cout << player->getName() << " ü�� : " << player->GetHP() << endl;

				// �÷��̾� ���
				if (player->IsDead()) {
					cout << player->getName() << "��(��) ����߽��ϴ�. ���� ����!";
					system("pause");
					return false;
				}
				system("pause");
			}

			// �ٽ� ó������ �ݺ�
			system("cls");
			continue;
		}

		// 2. �÷��̾� ���� Ȯ��
		else if (choice == 2) {
			player->PrintStat();
			system("pause");
			continue;
		}

		// 3. �� ���� Ȯ��
		else if (choice == 3) {
			//monster->displayStatus();
			system("pause");
			continue;
		}

		// 4. �κ��丮 Ȯ��
		else if (choice == 4) {
			//player->displayInventory();
			system("pause");
			continue;
		}

		// 5. ������ ���
		else if (choice == 5) {
			// ������ ��� �Լ�
			// ----------------------------------------//
			system("pause");
			continue;
		}

		else {
			cout << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���." << endl;
			system("pause");
			continue;
		}
	}
	
	return false;
}

Monster* Battle::generateMonster(int level)
{
	int randNum = rand() % 4;

	switch (randNum) {
	case 0:
		return new Slime(level);

	case 1:
		return new Goblin(level);

	case 2:
		return new Orc(level);

	case 3:
		return new Troll(level);

	default:
		cout << "���� ���� ����\n";
		return nullptr;
	}
}

BossMonster* Battle::generateBossMonster(int level)
{
	return new BossMonster(level);
}

int Battle::printOption()
{
	int choice = 0;
	while (true) {
		cout << "1. ����\n";
		cout << "2. �÷��̾� ���� Ȯ��\n";
		cout << "3. �� ���� Ȯ��\n";
		cout << "4. �κ��丮 Ȯ��\n";
		cout << "5. ������ ���\n";
		cout << "��ȣ �Է�: ";

		cin >> choice;
		if (cin.fail()) {
			system("cls");
			cout << "�߸��� �Է��Դϴ�. ���ڸ� �Է����ּ���." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}

		else
			return choice;
	}

	return choice;
}
