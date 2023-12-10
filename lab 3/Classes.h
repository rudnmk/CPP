#pragma once

#include <iostream>
#include <string>

using namespace std;


class Company{
private:
    string company_name;
    int creation_year;
    int employee_count;

public:
    Company(string cn, int year, int count) 
    : company_name(cn), creation_year(year), employee_count(count) {}

    string get_company_name() {
        return company_name;
    }

    void get_company_info() {
        cout << "Company '" << company_name << "' was created in " << creation_year << " and now has " << employee_count << " employee(s)." << endl;
    }

    void change_employee_count(int new_count) {
        this->employee_count = new_count;
    } 
};


class Employee{
private:
    string company_name;
    string employee_name;
    char sex;
    int age;
    int how_long_works;

public:
    Employee(string comp_name, string n, char s, int a, int hlw) 
    : company_name(comp_name), employee_name(n), sex(s), age(a), how_long_works(hlw) {}

    void get_employee_info() {
        cout << "Employee " << employee_name << " is " << age << " years old. Sex: " << sex << ". Currently works for " << company_name << " company for " << how_long_works << " year(s)." << endl;
    }

    void another_new_year() {
        this->how_long_works++;
    }

    string get_employee_name() {
        return employee_name;
    }
};


class Vehicle{
protected:
    string employee_name;
    string company_name;
    string brand;
    string registration_number;
    int age_of_exploitation;
    int weight;

public:
    Vehicle(string empl_name, string comp_name, string br, string numb, int aoe, int w)
    : employee_name(empl_name), company_name(comp_name), brand(br), registration_number(numb), age_of_exploitation(aoe), weight(w) {}

    void get_vehicle_info() {
        cout << brand << " brand vehicle is now used by " << employee_name << " working at " << company_name << " company." << endl;
        cout << "Registration number: " << registration_number << "." << endl;
        cout << "Age of exploitation: "<< age_of_exploitation << "." << endl;
        cout << "Weight: " << weight << "." << endl;
    }
};


class Car : public Vehicle {
private:
    string transmission;
    int max_speed;
    int number_of_seats;

public:
    Car(string empl_name, string comp_name, string br, string numb, int aoe, int w, string tr, int max_s, int num_of_s) 
    : Vehicle(empl_name, comp_name, br, numb, aoe, w), transmission(tr), max_speed(max_s), number_of_seats(num_of_s) {}

    void get_car_info() {
        get_vehicle_info();
        cout << "Transmission: " << transmission << "." << endl;
        cout << "Max speed: " << max_speed << "." << endl;
        cout << "Number of seats: " << number_of_seats << "." << endl;
    }


};


class Trunk : public Vehicle {
private: 
    int load_capacity;
    int volume;
    
public:
    Trunk(string empl_name, string comp_name, string br, string numb, int aoe, int w, int lc, int vol) 
    : Vehicle(empl_name, comp_name, br, numb, aoe, w), load_capacity(lc), volume(vol) {}

    void get_trunk_info() {
        get_vehicle_info();
        cout << "Mass/Load capacity: " << load_capacity << "." << endl;
        cout << "Volume: " << volume << "." << endl;
    }
};