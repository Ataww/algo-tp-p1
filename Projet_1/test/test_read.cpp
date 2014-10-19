#include <iostream>
#include <stdexcept>
using namespace std;
#include "../read/read.h"

int main (int argc, char* argv[]){

	//Dalle
	bool* dalle = NULL;	
	int width, height;

	//Test fichier vide	
	try{
		dalle = createDalle( width, height, "file_test/test_read_1.txt");
	}
	catch(range_error& e){
		cout << e.what() << endl;
	}

	//Test entete incomplet
	try{
		dalle = createDalle( width, height, "file_test/test_read_2.txt");
	}
	catch(range_error& e){
		cout << e.what() << endl;
	}

	//Test nombre de colonne faux
	try{
		dalle = createDalle( width, height, "file_test/test_read_3.txt");
	}
	catch(range_error& e){
		cout << e.what() << endl;
	}

	//Test nombre de ligne faux
	try{
		dalle = createDalle( width, height, "file_test/test_read_4.txt");
	}
	catch(range_error& e){
		cout << e.what() << endl;
	}

	//Test sur un fichier connu
	try{
		dalle = createDalle( width, height, "file_test/test_1.txt");
	}
	catch(range_error& e){
		cout << e.what() << endl;
	}
	if(width == 22 && height == 10)
		cout << "[OK] La lecture du fichier est correcte" << endl;

	return 0;
}