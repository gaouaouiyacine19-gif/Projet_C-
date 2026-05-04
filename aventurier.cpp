#include "aventurier.h"
#include "caseFactory.h"
#include <iostream>
using namespace std;




Aventurier::Aventurier(int startx, int starty){
    x=startx;
    y=starty;
    vie=200;
    score=0;
    tresor=0;
    gagne = false;
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
        cout << "do you want to fight the monster ? (y/n) ";
        cin >> choix;
        if (choix == 'y') {
            int nombre = std::rand() % 21 + 10;
            vie -= nombre;
        }
        if (choix == 'n') {
            cout << "tu fuis le monstre" << endl;
        }
        // dans tous les cas le monstre disparaît
        d.setCase(nx, ny, CaseFactory::creeCase(PASSAGE));
    } 
        else if (c->afficher() == 'T') {
          vie -= 10;
    } 
         else if (c->afficher() == '+') {
          tresor++;
          d.setCase(nx, ny, CaseFactory::creeCase(PASSAGE));
    }

        
         else if (c->afficher() == 'S') {
          cout << "Félicitations ! Vous avez trouvé la sortie !" << endl;
          score += 100;
          gagne = true;


    }

    x=nx;
    y=ny;
}
bool Aventurier::estVivant() const {
    return vie > 0;
}
bool Aventurier::aGagne() const {
    return gagne;
}

int Aventurier:: getX() const {return x; }
int Aventurier:: getY() const {return y; }  

 void Aventurier:: afficherPosition(){
    cout<<"position: (" << x << "," << y << ")" << endl;
    cout << "vie: " << vie << endl;
    cout<< "score:"<< score << endl;
    cout << "tresor: " << tresor << endl;
 }