#ifndef AVENTURIER_H
#define AVENTURIER_H


class Aventurier {
private:
    int x;
    int y;
    int vie;
public:
   Aventurier(int startx, int starty);

   void deplacer(int dx , int dy);
   void afficherPosition();

};










#endif