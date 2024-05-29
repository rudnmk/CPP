#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <math.h>

class Character {
private:
	std::vector<int> pos = { 0, 0 };
	char whoPlays;
public:
	void setWhoPlays(char p);
	char getWhoPlays();
	void setPos(int x, int y);
	std::vector<int> getPos();
};

class Prey : public Character {
public:
	Prey();
	Prey(char p);
	void move(char choice);
};


class Hunter : public Character {
public:
	Hunter();
	Hunter(char p);
	void move(char choice);
};


class Arena {
private:
	std::vector<int> size = { 0, 0 };
	std::vector<std::vector<char>> playingField;
	std::vector<int> preyPos = { 0, 0 };
	std::vector<int> hunterPos = { 0, 0 };
public:
	Arena();
	Arena(int row, int col);
	std::vector<int> getSize();
	void clearField();
	void setPositions(int hx, int hy, int px, int py);
	void setSize(int x, int y);
	void createPlayingField();
	std::vector<int> getPosition(char role);
	void drawArena();
};


class MainGame {
private:
	Hunter hunter;
	Prey prey;
	Arena arena;
	char turn = 'H';
	std::string turnAmount;
public:
	MainGame();
	MainGame(int row, int col);
	char chooseRole();
	void turnChange();
	char moveChoice();
	void botMovement(char role);
	void setStartingPositions(int hx, int hy, int px, int py);
	void startGame();
	void endTheGame(bool hunterWon);
};