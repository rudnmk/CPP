#include <iostream>
#include <vector>
#include <time.h>
#include <random>
#include <string>

using namespace std;

float avg_value(vector<int> Grades);
int median(vector<int> Grades);
vector<int> mode(vector<int> Grades);

vector<string> add_name(vector<string> Names);
vector<int> add_grade(vector<int> Grades);

vector<string> delete_name(vector<string> Names, int index);
vector<int> delete_grade(vector<int> Grades, int index);


// Имена написаны на английском языке, т.к. инпут на русском не работает(пытался починить, но там либо не работает, либо ошибку выводит).
int main() {
	setlocale(LC_ALL, "ru");
	vector<string> Names{ "Sergey", "Ivan", "Ilya", "Sasha", "Yulia", "Maksim", "Matvey", "Darya", "Georgiy", "Marya" };
	vector<int> Grades{ 50, 32, 40, 55, 100, 1, 95, 40, 95, 0 };

	int choice;
	cout << "Выберите метод инициализации векторов: 1 - дефолтные значения; 2 - рандомные значения(с выбором размера выборки); 3 - ввод данных" << endl;
	cout << "Введите число: ";
	cin >> choice;
	if (choice == 1) {
		cout << "Дефолтные значения." << endl;
	}
	else if (choice == 2) {
		int num;
		cout << "Рандомные значения." << endl;
		Grades.clear();
		srand(time(0));
		for (int i = 0; i < 10; i++) {
			Grades.push_back(rand() % 101);
		}
	}
	else if (choice == 3) {
		cout << "Ввод данных пользователем." << endl;
		int length;
		Names.clear();
		Grades.clear();
		cout << "Введите кол-во имен и их оценок: ";
		cin >> length;
		string name;
		int grade;
		for (int i = 0; i < length; i++) {
			cout << "Введите имя: ";
			cin >> name;
			Names.push_back(name);
			cout << "Введите оценку: ";
			cin >> grade;
			Grades.push_back(grade);
		}
	}
	else {
		cout << "Введено неправильное число." << endl;
	}
	for (int i = 0; i < Names.size(); i++) {
		cout << Names[i] << ": ";
		cout << Grades[i] << endl;
	}

	cout << "Среднее арифметическое оценок: " << avg_value(Grades) << endl;
	cout << "Медиана оценок: " << median(Grades) << endl;
	vector<int> mode_nums = mode(Grades);
	if (mode_nums[mode_nums.size() - 1] != 0) {
		cout << "Мода оценок: " << endl;
		for (int i = 0; i < mode_nums.size() - 1; i++) {
			cout << mode_nums[i] << endl;
		}
		cout << "Кол-во повторений: " << mode_nums[mode_nums.size() - 1] << endl;

		cout << "Имена, чьи оценки соответствуют моде: " << endl;
		for (int i = 0; i < mode_nums.size(); i++) {
			for (int j = 0; j < Grades.size(); j++) {
				if (Grades[j] == mode_nums[i]) {
					cout << Names[j] << ": " << Grades[j] << endl;
				}
			}
		}
	}
	else {
		cout << "В данной последовательности нету моды." << endl;
	}

	string answer;
	cout << "Если вы хотите добавить/удалить элемент в базу данных, пропишите соответствующую команду add/delete. Если вы не хотите ничего изменять - пропишите none." << endl;
	cout << "Введите команду: ";
	cin >> answer;
	while (answer != "none") {
		if (answer == "add") {
			Names = add_name(Names);
			Grades = add_grade(Grades);
		}
		else if (answer == "delete") {
			string name = "";
			int index = 0;
			cout << "Введите имя студента, которого вы хотите убрать из базы данных: ";
			cin >> name;
			for (int i = 0; i < Names.size(); i++) {
				if (name == Names[i]) {
					index = i;
					break;
				}
			}
			string deleted_name = Names[index];
			int deleted_grade = Grades[index];
 			Names = delete_name(Names, index);
			Grades = delete_grade(Grades, index);
			cout << "Успешно! Студент с именем " << deleted_name << " и оценкой " << delete_grade << " был удален из базы данных." << endl;
		}
		else if (answer == "none") {
			break;
		}
		else {
			cout << "Нет такой команды. Возможные команды: add/delete/none." << endl;
		}
		cout << "Введите команду: ";
		cin >> answer;
	}

	cout << "Вывод обновленной информации об измененной базы данных: " << endl;
	for (int i = 0; i < Grades.size(); i++) {
		cout << Names[i] << ": " << Grades[i] << endl;
	}
	cout << "Среднее арифметическое оценок: " << avg_value(Grades) << endl;
	cout << "Медиана оценок: " << median(Grades) << endl;
	vector<int> new_mode_nums = mode(Grades);
	if (new_mode_nums[new_mode_nums.size() - 1] != 0) {
		cout << "Мода оценок: " << endl;
		for (int i = 0; i < new_mode_nums.size() - 1; i++) {
			cout << new_mode_nums[i] << endl;
		}
		cout << "Кол-во повторений: " << new_mode_nums[new_mode_nums.size() - 1] << endl;

		cout << "Имена, чьи оценки соответствуют моде: " << endl;
		for (int i = 0; i < new_mode_nums.size(); i++) {
			for (int j = 0; j < Grades.size(); j++) {
				if (Grades[j] == new_mode_nums[i]) {
					cout << Names[j] << ": " << Grades[j] << endl;
				}
			}
		}
	}
	else {
		cout << "В данной последовательности нету моды." << endl;
	}

	return 0;
}

