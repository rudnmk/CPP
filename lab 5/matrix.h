#include <iostream>
#include <random>


class Matrix {
private:
    unsigned int n;
    unsigned int m;
    int** data;

public:
    Matrix();
    Matrix(unsigned int row, unsigned int col);

    Matrix &operator+ (const Matrix&) const;
    Matrix &operator- (const Matrix&) const;
    Matrix &operator* (const Matrix&) const;

    const Matrix &operator+= (const Matrix&);
    const Matrix &operator-= (const Matrix&);

    int operator== (const Matrix&) const;
    int operator!= (const Matrix&) const;
    
    int* operator[] (unsigned int index);

    friend std::ostream &operator<<(std::ostream &, const Matrix&);

    void randFill();

    ~Matrix();
};