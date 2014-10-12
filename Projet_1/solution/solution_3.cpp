#include <iostream>
#include <stdexcept>
using namespace std;
#include "../read/read.h"
#include "common.h"

//////////////////////////////////////////////////////////////
// 	Fonction remplissant la ligne du tableau de hauteurs    //
//	dont l'indice est passé en paramètre.					//
//	Paramètre:												//
//		dalle: dalle de référence							//
//		tab: le tableau de hauteurs           				//
//		indice: indice de la ligne à rempli         		//            
//////////////////////////////////////////////////////////////
void fillTabH(const dalle& dalle, int tab[], const int indice){

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

	rect rect = {.width = 0, .height = 0};
	point coord = {.x = 0, .y = 0};
	bool Found = false;
	int w = dalle.dim.width;

	for(int j = 0; j < w; j++){

		int currentH = tab[indice*w+j];

		if(Found && currentH == rect.height)
			//Si la hauteur ne change pas on augmente la taille
			rect.width++;

		if(Found && currentH != rect.height){
			//Si la hauteur change = fin d'un rectangle
			if(rect > rectMax){
				rectMax = rect;
				coordMax = coord;
				cout << rect.height << "  /  " << endl;
			}
			if(tab[indice*w+j] == 0)
				Found = false;
			if(tab[indice*w+j] < rect.width){
				rect.width ++;
				rect.height = currentH;
				coord.y = indice-currentH+1;
			}else{
				Found = false;
			}
		}

		if(!Found && currentH != 0){
			//Si l'on commence un nouveau rectangle
			rect.width = 1;
			rect.height = currentH;
			coord.x = j;
			coord.y = indice-currentH+1;
			Found = true;
		}
	}

	//Mise à jour plus grand rectangle
	if(rect > rectMax){
		rectMax = rect;
		coordMax = coord;
		cout << rect.height << "  /  " << endl;
	}

}



//////////////////////////////////////////////////////////////////////////////////////////
//                            Point d'entrée du programme                               //
//////////////////////////////////////////////////////////////////////////////////////////
int main (int argc, char* argv[]){

	//Variable liée à la dalle
	dalle dalle;

	//Variable liée au plus grand rectangle
	point coord = {.x = 0, .y = 0};
	rect rect = {.width = 0, .height = 0};


	//Test présence nom de fichier
	if(argc != 2){
		cout << "ERRREUR sur les paramètres d'appel" << endl;
		return -1;
	}

	//Création de la dalle
	try{
		dalle.data = createDalle( dalle.dim.width, dalle.dim.height, argv[1]);
	}
	catch(range_error& e){
		cout << e.what() << endl;
		return -1;
	}

	//Formule d'accés à i ligne et j colonne
	// i * height + j
	//Affichage des informations de la dalle
	//et du contenu de la dalle
	cout << "largeur= " << dalle.dim.width << " / " << "hauteur= " << dalle.dim.height << endl;

	bool zeroFound = false;
	bool unFound   = false;

	checkDalle(dalle, zeroFound, unFound, true);

	//Tableau des hauteurs
	int tabH[dalle.dim.width*dalle.dim.height];

	//Si le dallage est noir et blanc
	if(zeroFound && unFound) {
		for(int i = 0; i < dalle.dim.height; i++){
			fillTabH(dalle, tabH, i);
			searchMaxRectLine(tabH,i, rect, coord, dalle);
		}
		for(int i = 0; i<dalle.dim.height; i++){
			for(int j = 0; j < dalle.dim.width; j++)
				cout << tabH[i*dalle.dim.width+j];
			cout << endl;}
	} else if(unFound && !zeroFound) {
		//Si le dallage est entièrement noir
		cout << "Le dallage est noir, il n'y a aucun rectangle" << endl;
		delete[] dalle.data;
		return 0;
	} else if(!unFound && zeroFound) {
		// si la dalle est toute blanche
		rect.width = dalle.dim.width;
		rect.height = dalle.dim.height;
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