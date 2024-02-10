#include "dispenserType.h"
 
dispenserType::dispenserType() {
    numberOfItems = 50;
    cost = 50;
}
 
dispenserType::dispenserType(int N, int C) {
    numberOfItems = N;
    cost = C;
}
 
int dispenserType::getNoOfItems() {
    return numberOfItems;
}
 
int dispenserType::getCost() {
    return cost;
}
 
void dispenserType::makeSale() {
    numberOfItems--;
}