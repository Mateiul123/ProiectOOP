//
// Created by MateiPop on 11/14/2023.
//

#ifndef OOP_MASINA_H
#define OOP_MASINA_H

#include <iostream>
#include <string>

class Masina {
public:
    int tipMasina;
    std::string culoare;
    float motorizare;
    float pret;
    int hp;

    Masina(int tip, std::string color, float engine, float price, int hp);

    void setCuloare(const std::string &color);
    void setMotorizare(float engine);
    [[nodiscard]] float getCustomPrice() const;
    int getCustomHp() const;

    friend std::ostream &operator<<(std::ostream &os, const Masina &masina);
};



#endif //OOP_MASINA_H
