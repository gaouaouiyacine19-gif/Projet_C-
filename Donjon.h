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
    vector<vector<bool>> visite; // tableau de booléens pour savoir quelles cases ont déjà été visitées par le Recursive Backtracking. true = déjà visité, false = pas encore
public:
    void setCase(int x, int y, Case* c); // remplace une case dans la grille
    void generer(int largeur, int hauteur);// definir  la fonction  pour la maps combien la hauteur et largeur 
    void afficher(int px, int py);// pour chaque valleur dans la martice  
     void genererRecursif(int x, int y); 
    // fonction qui creuse les chemins du labyrinthe en partant de (x,y)
    // avance de 2 cases à la fois et casse le mur du milieu
    // s'appelle elle même récursivement jusqu'à avoir visité toutes les cases
  
Case* getCase(int x, int y );
int getLargeur();
int getHauteur();
   
};

#endif