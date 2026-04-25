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
public:
   Aventurier(int startx, int starty);

   void deplacer(int dx , int dy , Donjon& d);
   void resoudreCase();
   int getX() const;
   int getY() const;
   void afficherPosition();

};



#endif