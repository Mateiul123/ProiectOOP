#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Masina {
public:
    int tipMasina;
    std::string culoare;
    float motorizare;
    float pret;

    Masina(int tip, const std::string &color, float engine, float price)
            : tipMasina(tip), culoare(color), motorizare(engine), pret(price) {}

    void setCuloare(const std::string &color) {
        culoare = color;
    }

    void setMotorizare(float engine) {
        motorizare = engine;
    }

    float getCustomPrice() const {
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

    friend std::ostream &operator<<(std::ostream &os, const Masina &masina) {
        os << "Tip_masina: " << masina.tipMasina
           << " culoare: " << masina.culoare
           << " capacitate: " << masina.motorizare
           << " pret: " << masina.getCustomPrice() << '\n';
        return os;
    }
};

class Customer {
private:
    std::string name;
    std::string contactInfo;
    std::vector<Masina> purchasedCars;
    float totalCost = 0;

public:
    Customer(const std::string& customerName, const std::string& contact) : name(customerName), contactInfo(contact) {}

    void buyCar(const Masina& car) {
        purchasedCars.push_back(car);
        totalCost += car.getCustomPrice();
    }

    void displayPurchaseHistory() {
        std::cout << "Client: " << name << "mail: (" << contactInfo << ")\n";
        std::cout << "Masini cumparate: " << purchasedCars.size() << '\n';
        for (const auto& car : purchasedCars) {
            std::cout << car;
        }
        std::cout << "Cost total: " << totalCost << '\n';
    }
};

class App {
private:
    static int contor;
    int nrMasini = 0;
    std::vector<Masina> masiniCumparate;
    float totalCost = 0;

public:
    App() {
        masini.emplace_back(1, "alb", 1.2, 10000);
        masini.emplace_back(2, "alb", 1.2, 20000);
        masini.emplace_back(3, "alb", 1.2, 25000);
        masini.emplace_back(4, "alb", 1.2, 30000);
        masini.emplace_back(5, "alb", 1.2, 60000);
        nrMasini = contor++;
    }

    char firstQuestion() {
        char yn;
        std::cout << "Doriti sa cumparati o masina? [Y/N]: ";
        std::cin >> yn;
        if (yn == 'Y')
            std::cout << "Bine ati venit!\n\n\n";
        return yn;
    }

    int sQuestion() {
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

    void customizeCar(Masina &selectedCar) {
        char customizationChoice;
        std::cout << "Doriti sa personalizati masina? [Y/N]: ";
        std::cin >> customizationChoice;

        if (customizationChoice == 'Y') {
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

    void buyCar(Masina &selectedCar) {
        masiniCumparate.push_back(selectedCar);
        totalCost += selectedCar.getCustomPrice();
    }

    void displayPurchaseHistory() {
        std::cout << "Ati cumparat " << masiniCumparate.size() << " masini:\n";
        for (const auto &car : masiniCumparate) {
            std::cout << car;
        }
        std::cout << "Total de plata: " << totalCost << '\n';
    }

    const std::vector<std::string> availableColors = {"Galben", "Negru", "Rosu", "Albastru", "Verde"};
    const std::vector<float> availableEngineCapacities = {1.4, 1.6, 2.0, 2.5};
    std::vector<Masina> masini;
};

int App::contor = 0;

int main() {
    App app;
    Customer customer("Matei Pop", "matei-serban.pop@s.unibuc.ro");

    while (app.firstQuestion() == 'Y') {
        int selectedType = app.sQuestion();

        if (selectedType != 0) {
            Masina selectedCar = app.masini[selectedType - 1];
            std::cout << "Ati selectat masina de tip " << selectedCar.tipMasina <<std::endl;

            app.customizeCar(selectedCar);
            app.buyCar(selectedCar);
            customer.buyCar(selectedCar);
        } else {
            std::cout << "Selectia nu este valida. Aplicatia se va inchide.\n";
        }
    }

    std::cout<<"\n\n\n";

    app.displayPurchaseHistory();

    std::cout<<"\n\n\n";

    customer.displayPurchaseHistory();

    return 0;
}
