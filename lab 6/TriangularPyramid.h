#include "Shape3D.h"
#include "Triangle.h"


class TriangularPyramid : public Shape3D, public Triangle {
private:
    float height;
public:
    TriangularPyramid(float a, float h, float p_h);
    void CalculateVolume();
    void Scale(float scaleFactor);
    void ShowInfo();
};