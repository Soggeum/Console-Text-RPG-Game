#include "Battle.hpp"

Battle::Battle(Character* player, bool& isClear, LogManager* logManager) : player(player), isClear(isClear), logManager(logManager) {}

void Battle::Init()
{
	if (player->GetLevel() < 10) {
		monster = generateMonster(player->GetLevel());
		cout << "���� " << monster->getName() << " ����!ü��: " << monster->getHp() << ", ���ݷ� : " << monster->getAttack() << endl;

		// ���� ���� �� Ŭ���� ����
		isClear = Begin();
	}

	else {
		monster = generateBossMonster(player->GetLevel());
		cout << "\033[31m���� ���� " << monster->getName() << " ����! ü��: " << monster->getHp() << ", ���ݷ�: " << monster->getAttack() << "\033[0m" << endl;

		// ���� ���� �� Ŭ���� ����
		isClear = BossBegin();
	}
}

Battle::~Battle() {}

bool Battle::Begin()
{
	int choice;
	while (true) {
		// ������ ��� (1. ���� / 2. ���� Ȯ�� ...)
		choice = printOption();
		system("cls");

		// 1. ���� �ó�����
		if (choice == 1) {
			player->Attack(monster);

			// ���� ���
			if (monster->getHp() <= 0) {
				cout << monster->getName() << " óġ!\n";
				int money = (rand() % 11) + 10;
				player->GetReward(money, 50);		

				// ������ ���
				Item* pItem = monster->dropItem();
				if (pItem != nullptr) 
					player->AddItem(pItem);

				// ���� óġ �α� ���
				logManager->setLogInput("monsterCount");

				system("pause");
				system("cls");
				delete monster;
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
					system("cls");
					delete monster;
					return false;
				}
				system("pause");
				system("cls");
			}

			// �ٽ� ó������ �ݺ�
			system("cls");
			continue;
		}

		// 2. �÷��̾� ���� Ȯ��
		else if (choice == 2) {
			player->PrintStat();
			system("pause");
			system("cls");
			continue;
		}

		// 3. �� ���� Ȯ��
		else if (choice == 3) {
			monster->displayStatus();
			system("pause");
			system("cls");
			continue;
		}

		// 4. �κ��丮 Ȯ��
		else if (choice == 4) {
			player->showInventory();
			system("pause");
			system("cls");
			continue;
		}

		// 5. ������ ���
		else if (choice == 5) {
			// ������ ��� �Լ�
			// ----------------------------------------//
			player->showInventory();
			cout << "����� ������ ��ȣ: ";
			int index;
			cin >> index;
			player->UseItem(index - 1);
			system("pause");
			system("cls");
			continue;
		}

		else {
			cout << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���." << endl;
			system("pause");
			system("cls");
			continue;
		}
	}
}

bool Battle::BossBegin()
{
	int choice;
	while (true) {
		// ������ ��� (1. ���� / 2. ���� Ȯ�� ...)
		choice = printOption();
		system("cls");

		// 1. ���� �ó�����
		if (choice == 1) {
			player->Attack(monster);

			// ���� ���
			if (monster->getHp() <= 0) {
				cout << monster->getName() << " óġ!\n";
				cout << "�����մϴ�!���� " << monster->getName() << "�� óġ�ϰ� ������ Ŭ�����߽��ϴ�!" << endl;
				system("pause");
				system("cls");
				delete monster;
				return true;
			}

			// ������ ����
			else {
				cout << "���� ���� " << monster->getName() << "��(��) " << player->getName() << "��(��) �����մϴ�!";
				player->TakeDamage(monster->getAttack());

				cout << player->getName() << " ü�� : " << player->GetHP() << endl;

				// �÷��̾� ���
				if (player->IsDead()) {
					cout << player->getName() << "��(��) ����߽��ϴ�. ���� ����!";
					system("pause");
					system("cls");
					delete monster;
					return false;
				}
				system("pause");
				system("cls");
			}

			// �ٽ� ó������ �ݺ�
			system("cls");
			continue;
		}

		// 2. �÷��̾� ���� Ȯ��
		else if (choice == 2) {
			player->PrintStat();
			system("pause");
			system("cls");
			continue;
		}

		// 3. �� ���� Ȯ��
		else if (choice == 3) {
			monster->displayStatus();
			system("pause");
			system("cls");
			continue;
		}

		// 4. �κ��丮 Ȯ��
		else if (choice == 4) {
			player->showInventory();
			system("pause");
			system("cls");
			continue;
		}

		// 5. ������ ���
		else if (choice == 5) {
			// ������ ��� �Լ�
			// ----------------------------------------//
			player->showInventory();
			cout << "����� ������ ��ȣ: ";
			int index;
			cin >> index;
			player->UseItem(index - 1);
			system("pause");
			system("cls");
			continue;
		}

		else {
			cout << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���." << endl;
			system("pause");
			system("cls");
			continue;
		}
	}
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
