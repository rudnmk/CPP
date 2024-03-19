#include "Circle.h"


Circle::Circle(float r) {
    SetRadius(r);
    Circle::CalculateArea();
    Shape::SetName("Круг.");
}

float Circle::GetRadius() {
    return radius;
}

void Circle::SetRadius(float r) {
    radius = r;
}

void Circle::CalculateArea() {
    float s = double(3.14) * radius * radius;
    Shape2D::SetArea(s);
}

void Circle::Scale(float scaleFactor) {
    radius = radius * scaleFactor;
    Circle::CalculateArea();
}

void Circle::ShowInfo() {
    Shape::ShowFigureName();
    std::cout<<"Радиус круга: "<<radius<<"."<<std::endl;
    Shape2D::ShowFigureArea();
}