#include "Square.h"
#include "Triangle.h"
#include "Circle.h"

#include "TriangularPyramid.h"
#include "Cylinder.h"
#include "Sphere.h"


int main() {
    setlocale(LC_ALL, "RUS");
    Square s(3.0);
    Circle c(4.0);
    Triangle t(3.0, 4.0);

    TriangularPyramid tp(3, 5, 4);
    Cylinder cy(4.0, 6.0);
    Sphere sp(4.0);

    //проверка базовых функций
    s.ShowInfo();
    s.Scale(3.0);
    s.ShowInfo();

    tp.ShowInfo();
    tp.Scale(2.0);
    tp.ShowInfo();

    sp.ShowInfo();
    sp.Scale(0.7);
    sp.ShowInfo();
    //----------------

    //проверка операторов сравнения
    std::cout<<(tp > cy)<<std::endl;
    std::cout<<(s > t)<<std::endl;
    std::cout<<(sp == cy)<<std::endl;
    std::cout<<(c < t)<<std::endl;
    //----------------

    return 0;
}