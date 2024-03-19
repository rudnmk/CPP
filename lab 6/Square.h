#include "Shape2D.h"
#pragma once


class Square : public Shape2D {
private:
    float side;
public:
    Square(float a);
    void CalculateArea();
    void Scale(float scaleFactor);
    void ShowInfo();
};