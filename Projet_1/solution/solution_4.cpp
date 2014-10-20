#include <iostream>
#include <stdexcept>

#include "../read/read.h"
#include "common.h"
#include "stack.h"
#include "solution_4.h"

using namespace std;

// Ouvre un rectangle commencant à la colonne col et de hauteur height.
void openRect(stack& s, const int& col, const int& height) {
	stack_item si = {.col = col, .height = height};
	push(s, si);
}

// Compare le rectangle fermé avec le plus grand rectangle actuel.
void calcRect(rect& max, point& coord, const stack_item& si, const int& col, const int& line) {
	rect tmp;
	tmp.height = si.height;
	tmp.width = col - si.col;
	if(tmp > max) {
		//si le rectangle fermé est plus grand que le rectangle maximal on remplace
		max = tmp;
		coord.x = si.col;
		coord.y = line - si.height +1;
	}
}

// Ferme les rectangles contenus dans la pile s d'un hauteur supérieure à height.
void closeRects(stack& s, const int& height, const int& col, const int& line, rect& max, point& coord) {
	stack_item si = {.col=0, .height=0};
	while(!empty(s)) {
		try {
			pop(s, si);
			if(si.height <= height) { break;}
			calcRect(max, coord, si, col, line);
		} catch(range_error& e) {
			cout << e.what() << endl;
			break;
		}
	}
	// on réduit le dernier rectangle dépilé et on le replace dans la pile.
	// sauf si la hauteur est de 0, dans ce cas on ferme tous les rectangle.
	if(height > 0) {
		si.height = height;
		push(s, si);
	}
	
}

// Parcourt la ligne line sur le tableau des hauteurs pour rechercher le rectangle maximal.
void lineTraverse(const rect& dim, stack& s, rect& max, point& coord, const int tabHeight[], int line) {
	int w = dim.width * line;
	int prev = tabHeight[w];
	if(prev > 0) {
		//si la hauteur de la première colonne est > 0 on ouvre un rectangle
		openRect(s, 0, prev);
	}
	//on avance par colonne sur la ligne.
	for(int i = 1; i < dim.width; i++) {
		if(tabHeight[w+i] > prev) {
			//si la hauteur est plus grande que la précédente on ouvre un rectangle
			openRect(s,i, tabHeight[w+i]);
		} else if(tabHeight[w+i] < prev || i == dim.width-1) {
			// si la hauteur de la colonne est moins grande que la précédente ou dernière colonne
			closeRects(s, tabHeight[w+i], i, line, max, coord);
		}
		prev = tabHeight[w+i];
	}
	while(!empty(s)) {
		stack_item si; //on vide la stack complètement.
		pop(s, si);
	}
}

bool solution4(const dalle& dalle, rect& max, point& coord) {
 	bool whiteFound = false;
 	bool blackFound = false;

	checkDalle(dalle, whiteFound, blackFound, S4_DISPLAY);

	stack pile = createEmptyStack(STACK_INITIAL_SIZE);
	int tabH[dalle.dim.width*dalle.dim.height];


	if(blackFound && ! whiteFound) {
		cout << "Le dallage est noir, aucun rectangle blanc n'existe" << endl;
		return false;
	} else if(!blackFound && whiteFound) {
		max = dalle.dim;
	} else {
		for(int i = 0; i < dalle.dim.height; i++){
			//on remplit le tableau des hauteurs pour la ligne i
			fillTabH(dalle, tabH, i, S4_DISPLAY);
			//on parcourt la ligne i à la recherche du rectangle maximal
			lineTraverse(dalle.dim, pile, max, coord, tabH, i);
		}
	}
	return true;
}

