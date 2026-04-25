#include  "case.h"


char Mur::afficher(){
    return '#';
}
char Passage::afficher(){
    return ' ';
}
char Tresor::afficher(){
   return '+';
}
char Monstre::afficher() {
    return 'M';
}
char Piege::afficher() {
    return 'T';
}
char Sortie::afficher() {
    return 'S';
}
char Entree::afficher(){
    return 'E';
}
