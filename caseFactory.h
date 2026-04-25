#ifndef CASEFACTORY_H
#define CASEFACTORY_H

#include "case.h"

enum TypeCase{
    MUR,
    PASSAGE,
    TRESOR,
    MONSTRE,
    PIEGE,
    SORTIE
};
class CaseFactory{
public :
     static Case* creeCase(TypeCase type);//static on peut appeler la fonction sans crée d'objet
  
};
//ici il recoit un type il renvoi la bonne case 

#endif 