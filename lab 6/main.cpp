#include "Square.h"


int main() {
    setlocale(LC_ALL, "RUS");
    Square s(3);
    s.CalculateArea();
    s.ShowInfo();
    s.Scale(3);
    s.ShowInfo();

    return 0;
}