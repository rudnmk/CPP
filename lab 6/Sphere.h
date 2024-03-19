#include "Shape3D.h"
#pragma once


class Sphere : public Shape3D {
private:
    float radius;
public:
    Sphere(float r);
    void CalculateVolume();
    void Scale(float scaleFactor);
    void ShowInfo();
};