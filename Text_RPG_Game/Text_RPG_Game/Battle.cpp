#include "Battle.hpp"

Battle::Battle(Character* player, bool& isClear, LogManager* logManager) : player(player), isClear(isClear), logManager(logManager) {}

void Battle::Init()
{
	if (player->GetLevel() < 10) {
		monster = generateMonster(player->GetLevel());
		cout << "몬스터 " << monster->getName() << " 등장!체력: " << monster->getHp() << ", 공격력 : " << monster->getAttack() << endl;

		// 전투 시작 및 클리어 여부
		isClear = Begin();
	}

	else {
		monster = generateBossMonster(player->GetLevel());
		cout << "\033[31m보스 몬스터 " << monster->getName() << " 등장! 체력: " << monster->getHp() << ", 공격력: " << monster->getAttack() << "\033[0m" << endl;

		// 전투 시작 및 클리어 여부
		isClear = BossBegin();
	}
}

Battle::~Battle() {}

bool Battle::Begin()
{
	int choice;
	while (true) {
		// 선택지 출력 (1. 공격 / 2. 스텟 확인 ...)
		choice = printOption();
		system("cls");

		// 1. 공격 시나리오
		if (choice == 1) {
			player->Attack(monster);

			// 몬스터 사망
			if (monster->getHp() <= 0) {
				cout << monster->getName() << " 처치!\n";
				int money = (rand() % 11) + 10;
				player->GetReward(money, 50);		

				// 아이템 드롭
				Item* pItem = monster->dropItem();
				if (pItem != nullptr) 
					player->AddItem(pItem);

				// 몬스터 처치 로그 기록
				logManager->setLogInput("monsterCount");

				system("pause");
				system("cls");
				delete monster;
				return false;
			}

			// 몬스터의 공격
			else {
				cout << monster->getName() << "이(가) " << player->getName() << "을(를) 공격합니다!";
				player->TakeDamage(monster->getAttack());

				cout << player->getName() << " 체력 : " << player->GetHP() << endl;

				// 플레이어 사망
				if (player->IsDead()) {
					cout << player->getName() << "이(가) 사망했습니다. 게임 오버!";
					system("pause");
					system("cls");
					delete monster;
					return false;
				}
				system("pause");
				system("cls");
			}

			// 다시 처음부터 반복
			system("cls");
			continue;
		}

		// 2. 플레이어 스텟 확인
		else if (choice == 2) {
			player->PrintStat();
			system("pause");
			system("cls");
			continue;
		}

		// 3. 적 스텟 확인
		else if (choice == 3) {
			monster->displayStatus();
			system("pause");
			system("cls");
			continue;
		}

		// 4. 인벤토리 확인
		else if (choice == 4) {
			player->showInventory();
			system("pause");
			system("cls");
			continue;
		}

		// 5. 아이템 사용
		else if (choice == 5) {
			// 아이템 사용 함수
			// ----------------------------------------//
			player->showInventory();
			cout << "사용할 아이템 번호: ";
			int index;
			cin >> index;
			player->UseItem(index - 1);
			system("pause");
			system("cls");
			continue;
		}

		else {
			cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
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
		// 선택지 출력 (1. 공격 / 2. 스텟 확인 ...)
		choice = printOption();
		system("cls");

		// 1. 공격 시나리오
		if (choice == 1) {
			player->Attack(monster);

			// 몬스터 사망
			if (monster->getHp() <= 0) {
				cout << monster->getName() << " 처치!\n";
				cout << "축하합니다!보스 " << monster->getName() << "을 처치하고 게임을 클리어했습니다!" << endl;
				system("pause");
				system("cls");
				delete monster;
				return true;
			}

			// 몬스터의 공격
			else {
				cout << "보스 몬스터 " << monster->getName() << "이(가) " << player->getName() << "을(를) 공격합니다!";
				player->TakeDamage(monster->getAttack());

				cout << player->getName() << " 체력 : " << player->GetHP() << endl;

				// 플레이어 사망
				if (player->IsDead()) {
					cout << player->getName() << "이(가) 사망했습니다. 게임 오버!";
					system("pause");
					system("cls");
					delete monster;
					return false;
				}
				system("pause");
				system("cls");
			}

			// 다시 처음부터 반복
			system("cls");
			continue;
		}

		// 2. 플레이어 스텟 확인
		else if (choice == 2) {
			player->PrintStat();
			system("pause");
			system("cls");
			continue;
		}

		// 3. 적 스텟 확인
		else if (choice == 3) {
			monster->displayStatus();
			system("pause");
			system("cls");
			continue;
		}

		// 4. 인벤토리 확인
		else if (choice == 4) {
			player->showInventory();
			system("pause");
			system("cls");
			continue;
		}

		// 5. 아이템 사용
		else if (choice == 5) {
			// 아이템 사용 함수
			// ----------------------------------------//
			player->showInventory();
			cout << "사용할 아이템 번호: ";
			int index;
			cin >> index;
			player->UseItem(index - 1);
			system("pause");
			system("cls");
			continue;
		}

		else {
			cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
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
		cout << "몬스터 생성 에러\n";
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
		cout << "1. 공격\n";
		cout << "2. 플레이어 스텟 확인\n";
		cout << "3. 적 스텟 확인\n";
		cout << "4. 인벤토리 확인\n";
		cout << "5. 아이템 사용\n";
		cout << "번호 입력: ";

		cin >> choice;
		if (cin.fail()) {
			system("cls");
			cout << "잘못된 입력입니다. 숫자를 입력해주세요." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}

		else
			return choice;
	}

	return choice;
}
