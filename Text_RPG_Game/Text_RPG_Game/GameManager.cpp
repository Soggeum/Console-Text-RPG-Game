#include "GameManager.hpp"

GameManager::GameManager()
{

	// 1. 캐릭터 생성
	player = Character::GetInstance();
	player->SetName();
	isClear = false;

	// 2. 랜덤값 시드 초기화
	srand(static_cast<unsigned int>(time(NULL)));

	// 3. LogManager 생성
	logManager = new LogManager();

	// 4. Shop 생성
	shop = new Shop(logManager);

	// 5. Battle 생성
	battle = new Battle(player, isClear, logManager);
}

GameManager::~GameManager()
{
	// ----- new로 할당한 것들 해제--------
	delete shop;

	delete logManager;
	delete battle;
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
		cout << "5. 게임 로그 보기\n";
		cout << "6. 게임 종료\n";
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
			system("cls");
			battle->Init();
		}

		else if (choice == 2) {
			system("cls");
			player->PrintStat();
			system("pause");
			continue;
		}

		else if (choice == 3) {
			system("cls");
			player->showInventory();
			system("pause");
			continue;
		}

		else if (choice == 4) {
			visitShop(player);
			system("pause");
			continue;
		}

		else if (choice == 5) {
			system("cls");
			logManager->displayLog();
			system("pause");
			continue;
		}

		else if (choice == 6) {
			return;
		}

		else {
			cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
			continue;
		}
	}

	if (player->IsDead()) {
		logManager->displayAllLog();
		return;
	}

	if (isClear) {
		logManager->displayAllLog();
		return;
	}
}

Character* GameManager::getCharacter(string name)
{
	Character* player = Character::GetInstance();
	return player;
}

void GameManager::visitShop(Character* player)
{//상점
	logManager->setLogInput("shopCount");
	shop->Begin(player);
}
void Character::AddGold(int amount)
{
	if (amount > 0) {
		gold += amount;
		cout << amount << " Gold를 획득했습니다. 현재 소지 금액: " << gold << " Gold" << endl;
	}
}

Item* Character::GetItemFromInventory(int index)
{
	if (index >= 0 && index < inventory.size()) {
		return inventory[index];
	}
	return nullptr; // 유효하지 않은 인덱스면 nullptr 반환
}

void Character::RemoveItemFromInventory(int index)
{
	if (index >= 0 && index < inventory.size()) {
		// 1. 메모리 해제
		delete inventory[index];
		// 2. 벡터에서 포인터 제거
		inventory.erase(inventory.begin() + index);
	}
}