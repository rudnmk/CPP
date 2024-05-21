#include "matrix.h"

//������� ���������� ���-�� ��������� ����� � ��������� �����.
int count_chosen_words();

//������� ������/���������� ������ � ����/�� �����.
Matrix file_matrix(Matrix X);

//������� ������ � ��������� ����
void book_database();



int main() {
	setlocale(LC_ALL, "ru");

	//�������� 1-�� �������
	int count = 0;
	//count = count_chosen_words();
	std::cout << count << std::endl;

	//�������� 2-�� �������
	Matrix A;
	Matrix B;
	A.randFill();
	B.randFill();
	//file_matrix(A);
	//B = file_matrix(B);
	//std::cout << B;


	//�������� 3-�� �������
	//book_database();
	return 0;
}


int count_chosen_words() {
	std::string needed_word;
	std::cout << "������� ����������� �����: ";
	std::cin >> needed_word;
	std::ifstream file(needed_word.c_str(), std::ios::in);
	std::string temp_word = "";
	int count = 0;
	file.open("test 1.txt");
	while (file >> temp_word) {
		if (temp_word == needed_word) {
			count++;
		}
	}

	file.close();
	return count;
}


Matrix file_matrix(Matrix X) {
	int answer;
	std::string path;
	std::string name;
	std::cout << "�������� ��������(1 - ������ ������� � ����, 2 - ������ ������� �� ����� � ����������): ";
	std::cin >> answer;
	if (answer == 1) {
		std::ofstream file;
		std::cout << "������� �������� �������: ";
		std::cin >> name;
		path = "matrix_" + name + ".txt";
		file.open(path);
		file << X << std::endl;
		file.close();
	}
	else {
		std::ifstream file;
		std::cout << "������� �������� �����(���� ������ ���������� � ����� ����� � ��������): ";
		std::cin >> name;
		path = name + ".txt";
		file.open(path);
		char ch;
		std::string snum = "";
		int num;
		int fl = 0;
		int row = 0;
		int col = 0;
		while (file.get(ch)) {
			if (ch != '[' && ch != ']' && ch != ' ' && ch != '\n') {
				snum += ch;
				fl = 1;
			}
			if (fl && ch == ' ') {
				num = std::stoi(snum);
				X[row][col] = num;
				col++;
				snum = "";
				fl = 0;
			}
			if (ch == '\n') {
				row++;
				col = 0;
			}
		}
		file.close();
	}

	return X;
}


void book_database() {
	std::ofstream write;
	std::ifstream read;
	std::string tmp;
	char catcher;


	//������ �����������, ���� �� ����� ���������� ���� book catalog.txt �� ���. ���������

	read.open("START.txt");
	write.open("book catalog.txt");
	while (std::getline(read, tmp)) {
		write << tmp << std::endl;
	}
	read.close();
	write.close();

	read.open("book catalog.txt");
	write.open("temp backup.txt");
	int ID = 0;
	while (std::getline(read, tmp)) {
		write << tmp << std::endl;
		ID++;
	}
	read.close();
	write.close();



	int chosenID;
	int still_working = 1;
	std::string command;
	std::cout << "�������� ������ ��� ������ � ��������� ����: " << std::endl;
	std::cout << "add - ���������� ������ � �������;" << std::endl;
	std::cout << "del - �������� ������ �� ��������;" << std::endl;
	std::cout << "show - �������� ���� ������� � ��������;" << std::endl;
	std::cout << "find - ����� ������ � ��������;" << std::endl;
	std::cout << "redact - �������������� ������ � ��������;" << std::endl;
	std::cout << "stop - ���������� ������ � ���������." << std::endl;
	while (still_working) {
		std::cout << "������� �������: ";
		std::getline(std::cin, command);
		read.open("temp backup.txt");

		if (command == "add" || command == "del" || command == "redact") {
			write.open("book catalog.txt");
		}

		if (command == "add") {
			while (std::getline(read, tmp)) {
				write << tmp << std::endl;
			}
			std::string author;
			std::string title;
			int pages;
			ID++;
			std::cout << "������� ������ �����: ";
			std::getline(std::cin, author);
			std::cout << "������� �������� �����: ";
			std::getline(std::cin, title);
			std::cout << "������� ���-�� ������� �����: ";
			std::cin >> pages;
			std::cin.ignore();
			write << ID << "   " << author << "   " << title << "   " << pages << std::endl;
		}

		else if (command == "del") {
			std::cout << "������� ID �����, ���������� � ������� �� ������ �������(������� �����, ��� ID �� ������ ��������� " << ID << "): ";
			std::cin >> chosenID;
			std::cin.ignore();
			if (chosenID > ID) {
				std::cout << "������ ID �� ����������! ����������� ��������� ID = " << ID << std::endl;
			}
			else{
				int c = 0;
				int fl = 0;
				while (std::getline(read, tmp)) {
					c++;
					if (c == chosenID && !fl) {
						fl = 1;
						c--;
					}
					else if (fl) {
						std::string sc = std::to_string(c);
						for (int j = 0; j < sc.length(); j++) {
							tmp[j] = sc[j];
						}
						write << tmp << std::endl;
					}
					else {
						write << tmp << std::endl;
					}
				}
				ID = c;
			}

		}

		else if (command == "show") {
			while (std::getline(read, tmp)) {
				std::cout << tmp << std::endl;
			}
		}

		else if (command == "find") {
			std::cout << "������� ID ������ �����(������� �����, ��� ID �� ������ ��������� " << ID << "): ";
			std::cin >> chosenID;
			std::cin.ignore();
			if (chosenID > ID) {
				std::cout << "������ ID �� ����������! ����������� ��������� ID = " << ID << std::endl;
			}
			else {
				int count = 1;
				while (std::getline(read, tmp)) {
					if (count == chosenID) {
						std::cout << tmp << std::endl;
						break;
					}
					count++;
				}
			}
		}

		else if (command == "redact") {
			std::cout << "������� ID �����, ���������� � ������� �� ������ ��������(������� �����, ��� ID �� ������ ��������� " << ID << "): ";
			std::cin >> chosenID;
			std::cin.ignore();
			if (chosenID > ID) {
				std::cout << "������ ID �� ����������! ����������� ��������� ID = " << ID << std::endl;
			}
			else {
				int count = 1;
				while (std::getline(read, tmp)) {
					if (count == chosenID) {
						std::string author;
						std::string title;
						int pages;
						std::cout << "������� ������ �����: ";
						std::getline(std::cin, author);
						std::cout << "������� �������� �����: ";
						std::getline(std::cin, title);
						std::cout << "������� ���-�� ������� �����: ";
						std::cin >> pages;
						std::cin.ignore();
						write << count << "   " << author << "   " << title << "   " << pages << std::endl;
					}
					else {
						write << tmp << std::endl;
					}
					count++;
				}
			}
		}

		else if (command == "stop") {
			still_working = 0;
			read.close();
			break;
		}

		else {
			std::cout << "������ ������� �� ����������. ��������� ������� ��� ���." << std::endl;
		}

		if (command == "add" || command == "del" || command == "redact") {
			write.close();
		}


		read.close();
		//������������� backup ����� � ������ book catalog
		read.open("book catalog.txt");
		write.open("temp backup.txt");
		while (std::getline(read, tmp)) {
			write << tmp << std::endl;
		}
		read.close();
		write.close();
	}

	std::cout << "������ � ��������� �����������." << std::endl;
}