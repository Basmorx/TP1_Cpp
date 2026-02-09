#include "polynome.h"

Polynome::Polynome(int degre) : m_degre(degre) {
    // On alloue (degre + 1) car il y a le terme x^0
    if (degre >= 0) {
        m_coefs = std::make_unique<double[]>(degre + 1);
        // Initialisation à 0 par sécurité
        for (int i = 0; i <= degre; ++i) m_coefs[i] = 0.0;
    }
}

void Polynome::setCoef(int puissance, double valeur) {
    if (puissance >= 0 && puissance <= m_degre) {
        m_coefs[puissance] = valeur;
    }
}

double Polynome::getCoef(int puissance) const {
    if (puissance >= 0 && puissance <= m_degre) {
        return m_coefs[puissance];
    }
    return 0.0;
}

void Polynome::afficher() const {
    std::cout << "P(x) = ";
    for (int i = m_degre; i >= 0; --i) {
        if (m_coefs[i] != 0) {
            std::cout << (m_coefs[i] > 0 && i != m_degre ? "+" : "") 
                      << m_coefs[i];
            if (i > 0) std::cout << "x^" << i << " ";
        }
    }
    if (m_degre == 0 && m_coefs[0] == 0) std::cout << "0";
    std::cout << std::endl;
}

std::unique_ptr<Polynome> Polynome::deriver() const {
    // Si degré 0, la dérivée est 0 (polynôme de degré 0)
    if (m_degre == 0) {
        return std::make_unique<Polynome>(0);
    }

    // Nouveau polynôme de degré n-1
    auto deriv = std::make_unique<Polynome>(m_degre - 1);

    // Formule : (a * x^n)' = n * a * x^(n-1)
    for (int i = 1; i <= m_degre; ++i) {
        double nouveauCoef = m_coefs[i] * i;
        deriv->setCoef(i - 1, nouveauCoef);
    }

    return deriv;
}

std::unique_ptr<Polynome> Polynome::integrer() const {
    // Nouveau polynôme de degré n+1
    auto integral = std::make_unique<Polynome>(m_degre + 1);

    // Formule : primitive de (a * x^n) = (a / n+1) * x^(n+1)
    for (int i = 0; i <= m_degre; ++i) {
        double nouveauCoef = m_coefs[i] / (i + 1);
        integral->setCoef(i + 1, nouveauCoef);
    }
    
    // La constante d'intégration (x^0) est laissée à 0 par défaut
    return integral;
}

std::unique_ptr<Polynome> saisirPolynome() {
    int degre;
    std::cout << "=== Création du Polynôme ===" << std::endl;
    std::cout << "Entrez le degré maximum (ex: 2 pour ax^2+bx+c) : ";
    std::cin >> degre;

    auto p = std::make_unique<Polynome>(degre);

    std::cout << "Entrez les coefficients :" << std::endl;
    // On demande du plus grand degré vers le plus petit pour une lecture naturelle
    for (int i = degre; i >= 0; --i) {
        double coef;
        std::cout << "  Coef pour x^" << i << " : ";
        std::cin >> coef;
        p->setCoef(i, coef);
    }
    return p;
}

int main() {
    // 1. Saisie utilisateur
    auto poly = saisirPolynome();

    std::cout << "\n--- Résultat Saisie ---" << std::endl;
    poly->afficher();

    // 2. Dérivation
    std::cout << "\n--- Dérivée ---" << std::endl;
    auto derivee = poly->deriver();
    derivee->afficher();

    // 3. Intégration
    std::cout << "\n--- Primitive (C=0) ---" << std::endl;
    auto primitive = poly->integrer();
    primitive->afficher();

    return 0;
}