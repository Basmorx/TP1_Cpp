#include <iostream>
#include <memory>
#include <vector>


class Tableau{

public :

    Tableau(int size);

    void moyenne() const;

    bool enleveElement(float valeur);

    void remplirTableau();

    void afficher() const;
   
private :

    std::unique_ptr<float[]> m_donnees;
    int m_taille;

    int trouverIndex(float valeur) const;

    void decalerElements(int index);
}
;
