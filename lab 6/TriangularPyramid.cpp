#include "TriangularPyramid.h"


TriangularPyramid::TriangularPyramid(float a, float h, float p_h) {
    triangle_base = a;
    triangle_height = h;
    height = p_h;
    TriangularPyramid::CalculateVolume();
    Shape::SetName("Треугольная пирамида");
}

void TriangularPyramid::CalculateVolume() {
    float s = 0.5 * triangle_base * triangle_height;
    float v = (1.0 / 3.0) * s * height;
    Shape3D::SetVolume(v);
}

void TriangularPyramid::Scale(float scaleFactor) {
    triangle_base = triangle_base * scaleFactor;
    triangle_height = triangle_height * scaleFactor;
    height = height * scaleFactor;
    TriangularPyramid::CalculateVolume();
}

void TriangularPyramid::ShowInfo() {
    Shape::ShowFigureName();
    std::cout<<"Информация об основании пирамиды: "<<std::endl;
    std::cout<<"Основание треугольника: "<<triangle_base<<". Высота треугольника: "<<triangle_height<<std::endl;
    std::cout<<"Высота пирамиды: "<<height<<std::endl;
    Shape3D::ShowFigureVolume();
}