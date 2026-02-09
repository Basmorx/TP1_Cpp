#include "tableau.h"

Tableau::Tableau(int taille) : m_taille(taille) {
    if (taille > 0) {
        // Allocation dynamique avec unique_ptr (tableau de floats)
        m_donnees = std::make_unique<float[]>(taille);
    }
}

void Tableau::remplirTableau() {
    std::cout << "Veuillez saisir les " << m_taille << " valeurs :" << std::endl;
    for (int i = 0; i < m_taille; ++i) {
        std::cout << "Valeur " << (i + 1) << " : ";
        std::cin >> m_donnees[i];
    }
}

void Tableau::moyenne() const {
    if (m_taille == 0) {
        std::cout << "Tableau vide, pas de moyenne." << std::endl;
        return;
    }

    float somme = 0.0f;
    for (int i = 0; i < m_taille; ++i) {
        somme += m_donnees[i];
    }
    
    std::cout << "Moyenne actuelle : " << (somme / m_taille) << std::endl;
}

bool Tableau::enleveElement(float valeur) {
    int index = trouverIndex(valeur);

    if (index == -1) {
        return false;
    }

    // Si trouvé, on décale et on réduit la taille
    decalerElements(index);
    m_taille--; 
    return true;
}

int Tableau::trouverIndex(float valeur) const {
    for (int i = 0; i < m_taille; ++i) {
        if (m_donnees[i] == valeur) {
            return i;
        }
    }
    return -1;
}

void Tableau::decalerElements(int index) {
    // On écrase l'élément à 'index' par celui de 'index + 1', et ainsi de suite
    for (int i = index; i < m_taille - 1; ++i) {
        m_donnees[i] = m_donnees[i + 1];
    }
}

void Tableau::afficher() const {
    std::cout << "[ ";
    for (int i = 0; i < m_taille; ++i) {
        std::cout << m_donnees[i] << " ";
    }
    std::cout << "]" << std::endl;
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