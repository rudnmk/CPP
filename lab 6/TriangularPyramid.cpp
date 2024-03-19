#include "TriangularPyramid.h"


TriangularPyramid::TriangularPyramid(Triangle triangle, float p_h) {
    triangle_base = triangle.GetBase();
    triangle_height = triangle.GetHeight();
    height = p_h;
    TriangularPyramid::CalculateVolume();
    Shape::SetName("Треугольная пирамида");
}

TriangularPyramid::TriangularPyramid(float a, float h, float p_h) {
    triangle_base = a;
    triangle_height = h;
    height = p_h;
    TriangularPyramid::CalculateVolume();
    Shape::SetName("Треугольная пирамида");
}

void TriangularPyramid::CalculateVolume() {
    Triangle::CalculateArea();
    float s = Shape2D::GetArea();
    float v = (1 / 3) * s * height;
    Shape3D::SetVolume(v);
}

void TriangularPyramid::Scale(float scaleFactor) {
    triangle_base = triangle_base * scaleFactor;
    triangle_height = triangle_height * scaleFactor;
    height = height * scaleFactor;
    Triangle::SetBase(triangle_base);
    Triangle::SetHeight(triangle_height);
    Triangle::CalculateArea();
    TriangularPyramid::CalculateVolume();
}

void TriangularPyramid::ShowInfo() {
    Shape::ShowFigureName();
    std::cout<<"Информация об основании пирамиды: "<<std::endl;
    Triangle::ShowInfo();
    std::cout<<"Высота пирамиды: "<<height<<std::endl;
    Shape3D::ShowFigureVolume();
}