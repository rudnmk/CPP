#include "Classes.h"

int main() {
	setlocale(LC_ALL, "ru");
	MainGame game(10, 30);
	game.startGame();

	return 0;
}