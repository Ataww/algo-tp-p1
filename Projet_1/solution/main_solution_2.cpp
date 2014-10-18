#include <iostream>
#include <stdexcept>
#include "../read/read.h"
#include "common.h"
#include "solution_2.h"


using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////
//                            Point d'entrée du programme                               //
//////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]) {

	//on vérifie qu'un fichier est donné en entrée.
	if(argc != 2) {
		cout << "ERRREUR sur les paramètres d'appel" << endl;
		return -1;
	}

	dalle dalle;

	try {
		dalle.data = createDalle(dalle.dim.width, dalle.dim.height, argv[1]);
	} catch(range_error& e) {
		cout << e.what() << endl;
		return -1;
	}

	cout << "largeur: " << dalle.dim.width << " / " << "hauteur: " << dalle.dim.height << endl;

	rect rect = {.width=0, .height=0};
	point coord = {.x=0, .y=0};

	if(solution2(dalle, rect, coord)) {
		//Affichage
		cout << endl;
		cout << "Caractéristique du plus grand rectangle :" << endl;
		cout << "- coordonnée x: " << coord.x << endl;
		cout << "- coordonnée y: " << coord.y << endl;
		cout << "- largeur : "     << rect.width << endl;
		cout << "- hauteur : "     << rect.height << endl;
	} else {
		cout << "Le dallage est noir, aucun rectangle blanc n'existe." << endl;
	}

	delete[] dalle.data;
	return 0;
}