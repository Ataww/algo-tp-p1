#ifndef SOLUTION_4_H
#define SOLUTION_4_H

#include "common.h"
#include "stack.h"
#include "solution_3.h"

void openRect(stack& s, const int& col, const int& height);

void closeRect(rect& max, point& coord, const stack_item& si, const int& col, const int& line);

void shrinkRects(stack& s, const int& height, const int& col, const int& line, rect& max, point& coord);

void lineTraverse(const dalle& dalle, stack& s, rect& max, point& coord, const int tabHeight[], int line);

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