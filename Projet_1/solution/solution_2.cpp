#include <iostream>
#include <stdexcept>
using namespace std;
#include "../read/read.h"
#include "common.h"

/**
*/
int measureLine(const dalle& dalle, int x, int y) {
	if(x >= dalle.dim.width) {
		throw new range_error("Index de départ supérieur à la largeur du dallage");
	} else if(y >= dalle.dim.height) {
		throw new range_error("Index de ligne supérieur à la hauteur du dallage");
	}
	int width = 0;
	// on parcourt la ligne en cours depuis l'index start.x jusqu'à la fin de ligne ou une dalle noire
	for(int i = x; dalle.data[dalle.dim.width*y+i] && i < dalle.dim.width; i++ ) {
		width++;
	}
	//on retourne la largeur du rectangle
	return width;
}

void rectTraverse(const dalle& dalle, rect& max, const point& start, point& coord) {
	rect current = { .width=measureLine(dalle, start.x, start.y), .height=1};
	for(int j = start.y; j < dalle.dim.height; j++) {
		if(!dalle.data[j*dalle.dim.width+start.x]) { break;}

		int ligne = measureLine(dalle, start.x, j);
		current.width = (ligne < current.width) ? ligne : current.width;
		current.height++;
		if(current > max) {
			max = current;
			coord = start;
		}
	}
	//temporaire, pour les rect de 1 case.
	if(current > max) {
		max = current;
		coord = start;
	}
}

void searchRect(const dalle& dalle, rect& r, point& coord) {
	rect max = r;
	for(int i = 0; i < dalle.dim.width; i++) {
		for(int j = 0; j < dalle.dim.height; j++) {
			if(dalle.data[j*dalle.dim.width+i]) {
				point start = {.x=i, .y=j};
				rectTraverse(dalle, max, start, coord);
			}
		}
	}
}

int main(int argc, char* argv[]) {

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
	checkDalle(dalle, white, black, true);

	if(black && !white) {
		//Si le dallage est entièrement noir
		cout << "Le dallage est noir, il n'y a aucun rectangle" << endl;
		delete[] dalle.data;
		return 0;
	}
	rect rect = {.width=0, .height=0};
	point coords = {.x=0, .y=0};

	if(!black && white) {
		// si la dalle est toute blanche
		rect.width = dalle.dim.width;
		rect.height = dalle.dim.height;
	} else {
		searchRect(dalle, rect, coords);
	}

	cout << "rectangle max: " << rect.width << "," << rect.height << " a (" << coords.x << "," << coords.y << ")" << endl;

	delete[] dalle.data;
	return 0;
}