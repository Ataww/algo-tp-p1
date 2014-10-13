#include <stdexcept>
#include "stack.h"

using namespace std;

stack createEmptyStack(const size_t& size) {
	stack s;
	s.size = size;
	s.top = 0;
	s.data = new bool[size];

	return s;
}

bool empty(const stack& s) {
	return (s.top == 0);
}

void push(stack& s,const bool& val) {
	//on double la taille si la pile est pleine.
	if(s.top == s.size) {
		resize(s, s.size * 2);
	}
	s.data[s.top] = val;
	s.top++;
}

bool pop(stack& s) {
	if(empty(s)) {
		throw new range_error("impossible de pop depuis une stack vide");
	}
	bool val = s.data[s.top--];
	//on resize la pile si le nombre d'éléments est inférieur au tiers de la capacité.
	if(s.top <= (s.size / 3)) {
		resize(s, s.size / 2);
	}
	return val;
}

void resize(stack& s, const size_t& newSize) {
	int length = (newSize > s.size) ? s.size : newSize;
	bool * tmp = new bool[newSize];
	for(int i = 0; i < length; i++) {
		tmp[i] = s.data[i];
	}
	s.data = tmp;
	s.size = newSize;
}