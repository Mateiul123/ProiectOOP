#include <iostream>
#include <vector>

class Masina{
private:
    static int contorId;
    const int id = 1;

class masina{
    static unsigned int contorID;
    const unsigned int ID;
    std::string Tip_masina;
    std::string culoare;
    std::string motorizare;
    unsigned int pret;
public:
    masina(const unsigned int id, const std::string &tipMasina, const std::string &culoare,
           const std::string &motorizare, unsigned int pret) : ID(contorID++), Tip_masina(tipMasina), culoare(culoare),
                                                               motorizare(motorizare), pret(pret) {}
    virtual ~masina() {}

    Masina() = default;

    ~Masina() = default;

    Masina(const int id) : id(contorId++){};


    void setTipMasina(const std::string &ltipMasina) {
        Tip_masina = ltipMasina;
    static void setContorId(unsigned int contorId) {
        contorID = contorId;
    }

    void setCuloare(const std::string &lculoare) {
        Masina::culoare = lculoare;
    void setTipMasina(const std::string &tipMasina) {
        Tip_masina = tipMasina;
    }

    void setCuloare(const std::string &culoare) {
        masina::culoare = culoare;
    }


    friend std::ostream &operator<<(std::ostream &out, const Masina &masina) {
        out << "id: " << masina.id << " Tip_masina: " << masina.Tip_masina << " culoare: " << masina.culoare;
        return out;
    void setMotorizare(const std::string &motorizare) {
        masina::motorizare = motorizare;
    }

    const std::string &getTipMasina() const {
        return Tip_masina;
    void setPret(unsigned int pret) {
        masina::pret = pret;
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
        this->pret = pret;
        return *this;
    }

    Masina &operator++ (){
        contorId++;
    friend std::ostream &operator<<(std::ostream &out, const masina &masina) {
        out << " Tip_masina: " << masina.Tip_masina << " culoare: " << masina.culoare << "pret: "<<masina.pret;
        return out;
    }
    void custom_color(const std::string& newcolor){
        culoare = newcolor;
    }
};

int Masina::contorId = 0;

class valabilitate{
class app{
private:
    std::vector<Masina> masini_valabile;
    std::vector<masina> masini;
    static int contor;
    const int nrMasini = 0;
public:
    valabilitate() = default;
    virtual ~valabilitate() {}
    valabilitate(const std::vector<Masina> &lmasinivalabile){
        this->masini_valabile=lmasinivalabile;
    app() = default;
    ~app() = default;
    app(const std::vector<masina>& obj){
        this->masini = obj;
    }
    friend std::ostream &operator<<(std::ostream &os, const valabilitate &valabil){
        for (auto &masina : valabil.masini_valabile) {
    friend std::ostream &operator<<(std::ostream &os, const app &app){
        for(auto & masina : app.masini){
            os << masina;
        }
        return os;
    }
    void add_more(){
    }
};

class constructor_masina:public masina{
public:
    custom
};

int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}