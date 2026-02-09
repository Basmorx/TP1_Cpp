#include <algorithm> // pour std::swap
#include <iostream>
using namespace std;


void ech2paradresse(float* v1, float* v2) {
        float temp = *v1;
        *v1 = *v2;
        *v2 = temp;
}

void ech2parReference(float& v1, float& v2) {

        std::swap(v1, v2); 

}



void ordonnetrois(float* a, float* b, float* c) {
    if(*a > *b){
    ech2paradresse(a, b);}
    // cout << "a = " << *a << "b = " << *b << "c = " << *c << endl;
    if(*b > *c){
        ech2parReference(*b, *c);
    }
    // cout << "a = " << *a << "b = " << *b << "c = " << *c << endl;
    if(*a > *b){
    ech2paradresse(a, b);
    }
    return;

}

int main(){
    float a = 10;
    float b = 42.141592653589;
    float c = -0.54;
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
    ordonnetrois(&a,&b,&c);
    cout << "a = " << a << " b = " << b << " c = " << c << endl;

}