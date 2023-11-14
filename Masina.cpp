//
// Created by MateiPop on 11/14/2023.
//

#include "Masina.h"

#include <utility>

Masina::Masina(int tip, std::string color, float engine, float price, int hp)
        : tipMasina(tip), culoare(std::move(color)), motorizare(engine), pret(price), hp(hp) {}

void Masina::setCuloare(const std::string &color) {
    culoare = color;
}

void Masina::setMotorizare(float engine) {
    motorizare = engine;
}

float Masina::getCustomPrice() const {
    float customPrice = pret;

    if (culoare == "Negru") {
        customPrice += 10000.99;
    }
    else if (culoare == "Rosu") {
        customPrice += 800.99;
    }
    else if (culoare == "Albastru") {
        customPrice += 600.99;
    }
    else if (culoare == "Verde") {
        customPrice += 1250.99;
    } else if (culoare == "Galben"){
        customPrice += 500.99;
    }

    if (motorizare == 1.6) {
        customPrice += 1500.99;
    }
    else if (motorizare == 2.0) {
        customPrice += 3000.0;
    }
    else if (motorizare == 2.5) {
        customPrice += 5750.99;
    }
    else if (motorizare == 1.4){
        customPrice += 999.99;

    }
    return customPrice;
}

int Masina::getCustomHp() const {
    int customHp = hp;

    if (motorizare == 1.6) {
        customHp += 30;
    }
    else if (motorizare == 2.0) {
        customHp += 50;
    }
    else if (motorizare == 2.5) {
        customHp += 100;
    }
    else if (motorizare == 1.4){
        customHp+= 40;
    }

    return customHp;
}

std::ostream &operator<<(std::ostream &os, const Masina &masina) {
    os << "Tip_masina: " << masina.tipMasina
       << " culoare: " << masina.culoare
       << " capacitate: " << masina.motorizare
       << " Putere: " << masina.getCustomHp()
       << " pret: " << masina.getCustomPrice() << '\n';
    return os;
}
