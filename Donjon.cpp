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
    // la cest pour crée un chemein de sotrie qui vreable a chaque fois 
    
    int d =1;
    int r= 1;
    while (d < hauteur - 1 && r < largeur-1 ){
        

        if (d==hauteur-2){
            for (int i=r; i<largeur-1; i++){
                maps[d][i]=CaseFactory::creeCase(PASSAGE);
                passages.push_back({d, i});

        }
        break;
    }
       else if(r==largeur-2){
         for (int i=d; i<hauteur-1; i++){
           maps[i][r]=CaseFactory::creeCase(PASSAGE);
           passages.push_back({i, d});

        } 
        break;
    }
        int dr = std::rand() % (2); // 0 ou 1 d r down or right 
        if(dr ==0){
            if(d < hauteur-2){
                 d++;
                 maps[d][r]=CaseFactory::creeCase(PASSAGE);
                 passages.push_back({d, r});
             }
         

        }
        if(dr ==1 ){
            if(r < largeur-2){
                 r++;
                 maps[d][r]=CaseFactory::creeCase(PASSAGE);
                 passages.push_back({d, r});
                

            }
            
        }


    }


    // Ajouter un trésor au centre
    maps[hauteur/2][largeur/2] = CaseFactory::creeCase(TRESOR);


    maps[1][0] = CaseFactory::creeCase(ENTREE); 
    maps[1][1] = CaseFactory::creeCase(PASSAGE);// entrée
    maps[hauteur-2][largeur-1] = CaseFactory::creeCase(SORTIE); // sortie
// crée les passage aleatoire 
for(int i =0 ; i<10;i++){
    int index = rand() % passages.size();
    Position p = passages[index];
        int l=p.d;
        int c=p.r;
        int choix = rand()%2;
  

  
        for(int j = 0 ; j<10 ;j++){
        int proch = rand() % 4;
        if (proch ==0 ) {
            c++;
            if(l==hauteur-1 || c==largeur-1){
                c--;
            }
            else{

                maps[l][c] = CaseFactory::creeCase(PASSAGE);
                passages.push_back({l, c});

            }
            

       }
        if (proch ==1 ) {
            l++;
             if(l==hauteur-1 || c==largeur-1){
                l--;
            }
            else {
                maps[l][c] = CaseFactory::creeCase(PASSAGE);
                passages.push_back({l, c});
            }

       }
        if (proch ==2 ) {
            c--;
             if(l==hauteur-1 || c==largeur-1){
                c++;
            }
           else {
            maps[l][c] = CaseFactory::creeCase(PASSAGE);
             passages.push_back({l, c});
            } 
            

       } if (proch ==3 ) {
           l--;
          if(l==hauteur-1 || c==largeur-1){
                l++;
             }
          else {
            maps[l][c] = CaseFactory::creeCase(PASSAGE);
            passages.push_back({l, c});
            } 

       }

    }

}
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
                cout << maps[i][j]->afficher() <<" ";
            }
        }
        cout << endl;
    }
}