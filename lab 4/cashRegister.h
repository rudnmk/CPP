#include <iostream>
 
class cashRegister {
private:
    int cashOnHand;
public:
    cashRegister();
    cashRegister(int cash);
    int getCurrentBalance();
    void acceptAmount(int amount);
};