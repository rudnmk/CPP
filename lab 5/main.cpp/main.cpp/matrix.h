#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <math.h>
#include <format>


class Matrix {
private:
    unsigned int n;
    unsigned int m;
    int** data;

public:
    Matrix();
    Matrix(unsigned int row, unsigned int col);

    /*
    int getRow();
    int getCol();
    */

    Matrix& operator+ (const Matrix&) const;
    Matrix& operator- (const Matrix&) const;
    Matrix& operator* (const Matrix&) const;

    const Matrix& operator+= (const Matrix&);
    const Matrix& operator-= (const Matrix&);

    int operator== (const Matrix&) const;
    int operator!= (const Matrix&) const;

    int* operator[] (unsigned int index);

    friend std::ostream& operator<<(std::ostream&, const Matrix);

    void randFill();
    void zeroFill();
};