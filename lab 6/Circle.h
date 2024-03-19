#include "Shape2D.h"
#pragma once


class Circle : public Shape2D {
private: 
    float radius;
public:
    Circle();
    Circle(float r);
    float GetRadius();
    void SetRadius(float r);
    void CalculateArea();
    void Scale(float scaleFactor);
    void ShowInfo();
};