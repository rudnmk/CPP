#include <iostream>
#include <string>
#include <ctime>

//Функция поиска второго максимума
template <typename T>
int find_second_max(T* ptr, int size) {
	T first_max_value = *(ptr);
	for (int step = 0; step < size; step++) {
		if (first_max_value < *(ptr + step)) {
			first_max_value = *(ptr + step);
		}
	}

	T second_max_value = *(ptr);
	int index = 0;

	for (int step = 0; step < size; step++) {
		if (*(ptr + step) != first_max_value) {
			if (second_max_value < *(ptr + step)) {
				second_max_value = *(ptr + step);
				index = step + 1;
			}
		}
	}

	return index;
}

//Шаблон класса Matrix
template <typename T>
class Matrix {
private:
	unsigned int n;
	unsigned int m;
	T** data;
public:
	Matrix() {
		n = 3;
		m = 3;
		data = new T* [m];
		for (int i = 0; i < 3; i++) {
			data[i] = new T[n];
		}
		srand(time(0));
	}

	Matrix(unsigned int row, unsigned int col) {
		n = row;ъ
		data = new T* [col];
		for (int i = 0; i < row; i++) {
			data[i] = new T[row];
		}
		srand(time(0));
	}

	Matrix& operator+ (const Matrix& other_matrix) const {
		Matrix result(n, m);
		if (n != other_matrix.n || m != other_matrix.m) {
			std::cout << "Невозможно провести операцию. Размеры матриц не совпадают. Возвращаю нулевую матрицу." << std::endl;
			result.zeroFill();
			return result;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				result.data[i][j] = data[i][j] + other_matrix.data[i][j];
			}
		}

		return result;
	}

	Matrix& operator- (const Matrix& other_matrix) const {
		Matrix result(n, m);
		if (n != other_matrix.n || m != other_matrix.m) {
			std::cout << "Невозможно провести операцию. Размеры матриц не совпадают. Возвращаю нулевую матрицу." << std::endl;
			result.zeroFill();
			return result;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				result.data[i][j] = data[i][j] - other_matrix.data[i][j];
			}
		}

		return result;
	}

	const Matrix& operator* (const Matrix& other_matrix) const {
		Matrix result(n, other_matrix.m);
		if (m != other_matrix.n) {
			std::cout << "Невозможно провести операцию. Размеры матриц не совпадают. Возвращаю нулевую матрицу." << std::endl;
			result.zeroFill();
			return result;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < other_matrix.m; j++) {
				result.data[i][j] = 0;
				for (int k = 0; k < other_matrix.n; k++) {
					result.data[i][j] += data[i][k] * other_matrix.data[k][j];
				}
			}
		}

		return result;
	}

	const Matrix& operator-= (const Matrix& other_matrix) {
		if (n != other_matrix.n || m != other_matrix.m) {
			std::cout << "Невозможно провести операцию. Размеры матриц не совпадают. Возвращаю нулевую матрицу." << std::endl;
			this->zeroFill();
			return *this;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				data[i][j] = data[i][j] - other_matrix.data[i][j];
			}
		}

		return *this;
	}

	int operator!= (const Matrix& other_matrix) const {
		int flag = 1;
		for (int i = 0; i < n; i++) {
			if (flag == 0) {
				break;
			}
			for (int j = 0; j < m; j++) {
				if (data[i][j] != other_matrix.data[i][j]) {
					flag = 0;
					break;
				}
			}
		}
		return flag;
	}

	int operator== (const Matrix& other_matrix) const {
		int flag = 1;
		for (int i = 0; i < n; i++) {
			if (flag == 0) {
				break;
			}
			for (int j = 0; j < m; j++) {
				if (data[i][j] != other_matrix.data[i][j]) {
					flag = 0;
					break;
				}
			}
		}
		return flag;
	}

	int* operator[] (unsigned int index) {
		return data[index];
	}

	void randFill() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				data[i][j] = T(rand() / 54.4);
			}
		}
	}

	void zeroFill() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				data[i][j] = 0;
			}
		}
	}

	friend std::ostream& operator<<(std::ostream& output, Matrix& matrix) {
		for (unsigned int i = 0; i < matrix.n; i++) {
			output << "[ ";
			for (unsigned int j = 0; j < matrix.m; j++) {
				output << matrix.data[i][j] << " ";
			}
			output << "]" << std::endl;
		}
		return output;
	}
};

