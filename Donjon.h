#ifndef DONJON_H
#define DONJON_H
#include<iostream>
#include <vector>
#include "case.h"
using namespace std ;

struct Position {
    int d;
    int r;
};

class Donjon {
private:
    vector<vector<Case*>> maps;// crée une matirce 
    std::vector<Position> passages;

public:
    void generer(int largeur, int hauteur);// definir  la fonction  pour la maps combien la hauteur et largeur 
    void afficher(int px, int py);// pour chaque valleur dans la martice  
Case* getCase(int x, int y );
int getLargeur();
int getHauteur();
  
};

#endif