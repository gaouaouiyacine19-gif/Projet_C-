#include "Donjon.h"
#include "aventurier.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    Donjon d;
    d.generer(21, 21);

    Aventurier a(1, 1);
    char cmd;

    while (a.estVivant() && !a.aGagne()) {
        system("clear");
        d.afficher(a.getX(), a.getY());
        a.afficherPosition();

        cout << "Entrez une commande (z/q/s/d/p), x pour quitter: ";
        cin >> cmd;
        cin.ignore();


        if (cmd == 'x') {
            cout << "Fin du jeu." << endl;
            return 0;
        }
        else if (cmd == 'z') {
            a.deplacer(0, -1, d);
        } 
        else if (cmd == 's') {
            a.deplacer(0, 1, d);
        } 
        else if (cmd == 'q') {
            a.deplacer(-1, 0, d);
        } 
        else if (cmd == 'd') {
            a.deplacer(1, 0, d);
        }
        else if (cmd == 'p') {
            vector<Position> chemin = d.trouverChemin(a.getX(), a.getY());
            if (chemin.empty()) {
                cout << "Aucun chemin trouve !" << endl;
            } else {
                cout << "Distance a la sortie : " << chemin.size()-1 << " cases" << endl;
                d.afficherAvecChemin(chemin, a.getX(), a.getY());
            }
            cout << "Appuyez sur ENTREE pour continuer..." << endl;
            cin.ignore();
            cin.get();
        }
        else {
            cout << "Commande invalide!" << endl;
        }
    }  // ← fin du while

    // ici on est sorti du while
    if (a.aGagne()) {
        cout << "Felicitations ! Vous avez trouve la sortie !" << endl;
    } else {
        cout << "Game Over !" << endl;
    }

    return 0;
}