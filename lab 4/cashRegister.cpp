#include "cashRegister.h"
 
cashRegister::cashRegister() {
    cashOnHand = 500;
}
 
cashRegister::cashRegister(int cash) {
    cashOnHand = cash;
}
 
int cashRegister::getCurrentBalance() {
    return cashOnHand;
}
 
void cashRegister::acceptAmount(int amount) {
    cashOnHand = cashOnHand + amount;
}