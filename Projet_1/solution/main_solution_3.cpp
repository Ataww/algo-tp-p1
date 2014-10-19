#include <iostream>
#include <stdexcept>

#include "../read/read.h"
#include "common.h"
#include "solution_3.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////
//                            Point d'entrée du programme                               //
//////////////////////////////////////////////////////////////////////////////////////////
int main (int argc, char* argv[]){

	//Variable liée à la dalle
	dalle dalle;

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

	//Formule d'accés à i ligne et j colonne
	// i * heigth + j
	//Affichage des informations de la dalle
	//et du contenu de la dalle
	cout << "largeur= " << dalle.dim.width << " / " << "hauteur= " << dalle.dim.heigth << endl;

	//Variable liée au plus grand rectangle
	point coord = {.x = 0, .y = 0};
	rect rect = {.width = 0, .heigth = 0};

	if(solution3(dalle, rect, coord)) {
		//Affichage
		cout << endl;
		cout << "Caractéristique du plus grand rectangle :" << endl;
		cout << "- coordonnée x: " << coord.x << endl;
		cout << "- coordonnée y: " << coord.y << endl;
		cout << "- largeur : "     << rect.width << endl;
		cout << "- hauteur : "     << rect.heigth << endl;
	} else  {
		cout << "dallage noir. Pas de rectangle blanc possible." << endl;
	}

	delete[] dalle.data;
	return 0;
}