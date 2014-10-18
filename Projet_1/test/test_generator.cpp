#include <iostream>
#include <string>
#include <stdlib.h> 
#include <ctime>
#include <cstdlib>
using namespace std;
#include "../read/read.h"
#include "../solution/common.h"

const int NB_TEST = 10;
const int L_MIN = 10;
const int L_MAX = 200;


//Fonction conptant le nombre de case blanche dans une dalle
int count_nbBlanc(dalle& dalle){

	int nb = 0;
	for(int i=0; i<dalle.dim.height; i++)
		for(int j=0; j<dalle.dim.width; j++)
			if(dalle.data[i*dalle.dim.width+j] == true)
				nb++;

	return nb;
}

//Test du generteur de fichier test
int main (int argc, char* argv[]){

	srand((unsigned)time(NULL));
	long double pourcentage_ecart = 0;

	for(int i = 0; i < NB_TEST; i++){

		int nbLine = L_MIN + rand()%(L_MAX - L_MIN);
		int pBlanc = rand()%100;

		string command = "./exe/generator.exe "+ to_string(nbLine)+ " " + to_string(pBlanc);
		system(command.c_str());

		dalle dalle;
		dalle.data = createDalle(dalle.dim.width, dalle.dim.height, "test_generator.txt");

		//On compte combien de case blanche sont présente
		int nbBlanc = count_nbBlanc(dalle);
		//On additionne les pourcentages d'écart entre celui demandé et celui obtenu
		pourcentage_ecart += pBlanc - (long double)( (nbBlanc*100) / (dalle.dim.width*dalle.dim.height) );


	}

	//Affiche du pourcentage d'écart moyen
	cout << "Pourcentage moyen des écarts de case blanche entre le pourcentage demandé et celui réellement obtenu : "
		 << pourcentage_ecart/NB_TEST << " %" << endl;

	return 0;
}