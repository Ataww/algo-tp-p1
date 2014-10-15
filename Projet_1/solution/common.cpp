#include <iostream>
using namespace std;
#include "common.h"

bool operator< (const rect& l, const rect& r) { 
	return (l.width * l.height < r.width * r.height);
};

bool operator> (const rect& l, const rect& r) {
	return (l.width * l.height > r.width * r.height);
}

bool operator== (const rect& l, const rect& r) {
	return (!(l < r) && !(l > r));
}

bool operator<= (const rect& l, const rect& r) {
	return ((l < r) || (l == r));
}

bool operator>= (const rect& l, const rect& r) {
	return ((l > r) || (l == r));
}

// rectangle output
ostream& operator<< (ostream& os, const rect& r) {
	os << "(" << r.width << "," << r.height << ")";
	return os;
}

// point output
ostream& operator<< (ostream& os, const point& p) {
	os << "(" << p.x << "," << p.y << ")";
	return os;
}

void checkDalle(const dalle& dalle, bool& white, bool& black, bool display) {
	white = black = false;
	for(int i = 0; i < dalle.dim.height; i++) {
		for(int j = 0; j < dalle.dim.width; j++) {
			if(dalle.data[i*dalle.dim.width+j]) {
				//case blanche
				white = true;
				if (display) {
					cout << '0';
				}
			} else {
				//case noire
				black = true;
				if(display) {
					cout << '1';
				}
			}
		}
		cout << endl;
	}
}