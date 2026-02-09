#include "Exo5.h"
#include <iostream>
#include <cmath>

Equation2::Equation2(double _a, double _b, double _c) {
    a = _a; 
    b = _b;
    c = _c;
}

void Equation2::saisir() {
    std::cout << "Entrez a, b, c : ";
    std::cin >> a >> b >> c;
}

void Equation2::afficher(){
    std::cout << a << "x^2 + " << b << "x + " << c << " = 0" << std::endl;
}


void Equation2::resoudre(){
        if (a == 0) {
            if (b != 0) {
                std::cout << "Solution unique : x = " << -c / b << std::endl;
            } else {
                std::cout << (c == 0 ? "Infinité de solutions." : "Aucune solution.") << std::endl;
            }
            return;
        }

        double delta = b * b - 4 * a * c;
        std::cout << "Discriminant (delta) = " << delta << std::endl;

        if (delta > 0) {
            double x1 = (-b - std::sqrt(delta)) / (2 * a);
            double x2 = (-b + std::sqrt(delta)) / (2 * a);
            std::cout << "Deux solutions réelles : x1 = " << x1 << " et x2 = " << x2 << std::endl;
        } 
        else if (delta == 0) {
            double x0 = -b / (2 * a);
            std::cout << "Une solution double : x0 = " << x0 << std::endl;
        } 
        else {
            std::cout << "Pas de solution réelle." << std::endl;
        }
}

int main() {

    Equation2 eqUser; // Utilise le constructeur par défaut (0,0,0)
    eqUser.saisir();
    eqUser.afficher();
    eqUser.resoudre();

    return 0;
}
