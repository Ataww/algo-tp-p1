#include <iostream>
#include <stdexcept>
using namespace std;
#include "../read/read.h"
#include "common.h"

/**
* Compte le nombre de cases sur une ligne donnée, depuis une position donnée.
* s'arrête en fin de ligne ou dés que la dalle est noire.
*
* dalle: la dallage contenant la ligne à traiter.
* x: l'abscisse de départ du comptage.
* y: l'ordonnée de départ du comptage.
*/
int measureLine(const dalle& dalle, int x, int y) {
	int width = 0;
	// on parcourt la ligne en cours depuis l'index start.x jusqu'à la fin de ligne ou une dalle noire
	for(int i = x; dalle.data[dalle.dim.width*y+i] && i < dalle.dim.width; i++ ) {
		width++;
	}
	//on retourne la largeur du rectangle
	return width;
}

/**
* Recherche le plus grand rectangle de dalles blanches depuis la postion donnée.
* Enumère tous les rectangles possibles avec pour origine une case donnée et sélectionne le plus grand.
*
* dalle: le dallage dans lequel on recherche le rectangle.
* max: le plus grand rectangle.
* start: les coordonnées du coin supérieur gauche des rectangles à énumérer.
* coord: les coordonnées du coin supérieur gauche du plus grand rectangle.
*/
void rectTraverse(const dalle& dalle, rect& max, const point& start, point& coord) {
	rect current = { .width=dalle.dim.width, .height=0};

	for(int j = start.y; j < dalle.dim.height; j++) {
		//on évalue chaque ligne jusqu'à ce que la premièe case soit noire.
		if(!dalle.data[j*dalle.dim.width+start.x]) { break;}

		int ligne = measureLine(dalle, start.x, j);
		current.width = (ligne < current.width) ? ligne : current.width;
		current.height++;
		//si le rectangle calculé est plus grand que le plus grand actuel on le remplace.
		if(current > max) {
			max = current;
			coord = start;
		}
	}
}

/**
* Enumère tout les coins supérieurs gauche possibles pour un rectangle blanc puis recherche le plus grand rectangle. 
* 
* dalle: le dallage dans lequel on recherche le rectangle.
* max: le plus grand rectangle.
* coord: les coordonnées du coin supérieur gauche du plus grand rectangle.
*/
void searchRect(const dalle& dalle, rect& max, point& coord) {
	for(int i = 0; i < dalle.dim.width; i++) {
		for(int j = 0; j < dalle.dim.height; j++) {
			if(dalle.data[j*dalle.dim.width+i]) {
				point start = {.x=i, .y=j};
				rectTraverse(dalle, max, start, coord);
			}
		}
	}
}

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
	rect rect = {.width=0, .height=0};
	point coord = {.x=0, .y=0};

	if(!black && white) {
		// si la dalle est toute blanche
		rect.width = dalle.dim.width;
		rect.height = dalle.dim.height;
	} else {
		//sinon lance la recherche.
		searchRect(dalle, rect, coord);
	}

	//Affichage
	cout << endl;
	cout << "Caractéristique du plus grand rectangle :" << endl;
	cout << "- coordonnée x: " << coord.x << endl;
	cout << "- coordonnée y: " << coord.y << endl;
	cout << "- largeur : "     << rect.width << endl;
	cout << "- hauteur : "     << rect.height << endl;

	delete[] dalle.data;
	return 0;
}