#include "Shape.h"


class Shape3D : virtual public Shape {
private:
    float volume;
    virtual void CalculateVolume() = 0;
public:
    float GetVolume();
    void SetVolume(float v);
    void ShowFigureVolume();
    bool operator> (const Shape3D&) const;
    bool operator< (const Shape3D&) const;
    bool operator== (const Shape3D&) const;
};