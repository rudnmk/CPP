#include "Shape3D.h"
#pragma once


class TriangularPyramid : public Shape3D {
private:
    float triangle_base;
    float triangle_height;
    float height;
public:
    TriangularPyramid(float a, float h, float p_h);
    void CalculateVolume();
    void Scale(float scaleFactor);
    void ShowInfo();
};