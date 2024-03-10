#include "Shape3D.h"


class Sphere : public Shape3D {
private:
    float radius;
public:
    Sphere(float r);
    void CalculateVolume();
    void Scale(float scaleFactor);
    void ShowInfo();
};