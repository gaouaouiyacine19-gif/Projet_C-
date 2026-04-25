#include "Donjon.h"
#include "aventurier.h"
#include <cstdlib>
#include <ctime>

int main() {
    Donjon d;
   
    d.generer(20, 10);

   Aventurier a(0, 1);
   char cmd;
   while(true){
    d.afficher(a.getX(), a.getY());
    a.afficherPosition();
    srand(time(0));
    cout << "Entrez une commande (z ou q ou s ou d) pour se deplacer, x pour quitter: ";
    cin >> cmd;
    Case* c = d.getCase(a.getX(), a.getY());
    if (c->afficher() == 'S') {
        cout << "Félicitations ! Vous avez trouvé la sortie !" << endl;
        break;
    }

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
