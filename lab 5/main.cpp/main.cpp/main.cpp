#include "matrix.h"


int main() {

	setlocale(LC_ALL, "RU");
	Matrix A(3, 3);
	Matrix B(3, 3);
	Matrix SUM;
	Matrix DIF;
	Matrix PRD;

	//���������� ������ ���������� ������� �� 0 �� 99
	A.randFill();
	B.randFill();

	//�������� ������ ������
	std::cout << "������� �: " << std::endl;
	std::cout << A << std::endl;
	std::cout << "������� B: " << std::endl;
	std::cout << B << std::endl;
	std::cout << "----------------------" << std::endl;

	//�������� �� ������ ��������� +=
	std::cout << "���������� ������� � ��� ����� ������ � � B: " << std::endl;
	A += B;
	std::cout << A << std::endl;
	std::cout << "----------------------" << std::endl;

	//�������� �� ������ ��������� +
	std::cout << "��������� ����� � � B: " << std::endl;
	SUM = A + B;
	std::cout << SUM << std::endl;
	std::cout << "----------------------" << std::endl;

	//�������� �� ������ ��������� -
	std::cout << "��������� �������� � � B: " << std::endl;
	DIF = A - B;
	std::cout << DIF << std::endl;
	std::cout << "----------------------" << std::endl;

	//�������� �� ������ ��������� *
	std::cout << "��������� ������������ � � B: " << std::endl;
	PRD = A * B;
	std::cout << PRD << std::endl;
	std::cout << "----------------------" << std::endl;


	return 0;
}