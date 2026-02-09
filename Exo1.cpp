#include <iostream>
#include <memory>
using namespace std;

void exo1_partie1() {
    int* p = new int(5);          // Pointeur sur entier
    const int* q = new int(10);   // Pointeur sur entier constant (la valeur est const)
    int* const r = new int(10);          // Pointeur constant sur entier (l'adresse est const)
    
    int** tabPointeurs = new int*[10];
    for (int i = 0; i < 10; ++i) {
        tabPointeurs[i] = new int(i);
    }



    for (int i = 0; i < 10; ++i) {
        delete tabPointeurs[i];
    }
    delete[] tabPointeurs;
    cout << "*p  = " << *p << " p = " << p << " puis *p = 40" << endl;
    *p = 40;
    cout << "*p = " << *p << " p = " << p << endl;
    delete p;
    p = new int(70);
    cout << "*p = " << *p << " p = " << p << endl << endl;

    cout << "*q = " << *q << " q = " << q << " puis *q = 90 impossible car type(*q) = const int" << endl;
    // *q = 90;
    const int * temp = q;
    q = new int(100);
    delete temp;
    cout << "*q = " << *q << " q = " << q << endl << endl;

    cout << "*r = " << *r << " r = " << r << " puis *r = 110" << endl;
    *r = 110;
    cout << "*r = " << *r << " r = " << r << " impossible de changer le pointeur r car r est pointeur cst"<< endl << endl;
    delete r;
    //r = new int(190);

    int nombre = 60;
    int &s = nombre;
    
    cout << "nombre = " << nombre << " s = " << s << " puis s = 10 " << endl;
    s = 10;
    cout << "nombre = " << nombre << " s = " << s << endl << endl;

}

void exercice1_partie2() {

    unique_ptr<int> p  = make_unique<int>(42);
    cout <<" *p = " << *p << " p est deleted tt seul"<<  endl; 
    shared_ptr<const int>q = make_shared<const int>(30);
    shared_ptr Q2 = q;
    cout << "shared_ptr = " << q << " *q = " << *q <<  " apres 2 utilisation le pointeur et libéré"<<endl;
    cout << "shared_ptr = " << Q2 << " *Q2 = " << *Q2 <<  "  apres 2 utilisation le pointeur et libéré"<<endl;
    


}



int main() {
    exo1_partie1();
    exercice1_partie2();

    return 0;
}