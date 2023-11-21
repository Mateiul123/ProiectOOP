#include <iostream>
#include <string>
#include <fstream>
#include "Masina.h"
#include "Customer.h"
#include "App.h"



int main() {
    App app;
    Customer customer("Matei Pop", "matei-serban.pop@s.unibuc.ro");
    std::ofstream o ("Feedback.txt");
    std::string msg;

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