//Шаблон класса Vector
template <typename T>
class Vector {
private:
	T vec[3];
public:
	Vector(T* ptr) {
		vec[0] = *(ptr);
		vec[1] = *(ptr + 1);
		vec[2] = *(ptr + 2);
	}

	T operator[] (int index) {
		return vec[index];
	}

	T scalar_product(Vector& other_vec) const {
		T result = (vec[0] * other_vec[0]) + (vec[1] * other_vec[1]) + (vec[2] * other_vec[2]);
		return result;
	}

	T vector_product(Vector& other_vec) const {
		T result = (vec[1] * other_vec[2] - vec[2] * other_vec[1]) - (vec[0] * other_vec[2] - vec[2] * other_vec[0]) + (vec[0] * other_vec[1] - vec[1] * other_vec[0]);
		return result;
	}
};

int main() {

	//проверка 1-го задания
	int int_array[5] = { 1, 2, 6, 11, 255 };
	int* int_ptr = int_array;
	int int_answer = find_second_max(int_ptr, 5);

	float float_array[8] = { 2.0, 1.6, 11.1, 24.414, 0.0, -3.4, 7.7, 100.0 };
	float* float_ptr = float_array;
	int float_answer = find_second_max(float_ptr, 8);

	float double_array[10] = { 2.0, 1.446, 11.42141, 24.414, 0.0, -3.4, 7.32137, 100.0, 14.444444, 13.666666666666666 };
	float* double_ptr = double_array;
	int double_answer = find_second_max(double_ptr, 10);

	std::string string_array[6] = { "array", "big number", "something", "A", "random stirng", "another random string" };
	std::string* string_ptr = string_array;
	int string_answer = find_second_max(string_ptr, 6);
	std::cout << "Index for int array = " << int_answer << "; index for float array = " << float_answer << "; index for double array = " << double_answer << "; index for string array = " << string_answer << std::endl;

	//проверка 2-го задания
	Matrix<int> A(4, 4);
	Matrix<int> B(4, 4);
	Matrix<int> C(4, 4);
	A.randFill();
	B.randFill();
	C = A + B;

	Matrix<float> a(4, 4);
	Matrix<float> b(4, 4);
	Matrix<float> c(4, 4);
	a.randFill();
	b.randFill();
	c = a + b;

	Matrix<double> Aa(3, 3);
	Matrix<double> Bb(3, 3);
	Matrix<double> Cc(3, 3);
	Aa.randFill();
	Bb.randFill();
	Cc = Aa + Bb;

	std::cout << "--------Matrix with int--------" << std::endl;
	std::cout << "Matrix A: " << std::endl;
	std::cout << A << std::endl;
	std::cout << "Matrix B: " << std::endl;
	std::cout << B << std::endl;
	std::cout << "Matrix C: " << std::endl;
	std::cout << C << std::endl;

	std::cout << "--------Matrix with float--------" << std::endl;
	std::cout << "Matrix A: " << std::endl;
	std::cout << a << std::endl;
	std::cout << "Matrix B: " << std::endl;
	std::cout << b << std::endl;
	std::cout << "Matrix C: " << std::endl;
	std::cout << c << std::endl;

	std::cout << "--------Matrix with double--------" << std::endl;
	std::cout << "Matrix A: " << std::endl;
	std::cout << Aa << std::endl;
	std::cout << "Matrix B: " << std::endl;
	std::cout << Bb << std::endl;
	std::cout << "Matrix C: " << std::endl;
	std::cout << Cc << std::endl;

	//проверка 3-го задания

	srand(time(0));
	int vector1[3] = { int(rand() % 100), int(rand() % 100), int(rand() % 100) };
	int vector2[3] = { int(rand() % 100), int(rand() % 100), int(rand() % 100) };
	/*
	float vector3[3] = { 23.3, 11.1, 11.1 };
	float vector4[3] = { 23.4, 21.1, 13.1 };
	double vector5[3] = { 23.1321133, 11.113321, 11.33231 };
	double vector6[3] = { 20.31233, 1.132112, 15.1634243 };
	*/
	float vector3[3] = { float((rand() % 100) * 11.0), float((rand() % 100) * 90.1), float((rand() % 100) * 134.4) };
	float vector4[3] = { float((rand() % 100) * 14.3), float((rand() % 100) * 4.4), float((rand() % 100) * 7.7) };
	double vector5[3] = { double((rand() % 100) * 13.14), double((rand() % 100) * 21.144), double((rand() % 100) * 40.412) };
	double vector6[3] = { double((rand() % 100) * 41.54), double((rand() % 100) * 11.31), double((rand() % 100) * 31.33)};

	int* ptr_to_vec1 = vector1;
	int* ptr_to_vec2 = vector2;
	float* ptr_to_vec3 = vector3;
	float* ptr_to_vec4 = vector4;
	double* ptr_to_vec5 = vector5;
	double* ptr_to_vec6 = vector6;

	Vector<int> vec_1(ptr_to_vec1);
	Vector<int> vec_2(ptr_to_vec2);
	Vector<float> vec_3(ptr_to_vec3);
	Vector<float> vec_4(ptr_to_vec4);
	Vector<double> vec_5(ptr_to_vec5);
	Vector<double> vec_6(ptr_to_vec6);

	std::cout << "Vector 1 = [ " << *(ptr_to_vec1) << ", " << *(ptr_to_vec1 + 1) << ", " << *(ptr_to_vec1 + 2) << " ]." << std::endl;
	std::cout << "Vector 2 = [ " << *(ptr_to_vec2) << ", " << *(ptr_to_vec2 + 1) << ", " << *(ptr_to_vec2 + 2) << " ]." << std::endl;
	std::cout << "Vector 3 = [ " << *(ptr_to_vec3) << ", " << *(ptr_to_vec3 + 1) << ", " << *(ptr_to_vec3 + 2) << " ]." << std::endl;
	std::cout << "Vector 4 = [ " << *(ptr_to_vec4) << ", " << *(ptr_to_vec4 + 1) << ", " << *(ptr_to_vec4 + 2) << " ]." << std::endl;
	std::cout << "Vector 5 = [ " << *(ptr_to_vec5) << ", " << *(ptr_to_vec5 + 1) << ", " << *(ptr_to_vec5 + 2) << " ]." << std::endl;
	std::cout << "Vector 6 = [ " << *(ptr_to_vec6) << ", " << *(ptr_to_vec6 + 1) << ", " << *(ptr_to_vec6 + 2) << " ]." << std::endl;
 
	std::cout << "--------Vectors with int--------" << std::endl;
	std::cout << "Scalar product of vec_1 and vec_2 = " << vec_1.scalar_product(vec_2) << std::endl;
	std::cout << "Vector product of vec_1 and vec_2 = " << vec_1.vector_product(vec_2) << std::endl;
	std::cout << "Vector product of vec_2 and vec_1 = " << vec_2.vector_product(vec_1) << std::endl;
	std::cout << "--------Vectors with float--------" << std::endl;
	std::cout << "Scalar product of vec_3 and vec_4 = " << vec_3.scalar_product(vec_4) << std::endl;
	std::cout << "Vector product of vec_3 and vec_4 = " << vec_3.vector_product(vec_4) << std::endl;
	std::cout << "Vector product of vec_4 and vec_3 = " << vec_4.vector_product(vec_3) << std::endl;
	std::cout << "--------Vectors with double--------" << std::endl;
	std::cout << "Scalar product of vec_5 and vec_6 = " << vec_5.scalar_product(vec_6) << std::endl;
	std::cout << "Vector product of vec_5 and vec_6 = " << vec_5.vector_product(vec_6) << std::endl;
	std::cout << "Vector product of vec_6 and vec_5 = " << vec_6.vector_product(vec_5) << std::endl;

	return 0;
}
