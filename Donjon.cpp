#include "Donjon.h"
#include <iostream>
#include "caseFactory.h"

using namespace std;

void Donjon::generer(int largeur, int hauteur) {
    maps.resize(hauteur, vector<Case*>(largeur));
 

    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            maps[i][j] = CaseFactory::creeCase(MUR) ;


            //if (i == 0 || i == hauteur - 1 || j == 0 || j == largeur - 1) {
                // maps[i][j] = CaseFactory::creeCase(MUR) ;} 
            
            
             //maps[i][j] = CaseFactory::creeCase(PASSAGE);
                
        }
    }
    
    //for (int i=1; i<largeur-2; i++){
       //maps[1][i]=CaseFactory::creeCase(PASSAGE);
    //}
     //for (int i=1; i<hauteur-1; i++){
      // maps[i][largeur-2]=CaseFactory::creeCase(PASSAGE);

    //}
    int d =1;
    int r= 1;
    while (d < hauteur - 1 && r < largeur-1 ){
        

        if (d==hauteur-2){
            for (int i=r; i<largeur-2; i++){
                maps[d][i]=CaseFactory::creeCase(PASSAGE);

        }
        break;
    }
       else if(r==largeur-2){
         for (int i=d; i<hauteur-1; i++){
           maps[i][r]=CaseFactory::creeCase(PASSAGE);

        } 
        break;
    }
        int dr = std::rand() % (2); // 0 ou 1 d r down or right 
        if(dr ==0){
            if(d < hauteur-2){
                 d++;
                 maps[d][r]=CaseFactory::creeCase(PASSAGE);
             }
         

        }
        if(dr ==1 ){
            if(r < largeur-2){
                 r++;
            maps[d][r]=CaseFactory::creeCase(PASSAGE);
                

            }
            
        }


    }


    // Ajouter un trésor au centre
    maps[hauteur/2][largeur/2] = CaseFactory::creeCase(TRESOR);


    maps[1][0] = CaseFactory::creeCase(ENTREE); 
    maps[1][1] = CaseFactory::creeCase(PASSAGE);// entrée

    maps[hauteur-2][largeur-1] = CaseFactory::creeCase(SORTIE); // sortie

    
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
void Donjon::afficher(int px , int py ) {
    for ( int i = 0; i< maps.size(); i++ ) {// pour chauqe linge de la maps 
        for (int j = 0; j < maps[i].size(); j++) {
        
            if (i == py && j == px) {
                cout << '@';
            } else {
                cout << maps[i][j]->afficher();
            }
        }
        cout << endl;
    }
}