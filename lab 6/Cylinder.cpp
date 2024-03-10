#include "Cylinder.h"


Cylinder::Cylinder(float r, float h) {
    SetRadius(r);
    height = h;
    Shape::SetName("Цилиндр.");
}

void Cylinder::CalculateVolume() {
    Circle::CalculateArea();
    float s = Shape2D::GetArea();
    float v = s * height;
    Shape3D::SetVolume(v);
}

void Cylinder::Scale(float scaleFactor) {
    float r = Circle::GetRadius();
    Circle::SetRadius(r * scaleFactor);
    height = height * scaleFactor;
    Cylinder::CalculateVolume();
}

void Cylinder::ShowInfo() {
    Shape::ShowFigureName();
    std::cout<<"Информация об основании цилиндра: "<<std::endl;
    Circle::ShowInfo();
    std::cout<<"Высота цилиндра: "<<height<<std::endl;
    Shape3D::ShowFigureVolume();
}