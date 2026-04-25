#include "Donjon.h"
#include "aventurier.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // une seule fois au début

    Donjon d;
    d.generer(20, 10);

    Aventurier a(0, 1);
    char cmd;

    while (a.estVivant() && !a.aGagne()) {
        d.afficher(a.getX(), a.getY());
        a.afficherPosition();

        cout << "Entrez une commande (z/q/s/d), x pour quitter: ";
        cin >> cmd;

        if (cmd == 'x') {
            cout << "Fin du jeu." << endl;
            return 0;
        }

        if (cmd == 'z') {
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
        else {
            cout << "Commande invalide!" << endl;
        }
    }

    if (a.aGagne()) {
        cout << "Felicitations ! Vous avez trouve la sortie !" << endl;
    } else {
        cout << "Game Over !" << endl;
    }

    return 0;
}