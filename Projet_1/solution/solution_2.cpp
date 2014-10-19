#include <iostream>
#include <stdexcept>
using namespace std;
#include "../read/read.h"
#include "common.h"
#include "solution_2.h"


// Compte le nombre de cases blanches sur une ligne donnée, depuis une position donnée.
int measureLine(const dalle& dalle, int x, int y) {
	int width = 0;
	// on parcourt la ligne en cours depuis l'index start.x jusqu'à la fin de ligne ou une dalle noire
	for(int i = x; dalle.data[dalle.dim.width*y+i] && i < dalle.dim.width; i++ ) {
		width++;
	}
	//on retourne la largeur du rectangle
	return width;
}

// Recherche le plus grand rectangle de dalles blanches depuis la postion donnée.
void rectTraverse(const dalle& dalle, rect& max, const point& start, point& coord) {
	rect current = { .width=dalle.dim.width, .heigth=0};

	for(int j = start.y; j < dalle.dim.heigth; j++) {
		//on évalue chaque ligne jusqu'à ce que la premièe case soit noire.
		if(!dalle.data[j*dalle.dim.width+start.x]) { break;}

		int ligne = measureLine(dalle, start.x, j);
		current.width = (ligne < current.width) ? ligne : current.width;
		current.heigth++;
		//si le rectangle calculé est plus grand que le plus grand actuel on le remplace.
		if(current > max) {
			max = current;
			coord = start;
		}
	}
}


// Enumère tout les coins supérieurs gauche possibles pour un rectangle blanc puis recherche le plus grand rectangle.
void searchRect(const dalle& dalle, rect& max, point& coord) {
	for(int i = 0; i < dalle.dim.width; i++) {
		for(int j = 0; j < dalle.dim.heigth; j++) {
			if(dalle.data[j*dalle.dim.width+i]) {
				point start = {.x=i, .y=j};
				rectTraverse(dalle, max, start, coord);
			}
		}
	}
}

// Point d'entrée de la solution 2.
bool solution2(const dalle& dalle, rect& max, point& coord) {
	bool whiteFound = false;
	bool blackFound = false;

	checkDalle(dalle, whiteFound, blackFound, false);

	if(blackFound && !whiteFound) {
		return false;
	} else if(!blackFound && whiteFound) {
		max = dalle.dim;
		return true;
	} else {
		searchRect(dalle, max, coord);
		return true;
	}
}

