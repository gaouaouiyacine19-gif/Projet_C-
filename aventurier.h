#ifndef AVENTURIER_H
#define AVENTURIER_H
#include "Donjon.h"


class Aventurier {
private:
    int x;
    int y;
    int vie;
    int score;
    int tresor;
    bool gagne;

public:
   Aventurier(int startx, int starty);

   void deplacer(int dx , int dy , Donjon& d);
   void resoudreCase();
   int getX() const;
   int getY() const;
   void afficherPosition();
   bool estVivant() const;
   bool aGagne() const ;

};



#endif