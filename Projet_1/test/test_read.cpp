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

	//Test nombre de colonne
	try{
		dalle = createDalle( width, height, "file_test/test_read_3.txt");
	}
	catch(range_error& e){
		cout << e.what() << endl;
	}

	//Test nombre de ligne
	try{
		dalle = createDalle( width, height, "file_test/test_read_4.txt");
	}
	catch(range_error& e){
		cout << e.what() << endl;
	}

	return 0;
}