#include "Triangle.h"


Triangle::Triangle() {}

Triangle::Triangle(float a, float h) {
    SetBase(a);
    SetHeight(h);
    Triangle::CalculateArea();
    Shape::SetName("Треугольник.");
}

float Triangle::GetBase() {
    return base;
}

void Triangle::SetBase(float b) {
    base = b;
}

float Triangle::GetHeight() {
    return height;
}

void Triangle::SetHeight(float h) {
    height = h;
}


void Triangle::CalculateArea() {
    float s = 0.5 * base * height;
    Shape2D::SetArea(s);
}

void Triangle::Scale(float scaleFactor) {
    base = base * scaleFactor;
    height = height * scaleFactor;
    Triangle::CalculateArea();
}

void Triangle::ShowInfo() {
    Shape::ShowFigureName();
    std::cout<<"Основание треугольника: "<<base<<". Высота треугольника: "<<height<<"."<<std::endl;
    Shape2D::ShowFigureArea();
}