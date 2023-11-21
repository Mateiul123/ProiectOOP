//
// Created by MateiPop on 11/14/2023.
//

#include "Customer.h"


Customer::Customer(const std::string& customerName, const std::string& contact)
        : name(customerName), contactInfo(contact) {}

void Customer::buyCar(const Masina& car) {
    purchasedCars.push_back(car);
    totalCost += car.getCustomPrice();
}

void Customer::displayPurchaseHistory() {
    std::cout << "Client: " << name << " mail: (" << contactInfo << ")\n";
    std::cout << "Masini cumparate: " << purchasedCars.size() << '\n';
    for (const auto& car : purchasedCars) {
        std::cout << car;
    }
    std::cout << "Cost total: " << totalCost << '\n';
}
