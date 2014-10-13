#ifndef STACK_H
#define STACK_H

/**
* structure représentant une pile.
* top: indice de la valeur au sommet.
* size: taille de la pile.
* data: tableau contenant les valeurs contenues par la pile.
*/
typedef struct stack {
	unsigned int top;
	size_t size;
	bool* data;
}stack;

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
void push(stack& s,const bool& val);

/**
* Extrait la valeur au sommet de la pile. Renvoie une range_error si la pile est vide.
* s: La pile de laquelle on extrait la valeur.
* return: la valeur au sommet de la pile, si la pile est non vide.
*/
bool pop(stack& s);

/**
* Redimensionne le tableau de valeurs de la pile s à la taille newSize.
* s: La pile dont le tableau de valeur doit être redimensionné.
* newSize: La taille du nouveau tableau.
*/
void resize(stack& s, const size_t& newSize);

#endif