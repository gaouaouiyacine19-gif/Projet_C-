#include "Donjon.h"
#include "aventurier.h"

int main() {
    Donjon d;
   
    d.generer(20, 10);

   Aventurier a(3, 2);
   char cmd;
   while(true){
    d.afficher(a.getX(), a.getY());
    a.afficherPosition();
    cout << "Entrez une commande (z ou q ou s ou d) pour se deplacer, x pour quitter: ";
    cin >> cmd;

    if (cmd == 'x') {
        break;
    }

        if (cmd == 'z') {
            a.deplacer(0, -1, d);
        } else if (cmd == 's') {
            a.deplacer(0, 1, d);
        } else if (cmd == 'q') {
            a.deplacer(-1, 0, d);
        } else if (cmd == 'd') {
            a.deplacer(1, 0, d)     ;
        } else {
            cout << "Commande invalide!" << endl;
            continue;
        }
        
    }
         
    return 0;
}
