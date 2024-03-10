#include "Sphere.h"


Sphere::Sphere(float r) {
    radius = r;
    Sphere::CalculateVolume();
    Shape::SetName("Сфера.");
}

void Sphere::CalculateVolume() {
    float v = (4 / 3) * 3.14 * pow(radius, 3.0);
    Shape3D::SetVolume(v);
}

void Sphere::Scale(float scaleFactor) {
    radius = radius * scaleFactor;
    Sphere::CalculateVolume();
}

void Sphere::ShowInfo() {
    Shape::ShowFigureName();
    std::cout<<"Радиус сферы: "<<radius<<"."<<std::endl;
    Shape3D::ShowFigureVolume();
}