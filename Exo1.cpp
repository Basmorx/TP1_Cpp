#include "exercice.h"

void Exercice1() {
    // ---------------------------------------------------------
    // --- PARTIE 1 : Pointeurs bruts (Raw Pointers) ---
    // ---------------------------------------------------------
    std::cout << "--- PARTIE 1 : Pointeurs bruts ---" << std::endl;

    // 1. Pointeur sur un entier simple
    int* p = new int(10);

    // 2. Pointeur sur un entier constant (la valeur est constante)
    const int* q = new int(20);

    // 3. Pointeur constant sur un entier (l'adresse est constante)
    int* const r = new int(30);

    std::cout << "p: " << *p << ", q: " << *q << ", r: " << *r << std::endl;

    // Modification de p
    std::cout << "*p = " << *p << ", p = " << p << " puis p = 40" << std::endl;
    *p = 40; 
    std::cout << "*p = " << *p << ", p = " << p << std::endl;

    // Tentative de modification de q (interdit car const int*)
    std::cout << "*q = " << *q << ", q = " << q << " puis q = 50" << std::endl;
    std::cout << "Erreur car q pointe vers un entier constant, on ne peut pas modifier la valeur pointée,\n *q = " << *q << ", q = " << q << std::endl;

    // Tentative de modification de r (Note : int* const empêche de changer l'adresse r, mais autorise techniquement *r)
    std::cout << "*r = " << *r << ", r = " << r << " puis r = 60" << std::endl;
    std::cout << "Note : r est un pointeur constant. On ne pourrait pas faire r = nouveau_pointeur." << std::endl;

    // Référence dynamique
    int& s = *new int(40);
    std::cout << "s: " << s << std::endl;
    
    // IMPORTANT : Désallocation manuelle obligatoire pour éviter les fuites de mémoire
    delete p;
    delete q;
    delete r;
    delete &s; // Désallocation de la référence dynamique

    // 4. Tableau dynamique (Pointeurs bruts)
    int* arr = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Tableau (brut): ";
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << std::endl;

    // Désallocation du tableau
    delete[] arr;


    // ---------------------------------------------------------
    // --- PARTIE 2 : Pointeurs Intelligents (Smart Pointers) ---
    // ---------------------------------------------------------
    std::cout << "--- PARTIE 2 : Smarts Pointeurs ---" << std::endl;

    // 1. Smart pointers simples (std::unique_ptr)
    auto p_smart = std::make_unique<int>(10);
    
    // unique_ptr vers const int
    std::unique_ptr<const int> q_smart = std::make_unique<int>(20);

    // const unique_ptr (le pointeur lui-même est const)
    const auto r_smart = std::make_unique<int>(30);

    std::cout << "Smart Pointers alloués automatiquement (valeurs : " 
              << *p_smart << ", " << *q_smart << ", " << *r_smart << ")." << std::endl;

    // 2. Tableau dynamique géré par unique_ptr
    auto arr_smart = std::make_unique<int[]>(10);

    for (int i = 0; i < 10; ++i) {
        arr_smart[i] = i + 1;
    }

    std::cout << "Tableau Smart Pointers: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << arr_smart[i] << " ";
    }
    std::cout << std::endl;
    
    // Pas besoin de 'delete', la mémoire est libérée automatiquement à la fin de la fonction.
}


// ---------------------------Exercice 2 ---------------------------:

int somme(int a, int b) {
    std::cout << "[Appel version int]\n";
    return a + b;
}


float somme(float a, float b) {
    std::cout << "[Appel version float]\n";
    return a + b;
}

void somme(const int t1[10], const int t2[10], int res[10]) {
    std::cout << "[Appel version tableau]\n";
    for (int i = 0; i < 10; ++i) {
        res[i] = t1[i] + t2[i];
    }
}