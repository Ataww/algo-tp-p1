#include <iostream>
#include <stdexcept>

#include "solution_4.h"

using namespace std;

int main(int argc, char* argv[]) {

		//on vérifie qu'un fichier est donné en entrée.
	if(argc != 2) {
		cout << "ERRREUR sur les paramètres d'appel" << endl;
		return -1;
	}

	dalle dalle;

	try {
		dalle.data = createDalle(dalle.dim.width, dalle.dim.heigth, argv[1]);
	} catch(range_error& e) {
		cout << e.what() << endl;
		return -1;
	}

	cout << "largeur: " << dalle.dim.width << " / " << "hauteur: " << dalle.dim.heigth << endl;

	bool black = false;
	bool white = false;
	//on vérifie la dalle et on l'affiche.
	checkDalle(dalle, white, black, true);

	if(black && !white) {
		//Si le dallage est entièrement noir
		cout << "Le dallage est noir, il n'y a aucun rectangle" << endl;
		delete[] dalle.data;
		return 0;
	}
	rect rect = {.width=0, .heigth=0};
	point coord = {.x=0, .y=0};

	if(!black && white) {
		// si la dalle est toute blanche
		rect.width = dalle.dim.width;
		rect.heigth = dalle.dim.heigth;
	} else {
		//sinon lance la recherche.
		stack s = createEmptyStack(STACK_INITIAL_SIZE);
	}

	//Affichage
	cout << endl;
	cout << "Caractéristique du plus grand rectangle :" << endl;
	cout << "- coordonnée x: " << coord.x << endl;
	cout << "- coordonnée y: " << coord.y << endl;
	cout << "- largeur : "     << rect.width << endl;
	cout << "- hauteur : "     << rect.heigth << endl;

	delete[] dalle.data;
	return 0;
}