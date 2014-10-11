#ifndef COMMON_H
#define COMMON_H

/**
* Structure représentant les dimensions d'un rectangle.
* width : la largeur du rectangle.
* height : la hauteur du rectangle.
*/
typedef struct rect {
	int width;
	int height;

	//assignement
	rect& operator=(const rect& n) {
		width = n.width;
		height = n.height;
		return *this;
	}
} rect;

// Les opérateurs suivant comparent les aires des rectangles données.
bool operator< (const rect& l, const rect& r);

bool operator> (const rect& l, const rect& r);

bool operator== (const rect& l, const rect& r);

bool operator<= (const rect& l, const rect& r);

bool operator>= (const rect& l, const rect& r);

/**
* Structure représentant les coordonnées d'un point (une case dans notre cas).
* x : coordonnée en abscisse.
* y : coordonnée en ordonnée.
*/
typedef struct point {
	int x;
	int y;

	//assignement
	point& operator=(const point& n) {
		x = n.x;
		y = n.y;
		return *this;
	}
} point;

/**
* Structure représentant le dallage.
* dim : représente les dimensions de la dalle.
* data : contient la dalle (tableau de bool).
*/
typedef struct dalle {
	rect dim;
	bool * data;
} dalle;

/*
* Parcourt la dalle pour vérifier qu'elle contient des cases blanches et noires.
* dalle : la dalle à parcourir. Ne doit pas être vide.
* display : true si la dalle doit être affichée, false sinon.
* white : booléen utilisé pour indiquer si il existe des cases blanches.
* black : booléen utilisé pour indiquer si il existe des cases noires.
*/
void checkDalle(const dalle& dalle, bool& white, bool& black, bool display);

#endif