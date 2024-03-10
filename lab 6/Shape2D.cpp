#include "Shape2D.h"


float Shape2D::GetArea() {
    return area;
}

void Shape2D::SetArea(float a) {
    area = a;
}


void Shape2D::ShowFigureArea() {
    std::cout<<"Её площадь: "<<area<<std::endl;
}

bool Shape2D::operator< (const Shape2D& other_shape) const {
    return (area < other_shape.area);
}


bool Shape2D::operator> (const Shape2D& other_shape) const {
    return (area > other_shape.area);
}


bool Shape2D::operator== (const Shape2D& other_shape) const {
    return (area == other_shape.area);
}