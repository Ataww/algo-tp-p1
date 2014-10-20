#ifndef SOLUTION_4_H
#define SOLUTION_4_H

#include "common.h"
#include "stack.h"
#include "solution_3.h"

// active ou non l'affichage.
#define S4_DISPLAY false

/**
* Ouvre un rectangle commencant à la colonne col et de hauteur height.
* Le rectangle ouvert est placé au sommet de la pile s.
* stack: La pile de rectangle.
* col: La colonne de départ du rectangle à ouvrir.
* height: La hauteur du rectangle à ouvrir.
*/
void openRect(stack& s, const int& col, const int& height);

/**
* Compare le rectangle fermé avec le plus grand rectangle actuel.
* Le rectangle fermé est calculé comme suit: width = col - si.col, height = si.height.
* max: Le rectangle maximal, remplacé par le rectangle fermé si plus grand.
* coord: Les coordonnées du point supérieur gauche du rectangle maximal. Remplacées par celles du rectangle fermé si plus grand.
* si: Le stack_item correspondant au rectangle fermé.
* col: La colonne actuelle utilisée pour la largeur du rectangle fermé.
* line: La ligne actuelle, utilisée pour les coordonnées du rectangle fermé.
*/
void calcRect(rect& max, point& coord, const stack_item& si, const int& col, const int& line);

/**
* Ferme les rectangles contenus dans la pile s d'un hauteur supérieure à height.
* Le dernier rectangle fermé est réduit à la hauteur height et replacé dans la pile.
* s: La pile depuis laquelle on récupère les rectangles fermés.
* height: La hauteur de la colonne actuelle.
* col: L'indice de la colonne actuelle.
* line: L'indice de la ligne actuelle.
* max: Le rectangle maximal.
* coord: Les coordonnées du point supérieur gauche du rectangle maximal.
*/
void closeRects(stack& s, const int& height, const int& col, const int& line, rect& max, point& coord);

/**
* Parcourt la ligne line sur le tableau des hauteurs pour rechercher le rectangle maximal.
* dim: Les dimensions de la dalle.
* max: Le rectangle maximal.
* coord: Les coordonnées du point supérieur gauche du rectangle maximal.
* tabHeight: Le tableau des hauteurs. cf solution 3.
* line: L'indice de ligne actuel.
*/
void lineTraverse(const rect& dim, stack& s, rect& max, point& coord, const int tabHeight[], int line);

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