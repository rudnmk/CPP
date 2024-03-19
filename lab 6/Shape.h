#include <iostream>
#include <string>
#pragma once


class Shape {
private:
    std::string name;
public:
    std::string GetName();
    void SetName(std::string n);
    void ShowFigureName();
    virtual void Scale(float scaleFactor) = 0;
    virtual void ShowInfo() = 0;
};