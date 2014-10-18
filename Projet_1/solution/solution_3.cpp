#include <iostream>
#include <stdexcept>

#include "../read/read.h"
#include "common.h"

using namespace std;

//////////////////////////////////////////////////////////////
// 	Fonction remplissant la ligne du tableau de hauteurs    //
//	dont l'indice est passé en paramètre.					//
//	Paramètre:												//
//		dalle: dalle de référence							//
//		tab: le tableau de hauteurs           				//
//		indice: indice de la ligne à rempli         		//            
//////////////////////////////////////////////////////////////
void fillTabH(const dalle& dalle, int tab[], const int indice, const bool display){

	int w = dalle.dim.width;

	if(indice == 0){
		//Si l'on regarde la première ligne de dalle
		for(int j = 0; j < w; j++){
			if(dalle.data[j])
				tab[j] = 1;
			else
				tab[j] = 0;
		}
	}else{
		//Sinon on remplit en ayant accés à la ligne précedente
		for(int j = 0; j < w; j++){
			if(!dalle.data[indice*w+j])
				tab[indice*w+j] = 0;
			else{
				if(dalle.data[(indice-1)*w+j])
					tab[indice*w+j] = tab[(indice-1)*w+j] + 1;
				else
					tab[indice*w+j] = 1;
			}
		}
	}

	//Affichage du tableau de hauteur
	if(display){
		for(int j = 0; j < w; j++)
			cout << tab[indice*w+j];
		cout << endl;
	}
}

//////////////////////////////////////////////////////////////
//	Fonction cherchant les rectangles d'une ligne.          //
//  Elle met à jour les caractéristiques du plus grand.     //
// 	Paramètres:												//
//		tab: le tableau de hauteurs 						//
//		indice: indice de la ligne à regarder				//
//		rectMax: plus grand rectangles						//
//		coordMax: coordonnée du plus grand rectangles 		//
//		dalle: tableau du dallage
//////////////////////////////////////////////////////////////
void searchMaxRectLine(const int tab[], const int indice, rect& rectMax, point& coordMax, const dalle& dalle){

	int w = dalle.dim.width;
	int hMin;
	rect currentR = {.width = 0, .height = 0};

	for(int x_begin = 0; x_begin < w; x_begin++){
		hMin = tab[indice*w+x_begin];
		for(int x_end = x_begin; x_end < w; x_end++){
			if(tab[indice*w+x_end] < hMin)
				hMin = tab[indice*w+x_end];
			currentR.width = x_end - x_begin + 1;
			currentR.height = hMin;
			if(rectMax < currentR){
				rectMax = currentR;
				coordMax.x = x_begin;
				coordMax.y = indice-hMin+1;
			}
		}
	}

}

bool solution3(const dalle& dalle, rect& max, point& coord) {
	bool whiteFound = false;
	bool blackFound   = false;

	checkDalle(dalle, whiteFound, blackFound, true);

	//Tableau des hauteurs
	int tabH[dalle.dim.width*dalle.dim.height];
		
	if(blackFound && !whiteFound) {
		return false;
	} else if(!blackFound && whiteFound) {
		max = dalle.dim;
		return true;
	} else {
		for(int i = 0; i < dalle.dim.height; i++){
			fillTabH(dalle, tabH, i, false);
			searchMaxRectLine(tabH,i, max, coord, dalle);
		}
	}
	return true;
}