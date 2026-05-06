#include "Donjon.h"
#include <iostream>
#include<queue>
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

    // placer les monstres aléatoirement
    for (int i = 1; i < hauteur-1; i++) {
        for (int j = 1; j < largeur-1; j++) {
            if (maps[i][j]->afficher() == ' ') {
                int r = rand() % 100;
                if (r < 5) {
                    maps[i][j] = CaseFactory::creeCase(TRESOR);
                } else if (r < 10) {
                    maps[i][j] = CaseFactory::creeCase(MONSTRE);
                } else if (r < 13) {
                    maps[i][j] = CaseFactory::creeCase(PIEGE);
                }
            }
        }
    }
    // placer entrée, sortie, trésor
    maps[1][0] = CaseFactory::creeCase(ENTREE);
    maps[1][1] = CaseFactory::creeCase(PASSAGE);
    
    
    maps[hauteur-2][largeur-1] = CaseFactory::creeCase(SORTIE);


    

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
void Donjon::setCase(int x, int y, Case* c) {
    maps[y][x] = c; // remplace la case à la position (x,y)
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



// chemin optimaml
vector<Position> Donjon::trouverChemin(int startX, int startY) {
    // la file d'attente — stocke les cases à visiter
    queue<Position> file;

    // tableau de booléens — cases déjà visitées
    vector<vector<bool>> visiteB(getHauteur(), vector<bool>(getLargeur(), false));

    // tableau de parents — pour reconstruire le chemin
    vector<vector<Position>> parent(getHauteur(), vector<Position>(getLargeur(), {-1, -1}));
    
    // on place le point de départ dans la file
    file.push({startY, startX});
    visiteB[startY][startX] = true;
    // les 4 directions : haut, bas, gauche, droite  
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};


// tant que la file n'est pas vide
    while (!file.empty()) {
        // on prend la première case de la file
        Position courant = file.front();
        file.pop();

// on vérifie si on est arrivé à la sortie
        if (maps[courant.d][courant.r]->afficher() == 'S') {
            // on reconstruit le chemin
            vector<Position> chemin;
            Position c = courant;
            while (c.d != -1 && c.r != -1) {
                chemin.push_back(c);
                c = parent[c.d][c.r];
            }
            return chemin; // on retourne le chemin
        }
    
        for (int i = 0; i < 4; i++) {
            int nx = courant.r + dx[i];
            int ny = courant.d + dy[i];

            if (nx >= 0 && nx < getLargeur() &&
                ny >= 0 && ny < getHauteur() &&
                !visiteB[ny][nx] &&
                maps[ny][nx]->afficher() != '#') {

                visiteB[ny][nx] = true;
                parent[ny][nx] = courant;
                file.push({ny, nx});
            }
        }
    }
    return {};

}
void Donjon::afficherAvecChemin(vector<Position> chemin, int px, int py) {
    // on crée un tableau 2D de booléens pour marquer les cases du chemin
    vector<vector<bool>> dansChemin(getHauteur(), vector<bool>(getLargeur(), false));

    // on marque toutes les cases du chemin
    for (Position p : chemin) {
        dansChemin[p.d][p.r] = true;
    }

    // on affiche la grille
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (i == py && j == px) {
                cout << '@' << " "; // position de l'aventurier
            } else if (dansChemin[i][j]) {
                cout << '.' << " "; // case du chemin
            } else {
                cout << maps[i][j]->afficher() << " "; // case normale
            }
        }
        cout << endl;
    }
}