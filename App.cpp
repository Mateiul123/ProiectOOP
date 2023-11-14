//
// Created by MateiPop on 11/14/2023.
//

#include "App.h"
#include <algorithm>

int App::contor = 0;

App::App() {
    masini.emplace_back(1, "alb", 1.2, 10000,75);
    masini.emplace_back(2, "alb", 1.2, 20000,100);
    masini.emplace_back(3, "alb", 1.2, 25000,125);
    masini.emplace_back(4, "alb", 1.2, 30000,150);
    masini.emplace_back(5, "alb", 1.2, 60000,200);
    nrMasini = contor++;
}

char App::firstQuestion() {
    char yn;
    std::cout << "Doriti sa cumparati o masina? [Y/N]: ";
    std::cin >> yn;
    if (yn == 'Y')
        std::cout << "Bine ati venit!\n\n\n";
    return yn;
}

int App::sQuestion() {
    int selectedType = 0;
    std::cout << "Avem disponibile urmatoarele masini: \n\n\n";
    for (const auto &masina : masini) {
        std::cout << masina;
    }
    std::cout << "\n\n\n";

    std::cout << "Introduceti tipul masinii dorite (1-" << masini.size() << "): ";
    std::cin >> selectedType;

    if (selectedType < 1 || selectedType > masini.size()) {
        std::cout << "Tipul masinii introdus nu este valid. Va rugam selectati un numar intre 1 si " << masini.size() << ".\n";
        selectedType = 0;
    }

    return selectedType;
}

void App::customizeCar(Masina &selectedCar) {
    char customizationChoice;
    std::cout << "Doriti sa personalizati masina? [Y/N]: ";
    std::cin >> customizationChoice;

    if (customizationChoice == 'Y' || customizationChoice == 'y') {
        std::string customColor;
        float customEngineCapacity;

        std::cout << "Alegeti culoarea din " << availableColors.size() << " optiuni: ";
        for (const auto &color : availableColors) {
            std::cout << color << " ";
        }
        std::cout << "\nCuloare: ";
        std::cin >> customColor;

        if (std::find(availableColors.begin(), availableColors.end(), customColor) != availableColors.end()) {
            std::cout << "Alegeti capacitatea motorului din " << availableEngineCapacities.size()
                      << " optiuni: ";
            for (const auto &engine : availableEngineCapacities) {
                std::cout << engine << " ";
            }
            std::cout << "\nCapacitate motor: ";
            std::cin >> customEngineCapacity;

            if (std::find(availableEngineCapacities.begin(), availableEngineCapacities.end(), customEngineCapacity) !=
                availableEngineCapacities.end()) {
                selectedCar.setCuloare(customColor);
                selectedCar.setMotorizare(customEngineCapacity);
            } else {
                std::cout << "Capacitatea motorului aleasa nu este valida. Masina va ramane neschimbata.\n";
            }
        } else {
            std::cout << "Culoarea aleasa nu este valida. Masina va ramane neschimbata.\n";
        }
    } else {
        std::cout << "Ati ales o masina standard:\n";
    }
}

void App::buyCar(Masina &selectedCar) {
    masiniCumparate.push_back(selectedCar);
    totalCost += selectedCar.getCustomPrice();
    totalHP += selectedCar.getCustomPrice();
}

void App::displayPurchaseHistory() {
    std::cout << "Ati cumparat " << masiniCumparate.size() << " masini:\n";
    for (const auto &car : masiniCumparate) {
        std::cout << car;
    }
    std::cout << "Total de plata: " << totalCost << '\n';
}