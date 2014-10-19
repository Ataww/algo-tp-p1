#include <iostream>
#include <stdexcept>


#include "../read/read.h"
#include "common.h"
#include "stack.h"
#include "solution_4.h"

using namespace std;

void openRect(stack& s, const int& col, const int& height) {
	stack_item si = {.col = col, .height = height};
	push(s, si);
}

void shrinkRects(stack& s, const int& height, const int& col, rect& max, point& coord) {
	stack_item si;
	do {
		si = pop(s);
		rect tmp;
		tmp.height = si.height;
		tmp.width = col - si.col;
		if(tmp > max ) {
			max = tmp;
		}
	} while(!empty(s) && si.height > height);
	si.height = height;
	push(s, si);
}

void lineTraverse(const dalle& dalle, stack& s, rect& max, point& coord, const int tabHeight[], int line) {
	int prev = tabHeight[0];
	openRect(s, 0, tabHeight[0]);
	for(int i = 1; i < dalle.dim.width; i++) {
		if(tabHeight[i] > prev) {
			//openRect(s,i, tabHeight[i]);
			cout << "open ligne: " << line << ", col: " << i << endl;
		} else if(tabHeight[i] < prev) {
			//shrinkRects(s, tabHeight[i], i, max, coord);
			cout << "close ligne: " << line << ", col: " << i << endl;
		}
		prev = tabHeight[i];
	}
}

bool solution4(const dalle& dalle, rect& max, point& coord) {
 	bool whiteFound = false;
 	bool blackFound = false;

	checkDalle(dalle, whiteFound, blackFound, true);

	stack pile = createEmptyStack(STACK_INITIAL_SIZE);
	cout << "pile" << endl;
	int tabH[dalle.dim.height * dalle.dim.width];


	if(blackFound && ! whiteFound) {
		cout << "Le dallage est noir, aucun rectangle blanc n'existe" << endl;
		return false;
	} else if(!blackFound && whiteFound) {
		max = dalle.dim;
	} else {
		for(int i = 0; i < dalle.dim.height; i++){
			fillTabH(dalle, tabH, i, false);
			lineTraverse(dalle, pile, max, coord, tabH, i);
		}
	}
	return true;
}

