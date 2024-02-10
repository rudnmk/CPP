#include "cashRegister.h"
#include "dispenserType.h"
 
int getChoice(); //это тот же showSelection, только с получением ответа пользователя
void sellProduct(cashRegister count, dispenserType sweetsType);
 
int main()
{   
    cashRegister cashCounter(0);
    dispenserType candies(50, 50);
    dispenserType chips(30, 100);
    dispenserType gum(100, 1);
    dispenserType cookies(20, 150);
    std::cout<<"Hello! This machine sells candies, chips, gum and cookies!"<<std::endl;
    int choice = getChoice(); 
    while (choice != 0) {
        switch(choice) {
            case 1: 
                sellProduct(cashCounter, candies);
                break;
            case 2: 
                sellProduct(cashCounter, chips);
                break;                
            case 3: 
                sellProduct(cashCounter, gum);
                break;                
            case 4: 
                sellProduct(cashCounter, cookies);
                break;
            default:
                std::cout<<"There's nothing under this number."<<std::endl;
                break;
        choice = getChoice();
        }
    }
    
    
    return 0;
}
 
int getChoice() {
    int choice = 5;
    std::cout<<"Please, choose what you want, using numbers from 1 to 4, where:"<<std::endl;
    std::cout<<"1 - candies."<<std::endl;
    std::cout<<"2 - chips"<<std::endl;
    std::cout<<"3 - gum"<<std::endl;
    std::cout<<"4 - cookies"<<std::endl;
    std::cout<<"If you want to leave, just type 0 and I will give you your change."<<std::endl;
    std::cout<<"Now choose! Your choice: ";
    std::cin>>choice;
    return choice;
}
 
void sellProduct(cashRegister count, dispenserType sweetsType) {
    if (sweetsType.getNoOfItems() > 0) {
        int deposit;
        int deposit2;
        std::cout<<"There are "<<sweetsType.getNoOfItems()<<" items in total."<<std::endl;
        std::cout<<"The cost of the selected item is "<<sweetsType.getCost()<<" roubles. Please, deposit."<<std::endl;
        std::cout<<"How much would you like to deposit?  ";
        std::cin>>deposit;
        while (deposit < sweetsType.getCost()) {
            std::cout<<"There's not enough roubles to buy this product. Please, deposit more."<<std::endl;
            std::cout<<"Current cost: "<<sweetsType.getCost()<<"."<<std::endl;
            std::cout<<"Your deposit: "<<deposit<<"."<<std::endl;
            std::cout<<"Remaining cost: "<<(sweetsType.getCost() - deposit)<<"."<<std::endl;
            std::cout<<"How much would you like to deposit?  ";
            std::cin>>deposit2;
            deposit = deposit + deposit2;
        }
        count.acceptAmount(sweetsType.getCost());
        std::cout<<"There you go! Have a nice day!"<<std::endl;
        if (deposit > sweetsType.getCost()) {
            std::cout<<"Here's your change: "<<(deposit - sweetsType.getCost())<<std::endl;
            }
        
    }
    else {
        std::cout<<"I'm sorry! This product is out of stock. Please, choose something else."<<std::endl;
    }
}