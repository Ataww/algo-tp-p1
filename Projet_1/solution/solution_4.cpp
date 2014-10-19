#include <iostream>
#include <stdexcept>

#include "../read/read.h"
#include "common.h"
#include "stack.h"
#include "solution_4.h"

using namespace std;

//on ouvre un rectangle et le place dans la pile.
void openRect(stack& s, const int& col, const int& height) {
	stack_item si = {.col = col, .height = height};
	cout << "open: " << si << endl;
	push(s, si);
}

//on calcule l'aire des rectangles fermés et on met à jour le plus grand rectangle si besoin est.
void calcRect(rect& max, point& coord, const stack_item& si, const int& col, const int& line) {
	rect tmp;
	tmp.height = si.height;
	tmp.width = col - si.col;
	if(tmp > max) {
		max = tmp;
		coord.x = si.col;
		coord.y = line - si.height +1;
		cout << "max is now: " << max << " at " << coord << endl;
	}
}

// ferme tous les rectangles supérieurs à la hauteur height à la colonne col. Le dernier rectangle est réduit à la hauteur height.
void closeRects(stack& s, const int& height, const int& col, const int& line, rect& max, point& coord) {
	stack_item si = {.col=0, .height=0};
	while(!empty(s)) {
		try {
			pop(s, si);
			if(si.height <= height) { break;}
			cout << "shrink: " << si << endl;
			calcRect(max, coord, si, col, line);
		} catch(range_error& e) {
			cout << e.what() << endl;
			break;
		}
	}
	si.height = height;
	push(s, si);
	
}

void lineTraverse(const dalle& dalle, stack& s, rect& max, point& coord, const int tabHeight[], int line) {
	int w = dalle.dim.width * line;
	cout << "traverse line " << line << endl;
	int prev = tabHeight[w];
	if(prev > 0) {
		//si la hauteur de la première colonne est > 0 on ouvre un rectangle
		openRect(s, 0, prev);
	}
	//on avance par colonne sur la ligne.
	for(int i = 1; i < dalle.dim.width; i++) {
		if(tabHeight[w+i] > prev) {
			//si la hauteur est plus grande que la précédente on ouvre un rectangle
			openRect(s,i, tabHeight[w+i]);
		} else if(tabHeight[w+i] < prev) {
			// si la hauteur de la colonne est moins grande que la précédente
			closeRects(s, tabHeight[w+i], i, line, max, coord);
		}
		prev = tabHeight[w+i];
	}

	while(!empty(s)) {
		stack_item si;
		pop(s, si);
	}
}

bool solution4(const dalle& dalle, rect& max, point& coord) {
 	bool whiteFound = false;
 	bool blackFound = false;

	checkDalle(dalle, whiteFound, blackFound, true);

	stack pile = createEmptyStack(STACK_INITIAL_SIZE);
	int tabH[dalle.dim.width*dalle.dim.height];


	if(blackFound && ! whiteFound) {
		cout << "Le dallage est noir, aucun rectangle blanc n'existe" << endl;
		return false;
	} else if(!blackFound && whiteFound) {
		max = dalle.dim;
	} else {
		for(int i = 0; i < dalle.dim.height; i++){
			fillTabH(dalle, tabH, i, true);
			lineTraverse(dalle, pile, max, coord, tabH, i);
		}
	}
	return true;
}

