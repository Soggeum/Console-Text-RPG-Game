#include "Battle.hpp"

Battle::Battle(Character* player, bool& isClear) : player(player), isClear(isClear)
{
	system("cls");
	if (player->GetLevel() < 10) {
		monster = generateMonster(player->GetLevel());
		cout << "몬스터 " << monster->getName() << " 등장!체력: " << monster->getHp() << ", 공격력 : " << monster->getAttack() << endl;

		// 전투 시작 및 클리어 여부
		isClear = Begin();
	}

	else {
		monster = generateBossMonster(player->GetLevel());
		cout << "보스 몬스터 " << monster->getName() << " 등장! 체력: " << monster->getHp()<< ", 공격력: " << monster->getAttack() << endl;

		// 전투 시작 및 클리어 여부
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
		// 선택지 출력 (1. 공격 / 2. 스텟 확인 ...)
		choice = printOption();

		// 1. 공격 시나리오
		if (choice == 1) {
			player->Attack(monster);
			cout << player->getName() << "이(가) " << monster->getName() << "을(를) 공격합니다!";

			// 몬스터 사망
			if (monster->getHp() <= 0) {
				cout << monster->getName() << " 처치!\n";
				int money = (rand() % 11) + 10;
				player->GetReward(money, 50);
				cout << player->getName() << "이(가) 50 EXP와 " << money << " 골드를 획득했습니다.현재 EXP : "
					<< player->GetEXP() << " / 100, 골드 : " << player->GetGold() << endl;

				// --- 몬스터 아이템 ---

				
				system("pause");
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
					return false;
				}
				system("pause");
			}

			// 다시 처음부터 반복
			system("cls");
			continue;
		}

		// 2. 플레이어 스텟 확인
		else if (choice == 2) {
			player->PrintStat();
			system("pause");
			continue;
		}

		// 3. 적 스텟 확인
		else if (choice == 3) {
			//monster->displayStatus();
			system("pause");
			continue;
		}

		// 4. 인벤토리 확인
		else if (choice == 4) {
			//player->displayInventory();
			system("pause");
			continue;
		}

		// 5. 아이템 사용
		else if (choice == 5) {
			// 아이템 사용 함수
			// ----------------------------------------//
			system("pause");
			continue;
		}

		else {
			cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
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
		// 선택지 출력 (1. 공격 / 2. 스텟 확인 ...)
		choice = printOption();

		// 1. 공격 시나리오
		if (choice == 1) {
			monster->takeDamage(player->GetAttack());
			cout << player->getName() << "이(가) " << monster->getName() << "을(를) 공격합니다!";

			// 몬스터 사망
			if (monster->getHp() <= 0) {
				cout << monster->getName() << " 처치!\n";
				cout << "축하합니다! 보스 몬스터" << monster->getName() << "을 처치하고 게임을 클리어했습니다!" << endl;
				system("pause");
				return true;
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
					return false;
				}
				system("pause");
			}

			// 다시 처음부터 반복
			system("cls");
			continue;
		}

		// 2. 플레이어 스텟 확인
		else if (choice == 2) {
			player->PrintStat();
			system("pause");
			continue;
		}

		// 3. 적 스텟 확인
		else if (choice == 3) {
			//monster->displayStatus();
			system("pause");
			continue;
		}

		// 4. 인벤토리 확인
		else if (choice == 4) {
			//player->displayInventory();
			system("pause");
			continue;
		}

		// 5. 아이템 사용
		else if (choice == 5) {
			// 아이템 사용 함수
			// ----------------------------------------//
			system("pause");
			continue;
		}

		else {
			cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
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
