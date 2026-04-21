#include "Donjon.h"
#include <iostream>
#include "caseFactory.h"

using namespace std;

void Donjon::generer(int largeur, int hauteur) {
    maps.resize(hauteur, vector<Case*>(largeur));

    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            if (i == 0 || i == hauteur - 1 || j == 0 || j == largeur - 1) {
                maps[i][j] = CaseFactory::creeCase(MUR) ;
            } 
            else {
                maps[i][j] = CaseFactory::creeCase(PASSAGE);
                
            }
            if(i==3 & j==4){
                 maps[i][j] =CaseFactory::creeCase(PIEGE);
            }
            if(i==5 & j==3){
                 maps[i][j] =CaseFactory::creeCase(MONSTRE);
            }

        }
    }

    // Ajouter un trésor au centre
    maps[hauteur/2][largeur/2] = CaseFactory::creeCase(TRESOR);
}
void Donjon::afficher() {
    for (auto& ligne : maps ) {// pour chauqe linge de la maps 
        for (auto& c : ligne) {// pour chaque case 
            cout << c->afficher();
        }
        cout << endl;
    }
}