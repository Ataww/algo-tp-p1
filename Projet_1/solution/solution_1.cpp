#include <iostream>
#include <stdexcept>
using namespace std;
#include "../read/read.h"
#include "common.h"


/////////////////////////////////////////////////////////
//Test si un retangle ne contient pas de case noir     //
// Retourne VRAI si aucune case noir n'est trouné      //
//               sinon FAUX                            //
/////////////////////////////////////////////////////////
bool isValide(dalle& dalle, point source, int h_rect, int w_rect){
	for(int case_y = source.y; case_y <= h_rect; case_y++){
		for(int  case_x = source.x; case_x <= w_rect; case_x++){
			if(dalle.data[case_y*dalle.dim.width+case_x] == false) 
				return false;
		}
	}
	return true;
}


/////////////////////////////////////////////////////////
//Fonction de recherche de tout les rectangles possible//
//à partir de source.x et source.y                     //
/////////////////////////////////////////////////////////
void searchRect(dalle& dalle, rect& r, point& coord, int source_x, int source_y){

	//On stocke la largeur et la hauteur du plus grand rectangle
	rect maxRect = {.width = r.width, .height = r.height};

	point source = {.x = source_x, .y = source_y};

	//On regarde tout les rectangle possible depuis le point source(x,y)
	for(int h_rect = source.y; h_rect < dalle.dim.height; h_rect++){
		for(int w_rect = source.x; w_rect < dalle.dim.width; w_rect++){
			//on vérifie qu'un rectangle valide existe depuis les coordonnées source
			if(isValide(dalle, source, h_rect, w_rect)){
				if( (w_rect - source.x + 1)*(h_rect - source.y + 1) > maxRect.width * maxRect.height){
					//si le rectangle trouvé est plus grand que l'actuel max on remplace
					maxRect.width = w_rect-source.x + 1;
					maxRect.height = h_rect-source.y + 1;
				}
			}
		}
	}

	//Mise à jour des info du plus grand rectangle
	if(maxRect.width * maxRect.height > r.width * r.height){
		r.width = maxRect.width;
		r.height = maxRect.height;
		coord.x = source.x;
		coord.y = source.y;
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
		return 0;
	}

	//Création de la dalle
	try{
		dalle.data = createDalle( dalle.dim.width, dalle.dim.height, argv[1]);
	}
	catch(range_error& e){
		cout << e.what() << endl;
		return 0;
	}

	//Formule d'accés à i ligne et j colonne
	// i * height + j
	//Affichage des informations de la dalle
	//et du contenu de la dalle
	cout << "largeur= " << dalle.dim.width << " / " << "hauteur= " << dalle.dim.height << endl;

	bool zeroFound = false;
	bool unFound   = false;

	for(int i = 0; i < dalle.dim.height; i++){
		for(int j = 0; j < dalle.dim.width; j++){
			if(dalle.data[i*dalle.dim.width+j]){
				cout << '0';
				zeroFound = true;
			}
			else{
				cout << '1';
				unFound = true;
			}
		}
		cout << endl;
	}

	//Si le dallage est noir et blanc
	if(zeroFound && unFound)
		//recherche du plus grand rectangle
		for(int i = 0; i < dalle.dim.height; i++){
			for(int j = 0; j < dalle.dim.width; j++){
				searchRect(dalle, rect, coord, i, j);
			}
		}

	//Si le dallage est entièrement noir
	if(unFound && !zeroFound){
		cout << "Le dallage est noir, il n'y a aucun rectangle" << endl;
		return 0;
	}


	//Affichage
	cout << endl;
	cout << "Caractéristique du plus grand rectangle :" << endl;
	cout << "- coordonnée x: " << coord.x << endl;
	cout << "- coordonnée y: " << coord.y << endl;
	cout << "- largeur : "     << rect.width << endl;
	cout << "- hauteur : "     << rect.height << endl;

	return 0;
} 
