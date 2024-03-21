#include "Cylinder.h"


Cylinder::Cylinder(float r, float h) {
    circle_radius = r;
    height = h;
    Cylinder::CalculateVolume();
    Shape::SetName("Цилиндр.");
}

void Cylinder::CalculateVolume() {
    float s = 3.14 * circle_radius * circle_radius;
    float v = s * height;
    Shape3D::SetVolume(v);
}

void Cylinder::Scale(float scaleFactor) {
    circle_radius = circle_radius * scaleFactor;
    height = height * scaleFactor;
    Cylinder::CalculateVolume();
}

void Cylinder::ShowInfo() {
    Shape::ShowFigureName();
    std::cout<<"Информация об основании цилиндра: "<<std::endl;
    std::cout<<"Радиус круга: "<<circle_radius<<std::endl;
    std::cout<<"Высота цилиндра: "<<height<<std::endl;
    Shape3D::ShowFigureVolume();
}