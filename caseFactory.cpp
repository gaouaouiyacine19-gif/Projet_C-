#include "case.h"
#include "caseFactory.h" 


Case* CaseFactory::creeCase(TypeCase type){
switch(type){
    
    case MUR :
     return  new Mur();
    
    case PASSAGE:
      return new Passage() ;
    
    case TRESOR :
      return new Tresor();

    case PIEGE :

     return new Piege() ;
     
    case MONSTRE :
     return new Monstre();


    default:
     return nullptr;

    }
}


