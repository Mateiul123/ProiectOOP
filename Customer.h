//
// Created by MateiPop on 11/14/2023.
//

#ifndef OOP_CUSTOMER_H
#define OOP_CUSTOMER_H

#include <string>
#include <vector>
#include "Masina.h"

class Customer {
private:
    std::string name;
    std::string contactInfo;
    std::vector<Masina> purchasedCars;
    float totalCost = 0;
    std::vector<Customer> Clients;

public:
    Customer(const std::string& customerName, const std::string& contact);

    void buyCar(const Masina& car);
    void displayPurchaseHistory();
};

#endif //OOP_CUSTOMER_H
