#ifndef SOLUTION_2_H
#define SOLUTION_2_H

#include "common.h"

/**
* Compte le nombre de cases blanches sur une ligne donnée, depuis une position donnée.
* s'arrête en fin de ligne ou dés que la dalle est noire.
*
* dalle: la dallage contenant la ligne à traiter.
* x: l'abscisse de départ du comptage.
* y: l'ordonnée de départ du comptage.
*/
int measureLine(const dalle& dalle, int x, int y);

/**
* Recherche le plus grand rectangle de dalles blanches depuis la postion donnée.
* Enumère tous les rectangles possibles avec pour origine une case donnée et sélectionne le plus grand.
*
* dalle: le dallage dans lequel on recherche le rectangle.
* max: le plus grand rectangle.
* start: les coordonnées du coin supérieur gauche des rectangles à énumérer.
* coord: les coordonnées du coin supérieur gauche du plus grand rectangle.
*/
void rectTraverse(const dalle& dalle, rect& max, const point& start, point& coord);

/**
* Enumère tout les coins supérieurs gauche possibles pour un rectangle blanc puis recherche le plus grand rectangle. 
* 
* dalle: le dallage dans lequel on recherche le rectangle.
* max: le plus grand rectangle.
* coord: les coordonnées du coin supérieur gauche du plus grand rectangle.
*/
void searchRect(const dalle& dalle, rect& max, point& coord);

/**
* Point d'entrée pour la solution 2. Analyse la dalle pour quelques cas particuliers.
* dalle: le dallage dans lequel on cherche le rectangle.
* max: référence du plus grand rectangle. 
*	Le rectangle donnée doit être de dimension (0,0) et le rectangle maximal est retourné.
* coord: référence des coordonnées du plus grand rectangle.
*	Les coordonnées données doivent être à (0,0) et les coordonnées du rectangle maximal sont retournées.
*/
bool solution2(const dalle& dalle, rect& max, point& coord);

//header guard
#endif