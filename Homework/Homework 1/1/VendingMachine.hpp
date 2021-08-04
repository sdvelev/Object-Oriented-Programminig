#pragma once
#pragma warning(disable: 4996)

#include<iostream>
#include<cstring>
#include"drink.hpp"

class VendingMachine {
public:
    VendingMachine();
    VendingMachine(const VendingMachine& from);
    VendingMachine& operator=(const VendingMachine& from);

    ~VendingMachine();

    bool add_drink(const Drink& to_add);
    int buy_drink(const char* drink_name, const double money);

    double get_income() const;

    void VendingMachineGrow();
   
private:
    int MAX_SIZE = 10;
    int counter = 0;
    double income;
    Drink* drink = new Drink[MAX_SIZE];
};
