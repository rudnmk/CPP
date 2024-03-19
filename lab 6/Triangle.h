#include "Shape2D.h"
#pragma once


class Triangle : virtual public Shape2D {
private: 
    float base;
    float height;
public:
    Triangle();
    Triangle(float a, float h);
    float GetBase();
    void SetBase(float b);
    float GetHeight();
    void SetHeight(float h);
    void CalculateArea();
    void Scale(float scaleFactor);
    void ShowInfo();
};