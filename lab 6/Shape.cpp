#include "Shape.h"
setlocale(LC_ALL, "RUS");

std::string Shape::GetName() {
    return name;
}

void Shape::SetName(std::string n) {
    name = n;
}

void Shape::ShowFigureName() {
    std::cout<<"Фигура: "<<name<<std::endl;
}