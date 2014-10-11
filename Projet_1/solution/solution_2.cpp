#include <iostream>
#include <stdexcept>
using namespace std;
#include "../read/read.h"
#include "common.h"

int processLine(const dalle& dalle, int line, int start) {
	if(start >= dalle.dim.width) {
		throw new range_error("Index de départ supérieur à la largeur du dallage");
	} else if(line >= dalle.dim.height) {
		throw new range_error("Index de ligne supérieur à la hauteur du dallage");
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
	bool white = true;


	checkDalle(dalle, white, black, true);

	return 0;
}