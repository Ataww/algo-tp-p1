#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fstream>
using namespace std;

const string ERROR_APPEL= "ERREUR sur le nombres de paramètres d'appel.";
const string ERROR_INT  = "ERREUR: l'un des paramètres contient un caractère alphabétique.";
const string ERROR_POURCENTAGE = "ERREUR: Un poucentage ne peut pas etre superieur à 100.";
const string ERROR_NB = "ERREUR: Le nombre de ligne ou de colonne ne peut pas etre egal a 0";

//////////////////////////////////////////////////////////////////////////////////////////
//                            Point d'entrée du programme                               //
//////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]){

  //Test sur le nombre de paramètre
  if(argc != 4){
    cout << ERROR_APPEL << endl;
    return -1;
  }

  //Test paramètre int
  for(int i = 1; i < 4; i++ ){
    string tmp = argv[i];
    char cstr[tmp.length()];
    strcpy(cstr, tmp.c_str());
    for(int j = 0; j < tmp.length(); j++){
      if(!isdigit(cstr[j])){
        cout << ERROR_INT << endl;
        return -1;
      }
    }
  }

  //Variable caractérisant la dalle
  int nbLine = atoi(argv[1]);
  int nbCol  = atoi(argv[2]);
  int pBlanc = atoi(argv[3]);

  //Test pourcentage !> 100
  if(pBlanc > 100){
    cout << ERROR_POURCENTAGE << endl;
    return -1;
  }

  //Test nbLine et nbCol > o
  if(nbLine == 0 || nbCol ==0){
    cout << ERROR_NB << endl;
    return -1;
  }

  //Création du fichier de test
  ofstream f;
  f.open("test_generator.txt");
  f << nbLine << " " << nbCol;
  srand(time(NULL));
  for(int i = 0; i < nbLine; i++){
    f << '\n';
    for(int j = 0; j < nbCol; j++){
      if((rand() % 100) < pBlanc)
        f << "0";
      else
        f << "1";
    }
  }


  f.close();

  return 0;
}
