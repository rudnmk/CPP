#include <iostream>
using namespace std;

/*
C - C++

int *ptr = (int*)malloc(sizeof(int)) - int* arr = new int
int *ptrArr = (int*)malloc(sizeof(int) * N) - new int[N]
free(ptr) - delete ptr
free(ptrArr) - delete[] ptr

В языке C++ обязательно надо освобождать динамическую память для оптимизации работы программы. Если есть выделение памяти через new, значит, должен быть и delete.
Нельзя освобождать одну и ту же выделенную память дважды. Освобождение уже несуществующей ячейки памяти может привести к непредсказуемым последствиям.
Нельзя удалить невыделенную память, т.к. удалять нечего.

*/

int main() {
	setlocale(LC_ALL, "RU");
	short rows;
	short step = 1;
	unsigned int number;
	cout << "Введите число строк: ";
	cin >> rows;
	float length = ((1 + rows) * rows) / 2;
	int* arr = new int[length];
	int tmp1 = 1;
	int tmp2 = 1;
	*(arr) = tmp1;
	*(arr + 1) = tmp2;
	for (int i = 2; i < length; i++) {
		*(arr + i) = tmp1 + tmp2;
		if (i % 2 == 0) {
			tmp1 = tmp1 + tmp2;
		}
		else {
			tmp2 = tmp1 + tmp2;
		}
	}

	cout << "Результат:\n";
	int cnst = 0;
	for (int i = 0; i < rows; i++) {
		cout << string(rows - i, ' ');
		for (int j = 0; j < step; j++) {
			cout << *(arr + j + cnst) << " ";
		}
		cnst = cnst + step;
		cout << "\n";
		step++;
	}
	delete[] arr;
	return 0;
}