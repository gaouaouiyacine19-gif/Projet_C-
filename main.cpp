#include "Donjon.h"
#include "aventurier.h"

int main() {
    Donjon d;
    d.generer(20, 10);
    d.afficher();

   Aventurier a(3, 2);
   a.afficherPosition();
   a.deplacer(1, 0);

   a.afficherPosition();
    
    return 0;
}
