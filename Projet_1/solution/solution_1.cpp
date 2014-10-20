#include <iostream>
#include <stdexcept>
using namespace std;
#include "../read/read.h"
#include "common.h"
#include "solution_1.h"

bool isValide(const dalle& dalle, point source, int h_rect, int w_rect){
	for(int case_y = source.y; case_y <= h_rect; case_y++){
		for(int  case_x = source.x; case_x <= w_rect; case_x++){
			if(dalle.data[case_y*dalle.dim.width+case_x] == false) 
				return false;
		}
	}
	return true;
}


void searchRect(const dalle& dalle, rect& r, point& coord, int source_x, int source_y){

	//On stocke la largeur et la hauteur du plus grand rectangle
	rect maxRect = r;

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
	if(maxRect > r){
		r = maxRect;
		coord = source;
	}
}

bool solution_1(const dalle& dalle, rect& rect, point& coord){

	bool zeroFound = false;
	bool unFound   = false;

	checkDalle(dalle, zeroFound, unFound, S1_DISPLAY);

	//Si le dallage est noir et blanc
	if(zeroFound && unFound) {
		//recherche du plus grand rectangle
		for(int i = 0; i < dalle.dim.height; i++){
			for(int j = 0; j < dalle.dim.width; j++){
				searchRect(dalle, rect, coord, i, j);
			}
		}
	} else if(unFound && !zeroFound) {
		//Si le dallage est entièrement noir
		cout << "Le dallage est noir, il n'y a aucun rectangle" << endl;
		return false;
	} else if(!unFound && zeroFound) {
		// si la dalle est toute blanche
		rect.width = dalle.dim.width;
		rect.height = dalle.dim.height;
	}
	return true;

}
