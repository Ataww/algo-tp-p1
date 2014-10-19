#include <iostream>
#include <stdexcept>
using namespace std;
#include "../read/read.h"
#include "common.h"
#include "solution_1.h"

//////////////////////////////////////////////////////////////////////////////////////////
//                     Point d'entrée du programme : Solution 1                         //
//////////////////////////////////////////////////////////////////////////////////////////
int main (int argc, char* argv[]){

	//Variable liée à la dalle
	dalle dalle;

	//Variable liée au plus grand rectangle
	point coord = {.x = 0, .y = 0};
	rect rect = {.width = 0, .heigth = 0};


	//Test présence nom de fichier
	if(argc != 2){
		cout << "ERRREUR sur les paramètres d'appel" << endl;
		return -1;
	}

	//Création de la dalle
	try{
		dalle.data = createDalle( dalle.dim.width, dalle.dim.heigth, argv[1]);
	}
	catch(range_error& e){
		cout << e.what() << endl;
		return -1;
	}

	cout << "largeur= " << dalle.dim.width << " / " << "hauteur= " << dalle.dim.heigth << endl;

	//Appel algorithme solution 1
	bool result = solution_1(dalle, rect, coord);

	//Affichage
	if(result){
		cout << endl;
		cout << "Caractéristique du plus grand rectangle :" << endl;
		cout << "- coordonnée x: " << coord.x << endl;
		cout << "- coordonnée y: " << coord.y << endl;
		cout << "- largeur : "     << rect.width << endl;
		cout << "- hauteur : "     << rect.heigth << endl;
	}

	delete[] dalle.data;

	return 0;

} 