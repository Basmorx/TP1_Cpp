#include "exercice.h"

int main() {
    
    Exercice1() ;


    int x1 = 5;
    int y1 = 10;

    float x2 = 5.5f;
    float y2 = 10.5f;

    float result1 = somme(x2, y2);
    int result2 = somme(x1, y1);

    std::cout << "somme(" << x1 << ", " << y1 << ") = " << result2 << std::endl;
    std::cout << "somme(" << x2 << ", " << y2 << ") = " << result1 << std::endl;

    auto tab1 = std::make_unique<int[]>(10);

    for (int i = 0; i < 10; ++i) {
        tab1[i] = i + 1;
    }
    auto tab2 = std::make_unique<int[]>(10);
    for (int i = 0; i < 10; ++i) {
        tab2[i] = (i + 1) * 10;
    }

    auto res = std::make_unique<int[]>(10);
    somme(tab1.get(), tab2.get(), res.get());

    std::cout << "Résultat de la somme des tableaux : ";
    for (int i = 0; i < 10; ++i) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;


    return 0;
}



int main() {
    int n;
    std::cout << "Combien de valeurs voulez-vous traiter ? ";
    std::cin >> n;

    // Création de l'objet Tableau
    Tableau tab(n);

    // 1. Remplissage et première moyenne
    tab.remplirTableau();
    tab.afficher(); // Optionnel, pour voir l'état
    tab.moyenne();

    // 2. Suppression d'un élément
    float valASupprimer;
    std::cout << "Quelle valeur souhaitez-vous supprimer ? ";
    std::cin >> valASupprimer;

    if (tab.enleveElement(valASupprimer)) {
        std::cout << "Valeur supprimée avec succès." << std::endl;
        tab.afficher(); // Pour vérifier le décalage
        tab.moyenne();  // Recalcul de la moyenne
    } else {
        std::cout << "Cette valeur ne fait pas partie des échantillons." << std::endl;
        std::cout << "La moyenne reste inchangée." << std::endl;
    }

    return 0;
}