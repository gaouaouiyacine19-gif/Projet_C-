
// les deux linge c'est pour que  le case.h ce crée une seul fois 

#ifndef CASE_H
#define CASE_H 

class Case {
    public :
    // virtual  pour la difinier aprés 

    virtual char afficher() = 0;

    // c'est le destructeur 

    virtual ~Case(){}  

};
// la class mur hérte de la class case 
// override  jpour dire que je reéfinis une fonctio dela classe parent comme ça c'est il y a une erreur on peut le savoir 
class Mur : public Case{
public :
    char afficher() override;

};
class Passage : public Case {
public :
   char afficher() override ;

};

class Tresor : public Case {
public : 
   char afficher() override ;

};


class Piege : public Case {
public : 
  char afficher() override;

};

class Monstre : public Case {
public : 
   char afficher() override ;

};



