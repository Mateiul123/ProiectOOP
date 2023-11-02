#include <iostream>
#include <vector>

class masina{
protected:
    int Tip_masina;
    std::string culoare;
    float motorizare;
    float pret;
public:
    std::vector<std::vector<float>> Customizari;

    masina(const int &tipMasina, const std::string &culoare,
           const float &motorizare, unsigned int pret) :  Tip_masina(tipMasina), culoare(culoare),
                                                               motorizare(motorizare), pret(pret) {}
    virtual ~masina() {}

    void setTipMasina(const int &tipMasina) {
        Tip_masina = tipMasina;
    }

    void setCuloare(const std::string &culoare) {
        masina::culoare = culoare;
    }

        masina::motorizare = motorizare;
    }

    int getTipMasina() const {
        return Tip_masina;
    }

    const std::string &getCuloare() const {
        return culoare;
    }

    float getMotorizare() const {
        return motorizare;
    }

    masina& operator=(const masina& masina){
        this->culoare = culoare;
        this->Tip_masina = Tip_masina;
        this->motorizare = motorizare;
        this->pret = pret;
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &out, const masina &masina) {
        out << " Tip_masina: " << masina.Tip_masina << " culoare: " << masina.culoare << "pret: "<<masina.pret;
        return out;
    }

};
//"aplicatia" de baza
class app:public virtual masina{
private:
    static int cntMasini;
    const int nrMasini = 0;
    static int contor;
protected:
public:

    app(const int &tipMasina, const std::string &culoare, const float &motorizare, unsigned int pret,
        const int nrMasini) : masina(tipMasina, culoare, motorizare, pret), nrMasini(contor++) {}

    virtual ~app() {}

    static std::vector<masina> masini;

    static void afisare_masini(){
        std::cout<<"Avem disponibile urmatoarele masini: ";
        for(auto &masina : masini){
            std::cout << masina;
        }
    }
    static void first_question(){
        char yn;
        std::cout<<"Doriti sa cumparati o masina? [Y/N]: ";
        std::cin>>yn;
        if (yn == 'Y')
            std::cout<<"Bine ati venit!";
        else
            std::cout << "Ne pare rau vindem doar masini :(";

    }

    friend std::ostream &operator<<(std::ostream &os, const app &app){
        for(auto & masina : app.masini){
            os << masina ;
        }
        return os;
    }

};

int app::contor = 0;

class constructor_masina : public virtual masina, public virtual app{
public:

    void culoareCustom(const std::string& newcolor){
        culoare = newcolor;
    }
    void motorizareCustom(const std::string& newcolor){
        culoare = newcolor;
    }
};

int main() {
    static std::vector<masina> masini;
    masini.emplace_back(1,"alb",1.4,10000);
    masini.emplace_back(1,"alb",1.4,10000);
    masini.emplace_back(1,"alb",1.4,10000);
    masini.emplace_back(1,"alb",1.4,10000);
    masini.emplace_back(1,"alb",1.4,10000);

    app::first_question();
    app::afisare_masini();

    return 0;
}