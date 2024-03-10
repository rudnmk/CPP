#include "Cylinder.h"


Cylinder::Cylinder(Circle& circle, float h) {
    circle_radius = circle.GetRadius();
    height = h;
    Cylinder::CalculateVolume();
    Shape::SetName("Цилиндр.");
}

Cylinder::Cylinder(float r, float h) {
    circle_radius = r;
    height = h;
    Cylinder::CalculateVolume();
    Shape::SetName("Цилиндр.");
}

void Cylinder::CalculateVolume() {
    Circle::CalculateArea();
    float s = Shape2D::GetArea();
    float v = s * height;
    Shape3D::SetVolume(v);
}

void Cylinder::Scale(float scaleFactor) {
    circle_radius = circle_radius * scaleFactor;
    height = height * scaleFactor;
    Circle::SetRadius(circle_radius);
    Circle::CalculateArea();
    Cylinder::CalculateVolume();
}

void Cylinder::ShowInfo() {
    Shape::ShowFigureName();
    std::cout<<"Информация об основании цилиндра: "<<std::endl;
    Circle::ShowInfo();
    std::cout<<"Высота цилиндра: "<<height<<std::endl;
    Shape3D::ShowFigureVolume();
}