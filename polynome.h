#include <iostream>
#include <memory>
#include <vector>

class Polynome {
public:

    Polynome(int degre);

    void setCoef(int puissance, double valeur);

    double getCoef(int puissance) const;

    void afficher() const;

    std::unique_ptr<Polynome> deriver() const;

    std::unique_ptr<Polynome> integrer() const;

private:
    int m_degre;                       
    std::unique_ptr<double[]> m_coefs;  
};
