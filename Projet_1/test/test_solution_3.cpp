#include <iostream>
#include <string>
#include <stdlib.h> 
using namespace std;
#include "../read/read.h"
#include "../solution/common.h"
#include "../solution/solution_3.h"

const int NB_TEST = 10;
const string PATH = "file_test/test_";
const string GOOD = "[OK]";
const string BAD  = "[ERROR]";
const int expect[9][4] ={ {0, 0, 22, 10}, {3, 1, 9, 4}, {2, 1, 8, 3},
					  {6, 1, 11, 7}, {3, 0, 2, 19}, {18, 0, 2, 18},
					  {18, 0, 2, 18}, {18, 0, 2, 18}, {8, 8, 7, 1}
					};

const 

/**
* Fonction qui vérifie si le résultat retourné et bien celui qui est attendu
* Paramètres:
*   - rect : rectangle retourné
*   - coord: coordonnées de rectangle retourné
*   - i : numéro du test
* Retour:
*   true si le rectangle est conforme sinon false
**/
bool assert(const rect& rect, const point& coord, const int i){

	return coord.x == expect[i-1][0]    &&
		   coord.y == expect[i-1][1]    &&
		   rect.width == expect[i-1][2] &&
		   rect.height == expect[i-1][3];
}

/**
* Programme de test de la solution 1 avec tout les fichiers test mis en plac
* Affiche à l'écran:
*   - le test en cours
*   - le résulat du test
*   - les valeurs attendu et les valeurs retournés
**/
int main(int argc, char* argv[]){

	int fail = 0;

	for(int i = 0; i < NB_TEST; i++){

		string file = PATH + to_string(i+1) + ".txt";

		//Variable liée à la dalle
		dalle dalle;

		//Variable liée au plus grand rectangle
		point coord = {.x = 0, .y = 0};
		rect rect = {.width = 0, .height = 0};

		//Création de la dalle
		try{
			dalle.data = createDalle( dalle.dim.width, dalle.dim.height, file);
		}
		catch(range_error& e){
			cout << e.what() << endl;
			return -1;
		}

		//Appel algorithme solution 1
		bool result = solution3(dalle, rect, coord);

		if(!result && i == 0){
			//Si la dalle est noir
			cout << GOOD << "Test " << i+1 << " on file => " << file << endl;
		}
		else{
			if(!assert(rect, coord, i)){
				cout << BAD << "Test " << i+1 << " on file => " << file << endl;
				cout << "      expect : " << expect[i-1][0] << " / " << expect[i-1][1]
				     << " / " << expect[i-1][2] << " / " << expect[i-1][3] << endl;
				cout << "      result : " << coord.x << " / " << coord.y
				     << " / " << rect.width << " / " << rect.height << endl;
				fail ++;
			}
			else
				cout << GOOD << "Test " << i+1 << " on file => " << file << endl;
		}
	}

	cout << " ==> " << fail << " erreurs repérées." << endl;

	return 0;
}