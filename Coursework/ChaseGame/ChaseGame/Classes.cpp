#include "Classes.h"


std::vector<int> Character::getPos() {
	return pos;
}

void Character::setPos(int x, int y) {
	pos[0] = x;
	pos[1] = y;
}

void Character::setWhoPlays(char p) {
	whoPlays = p;
}

char Character::getWhoPlays() {
	return whoPlays;
}

Prey::Prey() {
	setWhoPlays('p');
}

Prey::Prey(char p) {
	setWhoPlays(p);
}

void Prey::move(char choice) {
	if (choice != 'w' && choice != 'a' && choice != 's' && choice != 'd' && choice != 'e' && choice != 'z' && choice != 'c' && choice != 'q') {
		while (true) {
			std::cout << "Incorrect input. You can only choose 'WASD' to move vertically/horizontally and 'QEZC' to move diagonally(only lower cases!)." << std::endl;
			std::cout << "Input: ";
			std::cin >> choice;
			std::cin.ignore();
			if (choice == 'w' || choice == 'a' || choice == 's' || choice == 'd' || choice == 'e' || choice == 'z' || choice == 'c' || choice == 'q') {
				break;
			}
		}
	}
	std::vector<int> position = getPos();
	int x = position[0];
	int y = position[1];

	if (choice == 'w') {
		setPos(x, y - 1);
	}
	else if (choice == 'a') {
		setPos(x - 1, y);
	}
	else if (choice == 's') {
		setPos(x, y + 1);
	}
	else if (choice == 'd') {
		setPos(x + 1, y);
	}
	else if (choice == 'q') {
		setPos(x - 1, y - 1);
	}
	else if (choice == 'e') {
		setPos(x + 1, y - 1);
	}
	else if (choice == 'z') {
		setPos(x - 1, y - 1);
	}
	else if (choice == 'c') {
		setPos(x + 1, y + 1);
	}
}


Hunter::Hunter() {
	setWhoPlays('n');
}

Hunter::Hunter(char p) {
	setWhoPlays(p);
}

void Hunter::move(char choice) {
	if (choice != 'w' && choice != 'a' && choice != 's' && choice != 'd') {
		while (true) {
			std::cout << "Incorrect input. You can only choose 'WASD'(only lower cases!)" << std::endl;
			std::cout << "Input: ";
			std::cin >> choice;
			std::cin.ignore();
			if (choice == 'w' || choice == 'a' || choice == 's' || choice == 'd') {
				break;
			}
		}
	}
	std::string stepS;
	std::cout << "Input the number of steps you want to make from 1 to 3: ";
	std::cin >> stepS;
	std::cin.ignore();
	int step = -1;
	if (stepS.find_first_not_of("0123456789") == std::string::npos) {
		step = std::stoi(stepS);
	}
	while (step < 1 || step > 3) {
		std::cout << "Incorrect input. Hunter can only move from 1 to 3 steps." << std::endl;
		std::cout << "Input: ";
		std::cin >> stepS;
		std::cin.ignore();
		if (stepS.find_first_not_of("0123456789") == std::string::npos) {
			step = std::stoi(stepS);
		}
	}
	std::vector<int> position = getPos();
	int x = position[0];
	int y = position[1];
	if (choice == 'w') {
		setPos(x, (y - step));
	}
	else if (choice == 'a') {
		setPos((x - step), y);
	}
	else if (choice == 's') {
		setPos(x, (y + step));
	}
	else {
		setPos((x + step), y);
	}
}

Arena::Arena() {
	setSize(20, 20);
}

Arena::Arena(int row, int col) {
	setSize(row, col);
}

void Arena::setSize(int x, int y) {
	size[0] = x;
	size[1] = y;
}

void Arena::clearField() {
	playingField = {};
}

std::vector<int> Arena::getSize() {
	return size;
}

void Arena::setPositions(int hx, int hy, int px, int py) {
	hunterPos[0] = hx;
	hunterPos[1] = hy;
	preyPos[0] = px;
	preyPos[1] = py;
}

void Arena::createPlayingField() {
	int column = 0;
	while (column < size[0]) {
		std::vector<char> row;
		for (int i = 0; i < size[1]; i++) {
			if (column == preyPos[1]) {
				if (i == preyPos[0]) {
					row.push_back('P');
				}
			}
			if (column == hunterPos[1]) {
				if (i == hunterPos[0]) {
					row.push_back('H');
				}
			}
			row.push_back(' ');
		}
		row.push_back('\n');
		playingField.push_back(row);
		column++;
	}
}

std::vector<int> Arena::getPosition(char role) {
	if (role == 'H') {
		return hunterPos;
	}
	else {
		return preyPos;
	}
}

