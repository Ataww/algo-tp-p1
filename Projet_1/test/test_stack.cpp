#include <iostream>
#include <stdexcept>
#include "../solution/stack.h"

using namespace std;

#define TOPANDSIZE(x, y)  cout << "top=" << x << "size=" << y << endl;


int main(int argc, char* argv[]) {

	const string ERREUR_INIT("ERREUR lors de l'initialisation de la stack: ");

	const size_t initialSize = 8;

	cout << "debut test stack ===========" << endl;
	cout << "debut init =================" << endl;
	// on teste l'initialisation
	stack s = createEmptyStack(initialSize);
	
	if(s.data == NULL) {
		cout << ERREUR_INIT << "data NULL" << endl;
		goto fin;
	} else if(s.top != 0) {
		cout << ERREUR_INIT << "top différent de 0" << endl;
		goto fin;
	} else if(s.size != initialSize) {
		cout << ERREUR_INIT << "size différente de la valeur attendue." << endl;
		goto fin;
	}
	TOPANDSIZE(s.top, s.size)

	cout << "fin init ===================" << endl;
	cout << "debut push =================" << endl;
	cout << "insertion de " << initialSize << " valeurs" << endl;
	//test push
	for(int i = 0; i < initialSize; i++) {
		bool val = ((i%2) == 0);
		cout << " " << val;
		push(s, val);
	}
	cout << endl;
	TOPANDSIZE(s.top, s.size)
	//test resize en plus grand
	push(s, false);
	TOPANDSIZE(s.top, s.size)
	if(!s.size > initialSize) {
		cout << "Resize (+) ne marche pas";
		goto fin;
	}
	cout << "fin push ===================" << endl;
	cout << "début pop ==================" << endl;
	// test pop et resize en plus petit
	for(int i = 0; i < initialSize - 3; i++) {	
		try {
			bool val;
			val = pop(s); 
			cout << " " << val;
		} catch(range_error& e) {
			cout << e.what() << endl;
			goto fin;
		}
	}
	cout << endl;
	TOPANDSIZE(s.top, s.size)
	cout << "pop jusqu'à stack vide: " << endl;
	//on test le catch d'exception
	for(int i = s.top; i <= 0; i--) {
		try {
			bool val;
			val = pop(s); 
			cout << " " << val;
		} catch(range_error& e) {
			cout << e.what() << endl;
			break;
		}
	}
	cout << "fin pop ====================" << endl;
	cout << "fin test stack =============" << endl;

	fin:
	delete[] s.data;
	return 0;
}