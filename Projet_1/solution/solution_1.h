#ifndef SOLUTION_1_H
#define SOLUTION_1_H

/**
*Test si un retangle ne contient pas de case noir     
* Retourne VRAI si aucune case noir n'est trouné      
*               sinon FAUX                            
*/
bool isValide(const dalle& dalle, point source, int h_rect, int w_rect);


/**
*Fonction de recherche de tout les rectangles possible
*à partir de source.x et source.y                     
*/
void searchRect(const dalle& dalle, rect& r, point& coord, int source_x, int source_y);

/**
* Point d'entrée pour la solution 1. Analyse la dalle pour quelques cas particuliers.
* dalle: le dallage dans lequel on cherche le rectangle.
* max: référence du plus grand rectangle. 
*	Le rectangle donnée doit être de dimension (0,0) et le rectangle maximal est retourné.
* coord: référence des coordonnées du plus grand rectangle.
*	Les coordonnées données doivent être à (0,0) et les coordonnées du rectangle maximal sont retournées.
*/
bool solution_1(const dalle& dalle, rect& rect, point& coord);

#endif