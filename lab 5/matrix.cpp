#include "matrix.h"


Matrix::Matrix() {
    n = 3;
    m = 3;
    for (int i = 0; i < 3; i++) {
        data[i] = new int[i];
    }
    
}

Matrix::Matrix(unsigned int row, unsigned int col) {
    n = row;
    m = col;
    data = new int*[col];
    for (int i = 0; i < row; i++) {
        data[i] = new int[i];
    }
}

Matrix &Matrix::operator+ (const Matrix& other_matrix) const{
    Matrix result(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result.data[i][j] = data[i][j] + other_matrix.data[i][j];
        }
    }
    
    return result;
}

Matrix &Matrix::operator- (const Matrix& other_matrix) const{
    Matrix result(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result.data[i][j] = data[i][j] - other_matrix.data[i][j];
        }
    }

    return result;
}

Matrix &Matrix::operator* (const Matrix& other_matrix) const{
    Matrix result(n, m);
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

const Matrix &Matrix::operator+= (const Matrix& other_matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            data[i][j] = data[i][j] + other_matrix.data[i][j];
        }
    }

    return *this;
}

const Matrix &Matrix::operator-= (const Matrix& other_matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            data[i][j] = data[i][j] - other_matrix.data[i][j];
        }
    }

    return *this;
}

int Matrix::operator!= (const Matrix& other_matrix) const{
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

int Matrix::operator== (const Matrix& other_matrix) const{
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
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,9);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            data[i][j] = dist6(rng);
        }
    }
}

std::ostream &operator<<(std::ostream &output, const Matrix& matrix) {
    for (unsigned int i = 0; i < matrix.n; i++) {
        output << "[  ";
        for (unsigned int j = 0; j < matrix.m; j++) {
            output << matrix.data[i][j] << ", ";
        }
        output << "  ]" << std::endl;
    }
    return output;
}

Matrix::~Matrix() {
    for (int i = 0; i < n; i++) {
        delete data[i];
    }
    delete data;
}