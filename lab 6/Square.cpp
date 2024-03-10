#include "Square.h"



Square::Square(float a) {
    side = a;
    Square::CalculateArea();
    Shape::SetName("Квадрат.");
}

void Square::CalculateArea() {
    float s = side * side;
    Shape2D::SetArea(s);
}

void Square::Scale(float scaleFactor) {
    side = side * scaleFactor;
    Square::CalculateArea();
}

void Square::ShowInfo() {
    Shape::ShowFigureName();
    std::cout<<"Сторона квадрата: "<<side<<"."<<std::endl;
    Shape2D::ShowFigureArea();
}