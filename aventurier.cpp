#include "aventurier.h"
#include <iostream>
using namespace std;



Aventurier::Aventurier(int startx, int starty){
    x=startx;
    y=starty;
    vie=100;
}

void Aventurier::deplacer(int dx , int dy ){

    x+=dx;
    y+=dy; 
}
 void Aventurier:: afficherPosition(){
    cout<<"position: (" << x << "," << y << ")" << endl;
    cout << "vie: " << vie << endl;

 }