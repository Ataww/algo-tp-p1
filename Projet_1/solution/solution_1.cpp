#include <iostream>
using namespace std;
#include "../read/read.h"


/////////////////////////////////////////////////////////
//Test si un retangle ne contient pas de case noir     //
// Retourne VRAI si aucune case noir n'est trouné      //
//               sinon FAUX                            //
/////////////////////////////////////////////////////////
bool isValide(bool* dalle, int x, int y, int h_rect, int w_rect, int w){
	for(int case_y = y; case_y <= h_rect; case_y++){
		for(int  case_x = x; case_x <= w_rect; case_x++){
			if(dalle[case_y*w+case_x] == false) 
				return false;
		}
	}
	return true;
}


/////////////////////////////////////////////////////////
//Fonction de recherche de tout les rectangles possible//
//à partir de source_x et source_y                     //
/////////////////////////////////////////////////////////
void searchRect(bool* dalle, int& rect_width, int& rect_height, int& coord_x, int& coord_y, int source_x, int source_y, int w, int h){

	//On stocke la largeur et la hauteur du plus grand rectangle
	int maxW = rect_width;
	int maxH = rect_height;

	//On regarde tout les rectangle possible depuis le point source(x,y)
	for(int h_rect = source_y; h_rect < h; h_rect++){
		for(int w_rect = source_x; w_rect < w; w_rect++){

			if(isValide(dalle, source_x, source_y, h_rect, w_rect, w)){
				if( (w_rect-source_x+1)*(h_rect-source_y+1) > maxW*maxH){
					maxW = w_rect-source_x+1;
					maxH = h_rect-source_y+1;
				}
			}
		}
	}

	//Mise à jour des info du plus grand rectangle
	if(maxW*maxH > rect_width*rect_height){
		rect_width = maxW;
		rect_height = maxH;
		coord_x = source_x;
		coord_y = source_y;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
//                            Point d'entrée du programme                               //
//////////////////////////////////////////////////////////////////////////////////////////
int main (int argc, char* argv[]){

	//Variable liée à la dalle
	bool* dalle = NULL;		
	int width;
	int height;
	//Variable liée au plus gradn rectangle
	int coord_x = 0;
	int coord_y = 0;
	int rect_width = 0; 
	int rect_height= 0;;

	//Test présence nom de fichier
	if(argc != 2){
		cout << "ERRREUR sur les paramètres d'appel" << endl;
		return 0;
	}

	//Création de la dalle
	try{
		dalle = createDalle( width, height, argv[1]);
	}
	catch(range_error& e){
		cout << e.what() << endl;
		return 0;
	}

	//Formule d'accés à i ligne et j colonne
	// i * height + j
	//Affichage des informations de la dalle
	//et du contenu de la dalle
	cout << "largeur= " << width << " / " << "hauteur= " << height << endl;

	bool zeroFound = false;
	bool unFound   = false;

	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			if(dalle[i*width+j]){
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
		for(int i = 0; i < height; i++){
			for(int j = 0; j < width; j++){
				searchRect(dalle, rect_width, rect_height, coord_x, coord_y, i, j, width, height);
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
	cout << "- coordonnée x: " << coord_x << endl;
	cout << "- coordonnée y: " << coord_y << endl;
	cout << "- largeur : "     << rect_width << endl;
	cout << "- hauteur : "     << rect_height << endl;

	return 0;
} 