float avg_value(vector<int> Grades) {
	float tmp = 0.0;
	for (int i = 0; i < Grades.size(); i++) {
		tmp = tmp + Grades[i];
	}
	return (tmp / Grades.size());
}

int median(vector<int> Grades) {
	sort(Grades.begin(), Grades.end());
	if ((Grades.size() % 2) == 1) {
		return (Grades[(Grades.size() - 1) / 2]);
	}
	else {
		return (Grades[Grades.size() / 2 - 1] + Grades[Grades.size() / 2]) / 2;
	}
}

vector<int> mode(vector<int> Grades) {
	sort(Grades.begin(), Grades.end());
	Grades.push_back(101);
	int flag = 0;
	int count = 1;
	int max_count = 2;
	vector<int> mode_numbers;

	for (int i = 1; i < Grades.size(); i++) {
		if (Grades[i] == Grades[i - 1]) {
			count++;
		}
		else {
			if (count > max_count) {
				flag = 1;
				mode_numbers.clear();
				mode_numbers.push_back(Grades[i - 1]);
				max_count = count;
			}
			else if (count == max_count) {
				flag = 1;
				mode_numbers.push_back(Grades[i - 1]);
			}
			count = 1;
		}
	}

	if (flag == 0) {
		max_count = 0;
	}
	mode_numbers.push_back(max_count);
	return mode_numbers;
}

vector<string> add_name(vector<string> Names) {
	string name;
	cout << "Введите имя: ";
	cin >> name;
	Names.push_back(name);
	return Names;
}

vector<int> add_grade(vector<int> Grades) {
	int grade;
	cout << "Введите оценку: ";
	cin >> grade;
	Grades.push_back(grade);
	return Grades;
}

vector<string> delete_name(vector<string> Names, int index) {
	Names.erase(Names.begin() + index);
	return Names;
}

vector<int> delete_grade(vector<int> Grades, int index) {
	Grades.erase(Grades.begin() + index);
	return Grades;

}


/*
ПУНКТ 2 (все способы вывода данных)
Range-based for-loop:
	for (string i : Names) {
		cout << i << endl;
	}

	for (const int i : Grades) {
		cout << i << endl;
	}

с помощью итератора:
	for (vector<int>::iterator it = Grades.begin(); it != Grades.end(); it++) {
		cout << *it << endl;
	}

	for (vector<string>::iterator it = Names.begin(); it != Names.end(); it++) {
		cout << *it << endl;
	}

обычный индексовый цикл:
	for (int i = 0; i < Names.size(); i++) {
		cout << Names[i] << endl;
	}

	for (int i = 0; i < Grades.size(); i++) {
		cout << Grades[i] << endl;
	}

*/