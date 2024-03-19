#include "Shape.h"
#pragma once


class Shape2D : virtual public Shape {
private:
    float area;
    virtual void CalculateArea() = 0;
public:
    float GetArea();
    void SetArea(float a);
    void ShowFigureArea();
    bool operator> (const Shape2D&) const;
    bool operator< (const Shape2D&) const;
    bool operator== (const Shape2D&) const;
};