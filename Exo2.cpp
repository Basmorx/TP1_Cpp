#include <iostream>

// 1. Fonction pour deux entiers
int somme(int a, int b) {
    std::cout << "[Appel version int] ";
    return a + b;
}

// 2. Fonction pour deux réels (float)
float somme(float a, float b) {
    std::cout << "[Appel version float] ";
    return a + b;
}

// 3. Fonction pour deux tableaux de 10 entiers
// Note : On ne peut pas retourner un tableau brut en C++, on passe donc 
// un tableau 'res' pour stocker le résultat.
void somme(const int t1[10], const int t2[10], int res[10]) {
    std::cout << "[Appel version tableau] ";
    for (int i = 0; i < 10; ++i) {
        res[i] = t1[i] + t2[i];
    }
}

int main() {
    // --- Test entiers ---
    int i1 = 5, i2 = 10;
    std::cout << "Somme int : " << somme(i1, i2) << std::endl;

    // --- Test float ---
    // Note : le suffixe 'f' (ex: 2.5f) force le type float. 
    // Sans 'f', 2.5 est un 'double'.
    float f1 = 2.5f, f2 = 4.5f;
    std::cout << "Somme float : " << somme(f1, f2) << std::endl;

    // --- Test tableaux ---
    int tab1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tab2[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int resultat[10];

    somme(tab1, tab2, resultat); // Appel de la version tableau

    // Affichage du tableau résultat
    std::cout << "Resultat tableau : ";
    for (int i = 0; i < 10; ++i) {
        std::cout << resultat[i] << " ";
    }
    std::cout << std::endl;

    // --- Question subsidiaire (short) ---
    short s1 = 2;
    short s2 = 3;
    std::cout << "\nAppel avec deux short : ";
    std::cout << somme(s1, s2) << std::endl;

    return 0;
}