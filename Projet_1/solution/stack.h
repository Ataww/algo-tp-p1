#ifndef STACK_H
#define STACK_H

#include "common.h"

// rend le changement de type contenu par la stack plus facile.
#define STACK_ITEM_TYPE stack_item

/**
* Structure représentant un élément d'une stack.
* rect: les dimensions du rectangle.
* coord: les coordonnées du point inférieur gauche du rectangle.
*/
typedef struct stack_item {
	rect rect;
	point coord;
} stack_item;

/**
* structure représentant une pile de rectangles.
* top: indice de la valeur au sommet.
* size: taille de la pile.
* data: tableau contenant les valeurs contenues par la pile.
*/
typedef struct stack {
	unsigned int top;
	size_t size;
	STACK_ITEM_TYPE* data;
}stack;

/**
* Taille initiale par défaut de la stack. Définie dans stack.cpp.
* vaut 8 par défaut.
*/
extern const size_t STACK_INITIAL_SIZE;


/**
* créé une pile vide de taille size.
* size: la taille de la pile à créer.
* return: une pile vide de taille size.
* throws: range_error: si la taille donnée est nulle.
*/
stack createEmptyStack(const size_t& size);

/**
* vérifie si la pile donnée est vide.
* s: la pile à vérifier.
* return: true si la pile est vide, false sinon.
*/
bool empty(const stack& s);

/**
* Insère la valeur val au sommet de la pile. La pile est agrandie si nécessaire.
* s: La pile dans laquelle insérer la valeur.
* val: la valeur à insérer.
*/
void push(stack& s,const STACK_ITEM_TYPE& val);

/**
* Extrait la valeur au sommet de la pile. Renvoie une range_error si la pile est vide.
* s: La pile de laquelle on extrait la valeur.
* return: la valeur au sommet de la pile, si la pile est non vide.
*/
STACK_ITEM_TYPE pop(stack& s);

/**
* Redimensionne le tableau de valeurs de la pile s à la taille newSize.
* s: La pile dont le tableau de valeur doit être redimensionné.
* newSize: La taille du nouveau tableau.
*/
void resize(stack& s, const size_t& newSize);

//header guard
#endif 