#include "Donjon.h"
#include <iostream>
#include "caseFactory.h"

using namespace std;

void Donjon::generer(int largeur, int hauteur) {
    maps.resize(hauteur, vector<Case*>(largeur));
 
    // remplir les murs 
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            maps[i][j] = CaseFactory::creeCase(MUR) ;
        
                
        }
    }
     // initialiser le tableau visite
    visite.assign(hauteur, vector<bool>(largeur, false));

    // lancer le recursive backtracking
    genererRecursif(1, 1);
    // placer entrée, sortie, trésor
    maps[1][0] = CaseFactory::creeCase(ENTREE);
    maps[1][1] = CaseFactory::creeCase(PASSAGE);
    maps[hauteur-2][largeur-2] = CaseFactory::creeCase(PASSAGE);
    maps[hauteur-3][largeur-2] = CaseFactory::creeCase(PASSAGE);
    maps[hauteur-2][largeur-1] = CaseFactory::creeCase(SORTIE);
    maps[hauteur/2][largeur/2] = CaseFactory::creeCase(TRESOR);

}
void Donjon::genererRecursif(int x, int y) {
    // on marque la case actuelle comme visitée
    visite[y][x] = true;

    // les 4 directions : haut, bas, gauche, droite
    // on avance de 2 cases donc dx et dy valent 2 ou -2
    int dx[] = {0, 0, -2, 2};
    int dy[] = {-2, 2, 0, 0};

    // mélanger les directions aléatoirement
    int ordre[] = {0, 1, 2, 3};
    for (int i = 3; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(ordre[i], ordre[j]);
    }

    // on essaie chaque direction
    for (int i = 0; i < 4; i++) {
        // la case voisine 2 cases plus loin
        int nx = x + dx[ordre[i]];
        int ny = y + dy[ordre[i]];

        // on avance seulement si :
        // - on est dans la grille (sans toucher les bords)
        // - la case n'est pas déjà visitée
        if (nx > 0 && nx < getLargeur()-1 &&
            ny > 0 && ny < getHauteur()-1 &&
            !visite[ny][nx]) {

            // casser le mur du milieu
            int mx = x + dx[ordre[i]]/2;
            int my = y + dy[ordre[i]]/2;
            maps[my][mx] = CaseFactory::creeCase(PASSAGE);

            // creuser la case d'arrivée
            maps[ny][nx] = CaseFactory::creeCase(PASSAGE);

            // appel récursif — on continue depuis la nouvelle case
            genererRecursif(nx, ny);
        }
    }
    // si aucune direction disponible → backtrack automatique
    // C++ remonte tout seul à l'appel précédent
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
                cout << maps[i][j]->afficher() <<" ";
            }
        }
        cout << endl;
    }


}