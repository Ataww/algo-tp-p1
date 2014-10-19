#include <iostream>
#include <string>
#include <stdlib.h> 
#include <fstream>
#include <chrono>
#include <ctime>
using namespace std;
#include "../read/read.h"
#include "../solution/common.h"
#include "../solution/solution_1.h"
#include "../solution/solution_2.h"
#include "../solution/solution_3.h"

const int NB_LOOP = 100;
const string TEST = "test_generator.txt";
const string PERFORM_1 = "performance_1.txt";
const string PERFORM_2 = "performance_2.txt";
const string PERFORM_3 = "performance_3.txt";
const string PERFORM_4 = "performance_4.txt";

/**
* Programme de test de performance
* On récupère pour chaque solution le temps d'exécution dans un fichier
* Le but étant à la fin de faire un graphique pour comparer les performances.
**/
int main(int argc, char* argv[]){

	srand(time(NULL));
	int pourcentage = 1;

	//Fichier d'écriture
	ofstream f1, f2, f3;
	f1.open(PERFORM_1);
	f2.open(PERFORM_2);
	f3.open(PERFORM_3);

	for(int i = 0; i < NB_LOOP; i++){

		//Information sur l'avancée
		cout << i+1 << " of " << NB_LOOP << endl;

		//Variable liée à la dalle
		dalle dalle;
		point coord = {.x = 0, .y = 0};
		rect rect = {.width = 0, .height = 0};

		//Variable de chronomètre
		chrono::time_point<std::chrono::system_clock> start1, start2, start3, end1, end2, end3;

		//Création du fichier test
		string command = "./exe/generator.exe " + to_string(100) + " " + to_string(pourcentage); 
		system(command.c_str());
		pourcentage++;

		//Création de la dalle
		try{
			dalle.data = createDalle( dalle.dim.width, dalle.dim.height, TEST);
		}
		catch(range_error& e){
			cout << e.what() << endl;
			return -1;
		}

		//Appel des différents algorithme sur le même exemple
		start1 = chrono::system_clock::now();
		bool result1 = solution_1(dalle, rect, coord);
		end1 = chrono::system_clock::now();

		start2 = chrono::system_clock::now();
		bool result2 = solution2(dalle, rect, coord);
		end2= chrono::system_clock::now();

		start3 = chrono::system_clock::now();
		bool result3 = solution3(dalle, rect, coord);
		end3 = chrono::system_clock::now();

		//Calcul du temps d'excution
		chrono::duration<double, micro> elapsed1 = end1-start1;
		chrono::duration<double, micro> elapsed2 = end2-start2;
		chrono::duration<double, micro> elapsed3 = end3-start3;

		//Ecriture
		if(result1)
			f1 << elapsed1.count() << '\n';
		if(result2)
			f2 << elapsed2.count() << '\n';
		if(result3)
			f3 << elapsed3.count() << '\n';
	}

	f1.close();
	f2.close();
	f3.close();

	return 0;
}