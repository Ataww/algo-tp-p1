CX = g++
CFLAGS = -Wall
READ_DIR = read/
SOLUTION_DIR = solution/
TEST_DIR = test/
EXE_DIR = exe/
EXEC = solution_1

#Cible pour une compilation total du projet
all: $(EXEC)

#Cible TEST fonction de lecture de fichier
test_read: read.o test_read.o
	$(CX) $(CFLAGS) -o test_read.exe test_read.o read.o
	mv test_read.exe exe/

test_read.o: $(TEST_DIR)test_read.cpp $(READ_DIR)read.h
	$(CX) $(CFLAGS) -c $(TEST_DIR)test_read.cpp

#Cible pour la solution 1
solution_1: read.o solution_1.o
	$(CX) $(CFLAGS) -o solution_1.exe read.o solution_1.o
	mv solution_1.exe exe/

read.o: $(READ_DIR)read.cpp
	$(CX) $(FLAGS) -c $(READ_DIR)read.cpp

solution_1.o: $(SOLUTION_DIR)solution_1.cpp $(READ_DIR)read.h
	$(CX) $(CFLAGS) -c $(SOLUTION_DIR)solution_1.cpp

#Cible de nettoyage
clean:
	rm -rf *.o

mrpropre: clean
	rm exe/*