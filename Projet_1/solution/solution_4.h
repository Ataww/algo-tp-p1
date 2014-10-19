#ifndef SOLUTION_4_H
#define SOLUTION_4_H

#include "common.h"
#include "stack.h"
#include "solution_3.h"

void openRect(stack& s, const int& col, const int& heigth);

void shrinkRect(stack& s, const int& heigth);

void closeRect(rect& max/*aire calculée*/);



/**
* Point d'entrée pour la solution 2. Analyse la dalle pour quelques cas particuliers.
* dalle: le dallage dans lequel on cherche le rectangle.
* max: référence du plus grand rectangle. 
*	Le rectangle donnée doit être de dimension (0,0) et le rectangle maximal est retourné.
* coord: référence des coordonnées du plus grand rectangle.
*	Les coordonnées données doivent être à (0,0) et les coordonnées du rectangle maximal sont retournées.
*/
bool solution4(const dalle& dalle, rect& max, point& coord);

//header guard
#endif