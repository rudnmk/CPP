#include "matrix.h"

//Функция считывания кол-ва появления слова в текстовом файле.
int count_chosen_words();

//Функция записи/считывания матриц в файл/из файла.
Matrix file_matrix(Matrix X);

//Функция работы с каталогом книг
void book_database();



int main() {
	setlocale(LC_ALL, "ru");

	//Проверка 1-го задания
	int count = 0;
	//count = count_chosen_words();
	std::cout << count << std::endl;

	//Проверка 2-го задания
	Matrix A;
	Matrix B;
	A.randFill();
	B.randFill();
	//file_matrix(A);
	//B = file_matrix(B);
	//std::cout << B;


	//Проверка 3-го задания
	//book_database();
	return 0;
}


int count_chosen_words() {
	std::string needed_word;
	std::cout << "Введите необходимое слово: ";
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
	std::cout << "Выберите действие(1 - запись матрицы в файл, 2 - запись матрицы из файла в переменную): ";
	std::cin >> answer;
	if (answer == 1) {
		std::ofstream file;
		std::cout << "Введите название матрицы: ";
		std::cin >> name;
		path = "matrix_" + name + ".txt";
		file.open(path);
		file << X << std::endl;
		file.close();
	}
	else {
		std::ifstream file;
		std::cout << "Введите название файла(файл должен находиться в одной папке с проектом): ";
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


	//убрать комментарий, если не нужно сбрасывать файл book catalog.txt до нач. состояния

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
	std::cout << "Названия команд для работы с каталогом книг: " << std::endl;
	std::cout << "add - добавление записи в каталог;" << std::endl;
	std::cout << "del - удаление записи из каталога;" << std::endl;
	std::cout << "show - просмотр всех записей в каталоге;" << std::endl;
	std::cout << "find - поиск записи в каталоге;" << std::endl;
	std::cout << "redact - редактирование записи в каталоге;" << std::endl;
	std::cout << "stop - остановить работу с каталогом." << std::endl;
	while (still_working) {
		std::cout << "Введите команду: ";
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
			std::cout << "Введите автора книги: ";
			std::getline(std::cin, author);
			std::cout << "Введите название книги: ";
			std::getline(std::cin, title);
			std::cout << "Введите кол-во страниц книги: ";
			std::cin >> pages;
			std::cin.ignore();
			write << ID << "   " << author << "   " << title << "   " << pages << std::endl;
		}

		else if (command == "del") {
			std::cout << "Введите ID книги, информацию о которой вы хотите удалить(иммейте ввиду, что ID не должно превышать " << ID << "): ";
			std::cin >> chosenID;
			std::cin.ignore();
			if (chosenID > ID) {
				std::cout << "Такого ID не существует! Максимально возможное ID = " << ID << std::endl;
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
			std::cout << "Введите ID нужной книги(иммейте ввиду, что ID не должно превышать " << ID << "): ";
			std::cin >> chosenID;
			std::cin.ignore();
			if (chosenID > ID) {
				std::cout << "Такого ID не существует! Максимально возможное ID = " << ID << std::endl;
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
			std::cout << "Введите ID книги, информацию о которой вы хотите изменить(иммейте ввиду, что ID не должно превышать " << ID << "): ";
			std::cin >> chosenID;
			std::cin.ignore();
			if (chosenID > ID) {
				std::cout << "Такого ID не существует! Максимально возможное ID = " << ID << std::endl;
			}
			else {
				int count = 1;
				while (std::getline(read, tmp)) {
					if (count == chosenID) {
						std::string author;
						std::string title;
						int pages;
						std::cout << "Введите автора книги: ";
						std::getline(std::cin, author);
						std::cout << "Введите название книги: ";
						std::getline(std::cin, title);
						std::cout << "Введите кол-во страниц книги: ";
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
			std::cout << "Данной команды не существует. Повторите попытку еще раз." << std::endl;
		}

		if (command == "add" || command == "del" || command == "redact") {
			write.close();
		}


		read.close();
		//синхронизация backup файла с файлом book catalog
		read.open("book catalog.txt");
		write.open("temp backup.txt");
		while (std::getline(read, tmp)) {
			write << tmp << std::endl;
		}
		read.close();
		write.close();
	}

	std::cout << "Работа с каталогом остановлена." << std::endl;
}