#include "matrix.h"


int main() {

	setlocale(LC_ALL, "RU");
	Matrix A(3, 3);
	Matrix B(3, 3);
	Matrix SUM;
	Matrix DIF;
	Matrix PRD;

	//Заполнение матриц рандомными числами от 0 до 99
	A.randFill();
	B.randFill();

	//Проверка вывода матриц
	std::cout << "Матрица А: " << std::endl;
	std::cout << A << std::endl;
	std::cout << "Матрица B: " << std::endl;
	std::cout << B << std::endl;
	std::cout << "----------------------" << std::endl;

	//Проверка на работу оператора +=
	std::cout << "Перезапись матрицы А как сумму матриц А и B: " << std::endl;
	A += B;
	std::cout << A << std::endl;
	std::cout << "----------------------" << std::endl;

	//Проверка на работу оператора +
	std::cout << "Результат суммы А и B: " << std::endl;
	SUM = A + B;
	std::cout << SUM << std::endl;
	std::cout << "----------------------" << std::endl;

	//Проверка на работу оператора -
	std::cout << "Результат разности А и B: " << std::endl;
	DIF = A - B;
	std::cout << DIF << std::endl;
	std::cout << "----------------------" << std::endl;

	//Проверка на работу оператора *
	std::cout << "Результат произведения А и B: " << std::endl;
	PRD = A * B;
	std::cout << PRD << std::endl;
	std::cout << "----------------------" << std::endl;


	return 0;
}