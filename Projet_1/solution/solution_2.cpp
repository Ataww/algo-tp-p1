#include <iostream>
#include <stdexcept>
using namespace std;
#include "../read/read.h"
#include "common.h"

/**
*/
int processLine(const dalle& dalle, point start) {
	if(start.x >= dalle.dim.width) {
		throw new range_error("Index de départ supérieur à la largeur du dallage");
	} else if(start.y >= dalle.dim.height) {
		throw new range_error("Index de ligne supérieur à la hauteur du dallage");
	}
	int width = 0;
	// on parcourt la ligne en cours depuis l'index start.x jusqu'à la fin de ligne ou une dalle noire
	for(int i = start.x; dalle.data[dalle.dim.width*start.y+i] && i < dalle.dim.width; i++ ) {
		width++;
	}
	//on retour la largeur du rectangle
	return width;
}

void searchRect(const dalle& dalle, rect& r, point& coord) {
	rect max = r;
	for(int i = 0; i < dalle.dim.width; i++) {
		for(int j = 0; j < dalle.dim.height; j++) {
			if(dalle.data[j*dalle.dim.width+i]) {
				point start = {.x=i, .y=j};
				int ligne = processLine(dalle, start);
				cout << "ligne(" << i << "," << j << ") -> length: " << ligne << endl;
			}
		}
	}
}

void searchByCol(const dalle& dalle, rect& r, int row, int col) {

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

	delete[] dalle.data;
	return 0;
}