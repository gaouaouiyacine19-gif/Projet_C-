#ifndef DONJON_H
#define DONJON_H
#include<iostream>
#include <vector>
#include "case.h"
using namespace std ;



class Donjon {
private:
    vector<vector<Case*>> maps;// crée une matirce 

public:
    void generer(int largeur, int hauteur);// definir  la fonction  pour la maps combien la hauteur et largeur 
    void afficher();// pour chaque valleur dans la martice  
};

#endif