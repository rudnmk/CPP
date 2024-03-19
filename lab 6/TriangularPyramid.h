#include "Shape3D.h"
#include "Triangle.h"
#pragma once


class TriangularPyramid : public Shape3D, public Triangle {
private:
    float triangle_base;
    float triangle_height;
    float height;
public:
    TriangularPyramid(Triangle triangle, float p_h);
    TriangularPyramid(float a, float h, float p_h);
    void CalculateVolume();
    void Scale(float scaleFactor);
    void ShowInfo();
};