#include "GameManager.hpp"

GameManager::GameManager()
{

	// 1. ĳ���� ����
	player = Character::GetInstance();
	player->SetName();
	isClear = false;

	// 2. ������ �õ� �ʱ�ȭ
	srand(static_cast<unsigned int>(time(NULL)));

	// 3. Shop ����
	//shop = new Shop();

	// 4. LogManager ����
	/*
	logmanager = new LogManager();
	*/

}

GameManager::~GameManager()
{
	// ----- new�� �Ҵ��� �͵� ����--------
	//delete shop;

	cout << "������ �����մϴ�.";
	return;
}

void GameManager::BeginGame()
{
	int choice;
	while (!(player->IsDead()) && !isClear)
	{
		system("cls");
		cout << "1. ����\n";
		cout << "2. �÷��̾� ���� Ȯ��\n";
		cout << "3. �÷��̾� �κ��丮 ����\n";
		cout << "4. ���� ����\n";
//		cout << "5. ���� �α� ����\n";	// (���� ���Ḧ 6������)
		cout << "5. ���� ����\n";
		cout << "��ȣ �Է�: ";

		cin >> choice;
		if (cin.fail()) {
			cout << "�߸��� �Է��Դϴ�. ���ڸ� �Է����ּ���." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			system("pause");
			continue;
		}

		if (choice == 1) {
			Battle battle(player, isClear);
		}

		else if (choice == 2) {
			system("cls");
			player->PrintStat();
			system("pause");
			continue;
		}

		else if (choice == 3) {
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
			return;
		}

		/*
		else if (choice == 6) {
			logManager->displayLog();
			system("pause");
			continue;
		}
		*/

		else {
			cout << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���." << endl;
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
	// shop->begin(player);
}
