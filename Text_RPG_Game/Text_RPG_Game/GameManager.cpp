#include "GameManager.hpp"

GameManager::GameManager()
{

	// 1. ĳ���� ����
	player = Character::GetInstance();
	player->SetName();
	isClear = false;

	// 2. ������ �õ� �ʱ�ȭ
	srand(static_cast<unsigned int>(time(NULL)));

	// 3. LogManager ����
	logManager = new LogManager();

	// 4. Shop ����
	shop = new Shop(logManager);

	// 5. Battle ����
	battle = new Battle(player, isClear, logManager);
}

GameManager::~GameManager()
{
	// ----- new�� �Ҵ��� �͵� ����--------
	delete shop;

	delete logManager;
	delete battle;
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
		cout << "5. ���� �α� ����\n";
		cout << "6. ���� ����\n";
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
			cout << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���." << endl;
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
{//����
	logManager->setLogInput("shopCount");
	shop->Begin(player);
}
void Character::AddGold(int amount)
{
	if (amount > 0) {
		gold += amount;
		cout << amount << " Gold�� ȹ���߽��ϴ�. ���� ���� �ݾ�: " << gold << " Gold" << endl;
	}
}

Item* Character::GetItemFromInventory(int index)
{
	if (index >= 0 && index < inventory.size()) {
		return inventory[index];
	}
	return nullptr; // ��ȿ���� ���� �ε����� nullptr ��ȯ
}

void Character::RemoveItemFromInventory(int index)
{
	if (index >= 0 && index < inventory.size()) {
		// 1. �޸� ����
		delete inventory[index];
		// 2. ���Ϳ��� ������ ����
		inventory.erase(inventory.begin() + index);
	}
}