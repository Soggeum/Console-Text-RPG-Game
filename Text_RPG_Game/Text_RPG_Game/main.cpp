#include "GameManager.hpp"

using namespace std;

int main() {
	GameManager* game = new GameManager();

	game->BeginGame();
	delete game;
	return 0;
}