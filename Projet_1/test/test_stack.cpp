#include <iostream>
#include <stdexcept>
#include "../solution/stack.h"

using namespace std;

#define TOPANDSIZE(x, y)  cout << "top=" << x << "size=" << y << endl;


int main(int argc, char* argv[]) {

	const string ERREUR_INIT("ERREUR lors de l'initialisation de la stack: ");

	cout << "debut test stack ===========" << endl;
	cout << "debut init =================" << endl;
	// on teste l'initialisation
	stack s = createEmptyStack(STACK_INITIAL_SIZE);
	
	if(s.data == NULL) {
		cout << ERREUR_INIT << "data NULL" << endl;
		return -1;
	} else if(s.top != 0) {
		cout << ERREUR_INIT << "top différent de 0" << endl;
		goto fin;
	} else if(s.size != STACK_INITIAL_SIZE) {
		cout << ERREUR_INIT << "size différente de la valeur attendue." << endl;
		goto fin;
	}
	TOPANDSIZE(s.top, s.size)
	{
		stack_item val = {.col=1, .height=1};
		cout << "val:" << val << endl;
		val.col = 1;
		val.height = 1;
		cout << "val:" << val << endl;
		push(s, val);
		TOPANDSIZE(s.top, s.size)
		stack_item si = val;
		cout << "val:" << si << endl;
		pop(s, si);
		cout << "val:" << si << endl; 
		TOPANDSIZE(s.top, s.size)
	}
	cout << "fin init ===================" << endl;
	cout << "debut push =================" << endl;
	cout << "insertion de " << STACK_INITIAL_SIZE << " valeurs" << endl;
	//test push
	for(unsigned int i = 0; i < STACK_INITIAL_SIZE; i++) {
		stack_item val = {.col=((i%2) == 0), .height=((i%2) == 0)};
		cout << " " << val;
		push(s, val);
	}
	cout << endl;
	TOPANDSIZE(s.top, s.size)
	//test resize en plus grand
	{
		stack_item val = {.col=1, .height=1};
		cout << val << endl;
		push(s, val);
	}
	TOPANDSIZE(s.top, s.size)
	if(!(s.size > STACK_INITIAL_SIZE)) {
		cout << "Resize (+) ne marche pas";
		goto fin;
	}
	cout << "fin push ===================" << endl;
	cout << "début pop ==================" << endl;
	TOPANDSIZE(s.top, s.size)
	// test pop et resize en plus petit
	for(unsigned int i = 0; i < STACK_INITIAL_SIZE; i++) {	
		try {
			stack_item val;
			pop(s, val); 
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
	for(int i = s.top; i >= 0; i--) {
		try {
			stack_item val;
			pop(s, val);
			cout << " " << val;
		} catch(exception& e) {
			cout << e.what() << endl;
			goto fin;
		}
	}
	TOPANDSIZE(s.top, s.size)
	cout << "fin pop ====================" << endl;
	cout << "fin test stack =============" << endl;

	fin:
	delete[] s.data;
	return 0;
}