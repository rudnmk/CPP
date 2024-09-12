#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> get_vector(std::string filename);
std::vector<int> reverse_vector(std::vector<int> vector);
int find_min(std::vector<int> vector);
std::vector<int> no_even_vector(std::vector<int> vector);
std::vector<int> sort_vector(std::vector<int> vector);
std::vector<int> insert_number(std::vector<int> vector);
int find(std::vector<int> vector);
std::vector<int> no_duplicates_vector(std::vector<int> vector);



int main() {
	setlocale(LC_ALL, "ru");
	std::vector<int> numbers;
	std::vector<int> reversed_numbers;
	std::vector<int> no_even_numbers;
	std::vector<int> sorted_numbers;
	std::vector<int> new_numbers;
	std::vector<int> new_sorted_numbers;
	std::vector<int> no_duplicate_numbers;
	//numbers = get_vector("vector.txt");
	numbers = get_vector("easyvector.txt");
	reversed_numbers = reverse_vector(numbers);
	no_even_numbers = no_even_vector(numbers);
	sorted_numbers = sort_vector(numbers);
	new_numbers = insert_number(numbers);
	new_sorted_numbers = insert_number(sorted_numbers);
	no_duplicate_numbers = no_duplicates_vector(new_numbers);

	std::cout << "numbers vector ||| reversed numbers vector ||| sorted numbers vector: " << std::endl;
	for (int i = 0; i < numbers.size() - 1; i++) {
		std::cout << numbers[i] << " ||| " << reversed_numbers[i] << " ||| " << sorted_numbers[i] << std::endl;
	}

	std::cout << "vector with no even numbers: " << std::endl;

	for (int i = 0; i < no_even_numbers.size(); i++) {
		std::cout << no_even_numbers[i] << std::endl;
	}
	
	std::cout << "The lowest number in vector = " << find_min(numbers) << std::endl;

	std::cout << "new non-sorted vector ||| new sorted vector: " << std::endl;
	for (int i = 0; i < new_numbers.size() - 1; i++) {
		std::cout << new_numbers[i] << " ||| " << new_sorted_numbers[i] << std::endl;
	}

	std::cout << "vector = numbers => value on chosen index = " << find(numbers) << std::endl;
	std::cout << "vector = new_sorted_numbers => value on chosen index = " << find(new_sorted_numbers) << std::endl;

	std::cout << "vector without duplicates: " << std::endl; 
	for (int i = 0; i < no_duplicate_numbers.size(); i++) {
		std::cout << no_duplicate_numbers[i] << std::endl;
	}

	return 0;
}


std::vector<int> get_vector(std::string filename) {
	std::ifstream file;
	file.open(filename);
	std::vector<int> vector;
	char ch;
	int num;
	std::string snum = "";
	while (file.get(ch)) {
		if (ch != ' ') {
			snum += ch;
		}
		else {
			num = std::stoi(snum);
			vector.push_back(num);
			snum = "";
		}
	}
	num = std::stoi(snum);
	vector.push_back(num);
	vector.push_back(0);
	return vector;
}

std::vector<int> reverse_vector(std::vector<int> vector) {
	std::vector<int> reversed_vector;
	for (int iter = 1; iter <= vector.size() - 1; iter++) {
		reversed_vector.push_back(vector[vector.size() - (iter + 1)]);
	}
	return reversed_vector;
}

int find_min(std::vector<int> vector) {
	int min = pow(10, 9);
	for (int iter = 0; iter < vector.size() - 1; iter++) {
		if (vector[iter] < min) {
			min = vector[iter];
		}
	}
	return min;
}

std::vector<int> no_even_vector(std::vector<int> vector) {
	std::vector<int> no_even_numbers;
	for (int iter = 0; iter < vector.size() - 1; iter++) {
		if (vector[iter] % 2 != 0) {
			no_even_numbers.push_back(vector[iter]);
		}
	}
	return no_even_numbers;
}

std::vector<int> sort_vector(std::vector<int> vector) {
	std::vector<int> sorted_vector;
	std::string answer;
	vector.pop_back();
	std::cout << "Ââåäèòå 'lower', åñëè õîòèòå îòñîðòèðîâàòü âåêòîð ïî óáûâàíèþ è 'greater' - åñëè ïî âîçðàñòàíèþ. Ââîä: ";
	while (true) {
		std::cin >> answer;
		if (answer == "lower") {
			std::sort(vector.begin(), vector.end(), std::greater<int>());
			vector.push_back(1);
			break;
		}
		else if (answer == "greater") {
			std::sort(vector.begin(), vector.end());
			vector.push_back(2);
			break;
		}
		else {
			std::cout << "Íåâåðíî ââåäåíà êîìàíäà. Ïîâòîðèòå ïîïûòêó. Ââîä: ";
		}
	}
	sorted_vector.swap(vector);
	return sorted_vector;
}

std::vector<int> insert_number(std::vector<int> vector) {
	std::vector<int>::iterator iter = vector.begin();
	std::vector<int> new_vector;
	int index;
	int number;
	std::cout << "Ââåäèòå ïîçèöèþ, íà êîòîðóþ âû õîòèòå âñòàâèòü ýëåìåíò: ";
	while (true) {
		std::cin >> index;
		std::cin.ignore();
		if (index > 0 && index < vector.size()) {
			break;
		}
		else {
			std::cout << "Âû âûøëè çà ïðåäåëû âåêòîðà. Ïîâòîðèòå ïîïûòêó: ";
		}
	}
	std::cout << "Ââåäèòå ÷èñëî, êîòîðîå âû õîòèòå âñòàâèòü: ";
	std::cin >> number;
	index--;
	vector.insert(iter + index, number);
	std::vector<int>::iterator new_iter = vector.end();
	if (*(new_iter) == 1) {
		std::sort(vector.begin(), vector.end(), std::greater<int>());
	}
	else if (*(new_iter) == 2) {
		std::sort(vector.begin(), vector.end());
	}

	new_vector.swap(vector);
	return new_vector;
}

int find(std::vector<int> vector) {
	int index;
	std::vector<int>::iterator iter = vector.begin();
	std::cout << "Ââåäèòå èíäåêñ ýëåìåíòà, êîòîðûé âû õîòèòå ïîëó÷èòü: ";
	while (true) {
		std::cin >> index;
		if (index > 0 && index < vector.size()) {
			break;
		}
		else {
			std::cout << "Âû âûøëè çà ïðåäåëû âåêòîðà. Ïîâòîðèòå ïîïûòêó: ";
		}
	}
	index--;
	return *(iter + index);
}

std::vector<int> no_duplicates_vector(std::vector<int> vector) {
	std::vector<int> only_uniques_vector;
	vector.pop_back();
	std::vector<int>::iterator iter = vector.begin();
	only_uniques_vector.push_back(*(iter));
	while (iter != vector.end()) {
		int uniqueness = 1;
		for (int i = 0; i < only_uniques_vector.size(); i++) {
			if (*(iter) == only_uniques_vector[i]) {
				uniqueness = 0;
				break;
			}
		}
		if (uniqueness) {
			only_uniques_vector.push_back(*(iter));
		}
		++iter;
	}
	return only_uniques_vector;
}
