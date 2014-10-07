#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
#include "read.h"

//Définition de createDalle
bool*	createDalle(int& w, int& h, string fileName){

	const string ERREUR_ENTETE ("ERREUR: Entete fichier incorrecte");
	const string ERREUR_VIDE   ("ERREUR: Le fichier est vide");
	const string ERREUR_COLONNE("ERREUR: Une ligne ne contient pas le bon nombre de colonne");
	const string ERREUR_LIGNE  ("ERREUR: Le fichier ne contient pas le bon nombre de ligne");

	ifstream f(fileName);
	string line;
	int nbEntete = 0;
	bool* t= NULL;

	//On prend la première ligne
	getline(f, line);
	if(line.empty())
		throw range_error(ERREUR_VIDE);

	//Test si la première ligne contient bien la largeur et la longueur
	char cstr[line.length()+1];
	strcpy(cstr, line.c_str());
	char* p = strtok(cstr, " ");
	while(p!= 0){
		nbEntete++;
		p = strtok(NULL, " ");
	}
	if(nbEntete != 2)
		throw range_error(ERREUR_ENTETE);

	//On récupère la largeur et la hauteur
	strcpy(cstr, line.c_str());
	p = strtok(cstr, " ");
	h = atoi(p);
	p = strtok(NULL, " ");
	w = atoi(p);

	//Création de la dalle
	t = new bool[w*h];
	int i = 0;

	while (!f.eof()){
		getline(f, line);
		//Test nombre de colonnes
		if(line.length() != w)
			throw range_error(ERREUR_COLONNE);
		char _line[w];
		strcpy(_line, line.c_str());
		for (int j = 0; j < w; j++){
			t[i*w+j] = (_line[j] == '0');}
		i++;
	}

	//On ferme le fichier + désalocation
	f.close();

	//Test nombre de lignes
	if(i != h)
		throw range_error(ERREUR_LIGNE);

	return t;
}