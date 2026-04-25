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

    maps[1][1] = CaseFactory::creeCase(PASSAGE); // entrée
    maps[hauteur-2][largeur-1] = CaseFactory::creeCase(SORTIE); // sortie

    
}
Case* Donjon::getCase(int x, int y ){
    return maps[y][x];// dans cette case y quoi 

}
int Donjon::getLargeur() {
    return maps[0].size();// combien de colone y a
}
int Donjon::getHauteur() {
    return maps.size();// cobien de ligne y a 
}
void Donjon::afficher(int px , int py ) {
    for ( int i = 0; i< maps.size(); i++ ) {// pour chauqe linge de la maps 
        for (int j = 0; j < maps[i].size(); j++) {
        
            if (i == py && j == px) {
                cout << '@';
            } else {
                cout << maps[i][j]->afficher();
            }
        }
        cout << endl;
    }
}