void Arena::drawArena() {
	std::string upper_and_lower_borders(size[1], '-');
	std::vector<int> lower_border_numbers;
	std::cout << ' ' << upper_and_lower_borders << std::endl;
	for (int col = 0; col < size[0]; col++) {
		std::cout << "|";
		for (int row = 0; row < size[1]; row++) {
			std::cout << playingField[col][row];
		}
		std::cout << "|" << std::endl;
	}
	std::cout << ' ' << upper_and_lower_borders << std::endl;
}


MainGame::MainGame() {
	turnAmount = 20;
}

MainGame::MainGame(int row, int col) {
	char r = chooseRole();
	if (r == 'H') {
		hunter.setWhoPlays('p');
		prey.setWhoPlays('n');
	}
	else {
		hunter.setWhoPlays('n');
		prey.setWhoPlays('p');
	}
	arena.setSize(row, col);
	std::cout << "Choose the number of turns: ";
	std::cin >> turnAmount;
	bool no = 0;
	std::cin.ignore();
	while (true) {
		if (turnAmount.find_first_not_of("0123456789") == std::string::npos) {
			break;
		}
		std::cout << "You've chosen an incorrect amount of turns. Try again." << std::endl;
		std::cin >> turnAmount;
		std::cin.ignore();
	}
}

char MainGame::chooseRole() {
	char r;
	std::cout << "'H' - Hunter, 'P' - Prey. Choose your role(only upper case!): ";
	std::cin >> r;
	while (r != 'H' && r != 'P') {
		std::cout << "You've chosen an incorrect role." << std::endl;
		std::cin >> r;
	}
	return r;
}


void MainGame::turnChange() {
	char hunterManager = hunter.getWhoPlays();
	char preyManager = prey.getWhoPlays();
	char choice;
	if (turn == 'H') {
		if (hunterManager == 'p') {
			choice = moveChoice();
			hunter.move(choice);
		}
		else {
			botMovement('H');
		}
		turn = 'P';
	}
	else {
		if (preyManager == 'p') {
			choice = moveChoice();
			prey.move(choice);
		}
		else {
			botMovement('P');
		}
		turn = 'H';
	}
}


char MainGame::moveChoice() {
	char choice;
	std::cout << "Choose where you want to go: ";
	std::cin >> choice;
	std::cin.ignore();
	return choice;
}

void MainGame::botMovement(char role) {
	int hx = arena.getPosition('H')[0];
	int hy = arena.getPosition('H')[1];
	int px = arena.getPosition('P')[0];
	int py = arena.getPosition('P')[1];
	if (role == 'H') {
		int x_diff = hx - px;
		int y_diff = hy - py;
		if (x_diff != 0) {
			if (x_diff <= 3 && x_diff >= -3) {
				hunter.setPos(hx - x_diff, hy);
			}
			else {
				if (x_diff < 0) {
					hunter.setPos(hx + 3, hy);
				}
				else {
					hunter.setPos(hx - 3, hy);
				}
			}
		}
		else {
			if (y_diff <= 3 && y_diff >= -3) {
				hunter.setPos(hx, hy - y_diff);
			}
			else {
				if (y_diff < 0) {
					hunter.setPos(hx, hy + 3);
				}
				else {
					hunter.setPos(hx, hy - 3);
				}
			}
		}
	}
	else {
		int X[] = { px - 1, px + 1, px };
		int Y[] = { py - 1, py + 1, py };
		int length = sizeof(X) / sizeof(int);
		prey.setPos(X[rand() % length], Y[rand() % length]);
	}

}


void MainGame::setStartingPositions(int hx, int hy, int px, int py) {
	prey.setPos(px, py);
	hunter.setPos(hx, hy);
	arena.setPositions(hx, hy, px, py);
}


void MainGame::startGame() {
	setStartingPositions(0, 0, int(arena.getSize()[1] / 2), int(arena.getSize()[0] / 2));
	int turnCount = 1;
	bool hunterWon = 0;
	while (turnCount <= std::stoi(turnAmount)) {
		int hx = arena.getPosition('H')[0];
		int hy = arena.getPosition('H')[1];
		int px = arena.getPosition('P')[0];
		int py = arena.getPosition('P')[1];
		std::cout << "Õîä #" << turnCount << std::endl;
		arena.createPlayingField();
		arena.drawArena();
		if (hx == px && hy == py && turnCount != std::stoi(turnAmount)) {
			hunterWon = 1;
			break;
		}
		turnChange();
		turnCount++;
		arena.setPositions(hunter.getPos()[0], hunter.getPos()[1], prey.getPos()[0], prey.getPos()[1]);
		arena.clearField();
	}
	endTheGame(hunterWon);
}


void MainGame::endTheGame(bool hunterWon) {
	if (hunterWon) {
		std::cout << "Hunter wins!" << std::endl;
	}
	else {
		std::cout << "Prey wins!" << std::endl;
	}
}
