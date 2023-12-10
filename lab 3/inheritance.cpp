#include "Classes.h"


int main() {
    Company D("D", 2000, 100);
    Employee I(D.get_company_name(), "Ilya", 'M', 35, 2);
    Car C(I.get_employee_name(), D.get_company_name(), "Nissan", "123AU45", 5, 600, "TR", 140, 6);
    C.get_car_info();
    return 0;
}