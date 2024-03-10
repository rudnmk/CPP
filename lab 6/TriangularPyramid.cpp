#include "TriangularPyramid.h"


TriangularPyramid::TriangularPyramid(float a, float h, float p_h) {
    Triangle::SetBase(a);
    Triangle::SetHeight(h);
    height = p_h;
    Shape::SetName("Треугольная пирамида");
}

void TriangularPyramid::CalculateVolume() {
    Triangle::CalculateArea();
    float s = Shape2D::GetArea();
    float v = (1 / 3) * s * height;
    Shape3D::SetVolume(v);
}

void TriangularPyramid::Scale(float scaleFactor) {
    float b = Triangle::GetBase();
    float h = Triangle::GetHeight();
    Triangle::SetBase(b * scaleFactor);
    Triangle::SetHeight(h * scaleFactor);
    height = height * scaleFactor;
    TriangularPyramid::CalculateVolume();
}

void TriangularPyramid::ShowInfo() {
    Shape::ShowFigureName();
    std::cout<<"Информация об основании пирамиды: "<<std::endl;
    Triangle::ShowInfo();
    std::cout<<"Высота пирамиды: "<<height<<std::endl;
    Shape3D::ShowFigureVolume();
}