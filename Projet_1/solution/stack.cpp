#include <stdexcept>
#include "stack.h"

using namespace std;

const size_t STACK_INITIAL_SIZE = 8;

std::ostream& operator<< (std::ostream& os, const stack_item& si) {
	os << "(" << si.col << ":" << si.height << ")";
	return os;
}

// créé une pile vide de taille size.
stack createEmptyStack(const size_t& size) {
	stack s;
	s.size = size;
	s.top = 0;
	s.data = new stack_item[size];

	return s;
}

// vérifie si la pile donnée est vide.
bool empty(const stack& s) {
	return (s.top == 0);
}

// Insère la valeur val au sommet de la pile. La pile est agrandie si nécessaire.
void push(stack& s,const stack_item& val) {
	//on double la taille si la pile est pleine.
	if(s.top == s.size) {
		resize(s, s.size * 2);
	}
	s.data[s.top] = val;
	s.top++;
}

// Extrait la valeur au sommet de la pile. Renvoie une range_error si la pile est vide.
void pop(stack& s, stack_item& si) {
	if(empty(s)) {
		throw new range_error("impossible de pop depuis une stack vide");
	}
	si = s.data[--s.top];
	//on resize la pile si le nombre d'éléments est inférieur au tiers de la capacité.
	if(s.top < (s.size / 3)) {
		resize(s, s.size / 2);
	}
}

// Redimensionne le tableau de valeurs de la pile s à la taille newSize.
void resize(stack& s, const size_t& newSize) {
	int length = (newSize > s.size) ? s.size : newSize;
	stack_item * tmp = new stack_item[newSize];
	for(int i = 0; i < length; i++) {
		tmp[i] = s.data[i];
	}
	delete[] s.data;
	s.data = tmp;
	s.size = newSize;
}