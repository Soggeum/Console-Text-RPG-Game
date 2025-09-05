#include "GameManager.hpp"

GameManager::GameManager()
{

	// 1. 캐릭터 생성
	/*string name;
	cout << "캐릭터 이름을 입력하세요: ";
	getline(cin >> ws, name);
	cout << endl;

	player = getCharacter(name);*/
	player = Character::GetInstance();
	player->SetName();
	isClear = false;

	// 2. 랜덤값 시드 초기화
	srand(static_cast<unsigned int>(time(NULL)));

	// 3. Shop 생성
	//shop = new Shop();

	BeginGame();
}

GameManager::~GameManager()
{
	// ----- new로 할당한 것들 해제--------
	//delete shop;

	cout << "게임을 종료합니다.";
	return;
}

void GameManager::BeginGame()
{
	int choice;
	while (!(player->IsDead()) && !isClear)
	{
		system("cls");
		cout << "1. 전투\n";
		cout << "2. 플레이어 스텟 확인\n";
		cout << "3. 플레이어 인벤토리 보기\n";
		cout << "4. 상점 가기\n";
		cout << "5. 게임 종료\n";
		cout << "번호 입력: ";

		cin >> choice;
		if (cin.fail()) {
			cout << "잘못된 입력입니다. 숫자를 입력해주세요." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			system("pause");
			continue;
		}

		if (choice == 1) {
			Battle battle(player, isClear);
			system("pause");
		}

		else if (choice == 2) {
			player->PrintStat();
			system("pause");
			continue;
		}

		else if (choice == 3) {
			//player->displayInventory();
			system("pause");
			continue;
		}

		else if (choice == 4) {
			visitShop(player);
			system("pause");
			continue;
		}

		else if (choice == 5) {
			return;
		}

		else {
			cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
			continue;
		}
	}

	if (player->IsDead()) {
		return;
	}

	if (isClear) {
		return;
	}
}

Character* GameManager::getCharacter(string name)
{
	Character* player = Character::GetInstance();
	return player;
}

void GameManager::visitShop(Character* player)
{

}
