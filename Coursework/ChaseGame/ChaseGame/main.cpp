#include "Classes.h"

int main() {
	setlocale(LC_ALL, "ru");
	MainGame game(30, 30);
	game.startGame();

	return 0;
}