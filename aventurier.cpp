#include "aventurier.h"
#include <iostream>
using namespace std;




Aventurier::Aventurier(int startx, int starty){
    x=startx;
    y=starty;
    vie=100;
}

void Aventurier::deplacer(int dx , int dy, Donjon& d){

   int nx = x + dx;
    int ny = y + dy;
    // Check if the new position is valid
    if (nx <  0  || nx >= d.getLargeur() || ny < 0 || ny >= d.getHauter()) {
        return ;// hors de la maps ne bouge pas 
    } 

    Case* c = d.getCase(nx, ny); // recuper la nouvelle case 
    if (c->afficher() == '#') {//c->afficher() on recuper ce qui dans la case 
        return ;// mur ne pouge ppas 
    } 
    else if (c->afficher() == 'M') {
        vie -= 20;
    } 
    else if (c->afficher() == 'P') {
        vie -= 10;
    } 
    else if (c->afficher() == 'T') {
        vie += 50;
    }
    x=nx;
    y=ny;
}
int Aventurier:: getX() const {return x; }
int Aventurier:: getY() const {return y; }  

 void Aventurier:: afficherPosition(){
    cout<<"position: (" << x << "," << y << ")" << endl;
    cout << "vie: " << vie << endl;

 }