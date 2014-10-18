#ifndef SOLUTION_3_H
#define SOLUTION_3_H

#include "common.h"

//////////////////////////////////////////////////////////////
// 	Fonction remplissant la ligne du tableau de hauteurs    //
//	dont l'indice est passé en paramètre.					//
//	Paramètre:												//
//		dalle: dalle de référence							//
//		tab: le tableau de hauteurs           				//
//		indice: indice de la ligne à rempli         		//            
//////////////////////////////////////////////////////////////
void fillTabH(const dalle& dalle, int tab[], const int indice, const bool display);

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
void searchMaxRectLine(const int tab[], const int indice, rect& rectMax, point& coordMax, const dalle& dalle);

bool solution3(const dalle& dalle, rect& max, point& coord);

// header guard
#endif