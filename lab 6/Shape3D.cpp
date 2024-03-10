#include "Shape3D.h"


float Shape3D::GetVolume() {
    return volume;
}

void Shape3D::SetVolume(float v) {
    volume = v;
}

void Shape3D::ShowFigureVolume() {
    std::cout<<"Её объем: "<<volume<<"."<<std::endl;
}

bool Shape3D::operator< (const Shape3D& other_shape) const {
    return (volume < other_shape.volume);
}


bool Shape3D::operator> (const Shape3D& other_shape) const {
    return (volume > other_shape.volume);
}


bool Shape3D::operator== (const Shape3D& other_shape) const {
    return (volume == other_shape.volume);
}