#include <iostream>
#include <stdexcept>

#include "../read/read.h"
#include "common.h"
#include "solution_4.h"

using namespace std;

void openRect(stack& s, const int& col, const int& heigth) {
	stack_item si = {.col = col, .heigth = heigth};
	push(s, si);
}

void shrinkRects(stack& s, const int& heigth, const int& col, rect& max point& coord) {
	stack_item si;
	do {
		si = pop(s);
		rect tmp = {.heigth=si.heigth , .width=col-si.col};
		if(tmp > max ) {
			max = tmp;
		}
	} while(!empty(s) && si.heigth > heigth);
	si.heigth = height;
	push(s, si);
}

void lineTraverse(const dalle& dalle, stack& s, rect& max, point& coord, const int* tabHeight, int line) {
	int prev = tabHeight[0];
	openRect(s, 0, tab[0]);
	for(int i = 1; i < dalle.dim.width; i++) {
		if(tab[i] > prev) {
			openRect(s,i, tab[i]);
		} else if(tab[i] < prev) {
			shrinkRect(s, tab[i], i, max, coord);
		}
		prev = tab[i];
	}
}

bool solution4(const dalle& dalle, rect& max, point& coord) {
 	bool whiteFound = false;
 	bool blackFound = false;

	checkDalle(dalle, whiteFound, blackFound, false);

	stack pile = createEmptyStack(STACK_INITIAL_SIZE);
	int tabH[dalle.dim.heigth*dalle.dim.heigth];

	if(blackFound && ! whiteFound) {
		cout << "Le dallage est noir, aucun rectangle blanc n'existe" << endl;
		return false;
	} else if(!blackFound && whiteFound) {
		max = dalle.dim;
	} else {
		for(int i = 0; i < dalle.dim.heigth; i++){
			fillTabH(dalle, tabH, i, false);
			lineTraverse(dalle, pile, max, coord, tabH, i);
		}
	}
	return true;
}
