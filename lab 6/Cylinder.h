#include "Shape3D.h"
#pragma once


class Cylinder : public Shape3D {
private:
    float circle_radius;
    float height;
public:
    Cylinder(float r, float h);
    void CalculateVolume();
    void Scale(float scaleFactor);
    void ShowInfo();
};