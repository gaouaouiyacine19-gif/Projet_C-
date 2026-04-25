#include "aventurier.h"
#include <iostream>
using namespace std;




Aventurier::Aventurier(int startx, int starty){
    x=startx;
    y=starty;
    vie=100;
    score=0;
    tresor=0;
}

void Aventurier::deplacer(int dx , int dy, Donjon& d){

   int nx = x + dx;
    int ny = y + dy;
    // Check if the new position is valid
    if (nx <  0  || nx >= d.getLargeur() || ny < 0 || ny >= d.getHauteur()) {
        return ;// hors de la maps ne bouge pas 
    } 

    Case* c = d.getCase(nx, ny); // recuper la nouvelle case 
    if (c->afficher() == '#') {//c->afficher() on recuper ce qui dans la case 
        return ;// mur ne pouge ppas 
    } 
    else if (c->afficher() == 'M') {
        char choix;
        cout<< " do you went to fight the monster ? (y/n) ";
        cin>> choix;
        if (choix == 'y') {
            int nombre = std::rand() % (71)+ 30; // 30-100
            vie-= nombre;
        }
        if (choix =='n'){
            cout<<"tu fuit le monstre"<<endl;
              return;
        }
    } 
        else if (c->afficher() == 'P') {
          vie -= 30;
    } 
         else if (c->afficher() == 'T') {
          tresor++;
    }
         else if (c->afficher() == 'S') {
          cout << "Félicitations ! Vous avez trouvé la sortie !" << endl;
          score += 100;


    }

    x=nx;
    y=ny;
}
int Aventurier:: getX() const {return x; }
int Aventurier:: getY() const {return y; }  

 void Aventurier:: afficherPosition(){
    cout<<"position: (" << x << "," << y << ")" << endl;
    cout << "vie: " << vie << endl;
    cout<< "score:"<< score << endl;
    cout << "tresor: " << tresor << endl;
 }