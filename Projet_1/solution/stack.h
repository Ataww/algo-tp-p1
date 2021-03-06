#ifndef STACK_H
#define STACK_H

#include <iostream>

#include "common.h"

/**
* Structure représentant un élément d'une stack.
* rect: les dimensions du rectangle.
* coord: les coordonnées du point inférieur gauche du rectangle.
*/
typedef struct stack_item {
	int col;
	int height;

	stack_item& operator=(const stack_item& s) {
		col = s.col;
		height = s.height;
		return *this;
	}
} stack_item;

std::ostream& operator<< (std::ostream& os, const stack_item& si);

/**
* structure représentant une pile de rectangles.
* top: indice de la valeur au sommet.
* size: taille de la pile.
* data: tableau contenant les valeurs contenues par la pile.
*/
typedef struct stack {
	unsigned int top;
	size_t size;
	stack_item* data;
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
void push(stack& s,const stack_item& val);

/**
* Extrait la valeur au sommet de la pile. Renvoie une range_error si la pile est vide.
* s: La pile de laquelle on extrait la valeur.
* return: la valeur au sommet de la pile, si la pile est non vide.
*/
void pop(stack& s, stack_item& si);

/**
* Redimensionne le tableau de valeurs de la pile s à la taille newSize.
* s: La pile dont le tableau de valeur doit être redimensionné.
* newSize: La taille du nouveau tableau.
*/
void resize(stack& s, const size_t& newSize);

//header guard
#endif 