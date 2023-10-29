#include <iostream>
#include <vector>

class Masina{
private:
    static int contorId;
    const int id = 1;
    std::string Tip_masina;
    std::string culoare;
    std::string motorizare;
    unsigned int pret;
public:

    Masina() = default;

    ~Masina() = default;

    Masina(const int id) : id(contorId++){};


    void setTipMasina(const std::string &ltipMasina) {
        Tip_masina = ltipMasina;
    }

    void setCuloare(const std::string &lculoare) {
        Masina::culoare = lculoare;
    }

    void setMotorizare(const std::string &lmotorizare) {
        Masina::motorizare = lmotorizare;
    }


    friend std::ostream &operator<<(std::ostream &out, const Masina &masina) {
        out << "id: " << masina.id << " Tip_masina: " << masina.Tip_masina << " culoare: " << masina.culoare;
        return out;
    }

    const std::string &getTipMasina() const {
        return Tip_masina;
    }

    const std::string &getCuloare() const {
        return culoare;
    }

    const std::string &getMotorizare() const {
        return motorizare;
    }


    Masina& operator=(const Masina& masina){
        this->culoare = culoare;
        this->Tip_masina = Tip_masina;
        this->motorizare = motorizare;
        return *this;
    }

    Masina &operator++ (){
        contorId++;
    }
};

int Masina::contorId = 0;

class valabilitate{
private:
    std::vector<Masina> masini_valabile;
public:
    valabilitate() = default;
    virtual ~valabilitate() {}
    valabilitate(const std::vector<Masina> &lmasinivalabile){
        this->masini_valabile=lmasinivalabile;
    }
    friend std::ostream &operator<<(std::ostream &os, const valabilitate &valabil){
        for (auto &masina : valabil.masini_valabile) {
            os << masina;
        }
    }
};

int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}