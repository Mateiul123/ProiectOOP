//
// Created by MateiPop on 11/14/2023.
//

#ifndef OOP_APP_H
#define OOP_APP_H

#include <vector>
#include "Masina.h"
#include "Customer.h"

class App {
private:
    static int contor;
    int nrMasini = 0;
    std::vector<Masina> masiniCumparate;
    float totalCost = 0;
    int totalHP = 0;
public:
    App();

    char firstQuestion();
    int sQuestion();
    void customizeCar(Masina &selectedCar);
    void buyCar(Masina &selectedCar);
    void displayPurchaseHistory();
    //void Hp-KwConv();



    const std::vector<std::string> availableColors = {"Galben", "Negru", "Rosu", "Albastru", "Verde"};
    const std::vector<float> availableEngineCapacities = {1.4, 1.6, 2.0, 2.5};
    std::vector<Masina> masini;
};

#endif //OOP_APP_H
