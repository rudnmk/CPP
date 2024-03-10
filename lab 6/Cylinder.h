#include "Shape3D.h"
#include "Circle.h"


class Cylinder : public Shape3D, public Circle {
private:
    float circle_radius;
    float height;
public:
    Cylinder(Circle& circle, float h);
    Cylinder(float r, float h);
    void CalculateVolume();
    void Scale(float scaleFactor);
    void ShowInfo();
};