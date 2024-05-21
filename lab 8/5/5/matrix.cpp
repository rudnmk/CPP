#include "matrix.h"


Matrix::Matrix() {
    n = 3;
    m = 3;
    data = new int* [m];
    for (int i = 0; i < 3; i++) {
        data[i] = new int[n];
    }
    srand(time(0));

}

Matrix::Matrix(unsigned int row, unsigned int col) {
    n = row;
    m = col;
    data = new int* [col];
    for (int i = 0; i < row; i++) {
        data[i] = new int[row];
    }
    srand(time(0));
}

Matrix& Matrix::operator+ (const Matrix& other_matrix) const {
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

Matrix& Matrix::operator- (const Matrix& other_matrix) const {
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

Matrix& Matrix::operator* (const Matrix& other_matrix) const {
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

const Matrix& Matrix::operator+= (const Matrix& other_matrix) {
    if (n != other_matrix.n || m != other_matrix.m) {
        std::cout << "Невозможно провести операцию. Размеры матриц не совпадают. Возвращаю нулевую матрицу." << std::endl;
        this->zeroFill();
        return *this;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            data[i][j] = data[i][j] + other_matrix.data[i][j];
        }
    }

    return *this;
}

const Matrix& Matrix::operator-= (const Matrix& other_matrix) {
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

int Matrix::operator!= (const Matrix& other_matrix) const {
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

int Matrix::operator== (const Matrix& other_matrix) const {
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


int* Matrix::operator[] (unsigned int index) {
    return data[index];
}

void Matrix::randFill() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            data[i][j] = float(rand() % 100);
        }
    }
}

void Matrix::zeroFill() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            data[i][j] = 0;
        }
    }
}

std::ostream& operator<<(std::ostream& output, const Matrix matrix) {
    for (unsigned int i = 0; i < matrix.n; i++) {
        output << "[ ";
        for (unsigned int j = 0; j < matrix.m; j++) {
            output << matrix.data[i][j] << " ";
        }
        output << "]" << std::endl;
    }
    return output;
}