#include "Square.h"
#include "Triangle.h"
#include "Circle.h"

#include "TriangularPyramid.h"
#include "Cylinder.h"
#include "Sphere.h"


int main() {
    setlocale(LC_ALL, "RUS");
    Square s(3);
    Circle c(4);
    Triangle t(3, 4);

    TriangularPyramid tp_1(3, 5, 4);
    TriangularPyramid tp_2(t, 6);
    Cylinder cy_1(4, 6);
    Cylinder cy_2(c, 3);
    Sphere sp(4);

    //проверка базовых функций
    s.ShowInfo();
    s.Scale(3);
    s.ShowInfo();

    tp_1.ShowInfo();
    tp_1.Scale(2);
    tp_1.ShowInfo();

    tp_2.ShowInfo();
    tp_2.Scale(2);
    tp_2.ShowInfo();

    sp.ShowInfo();
    sp.Scale(0.7);
    sp.ShowInfo();
    //----------------

    //проверка операторов сравнения
    std::cout<<(tp_1 < tp_2)<<std::endl;
    std::cout<<(s > t)<<std::endl;
    std::cout<<(sp == cy_1)<<std::endl;
    std::cout<<(c < t)<<std::endl;
    //----------------

    return 0;
}