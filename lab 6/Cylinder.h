#include "Shape3D.h"
#include "Circle.h"


class Cylinder : public Shape3D, public Circle {
private:
    float height;
public:
    Cylinder(float r, float h);
    void CalculateVolume();
    void Scale(float scaleFactor);
    void ShowInfo();
};