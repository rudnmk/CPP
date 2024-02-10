#include <iostream>
 
class dispenserType {
private:
    int numberOfItems;
    int cost;
public:
    dispenserType();
    dispenserType(int N, int C);
    int getNoOfItems();
    int getCost();
    void makeSale();
};