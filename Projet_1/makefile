CX = g++
CFLAGS = -Wall
READ_DIR = read/
SOLUTION_DIR = solution/
TEST_DIR = test/
EXE_DIR = exe/
EXEC = solution_1 solution_2 solution_3

#Cible pour une compilation total du projet
all: $(EXEC)

#Cible TEST fonction de lecture de fichier
test_read: read.o test_read.o
	$(CX) $(CFLAGS) -o test_read.exe test_read.o read.o
	mv test_read.exe $(EXE_DIR)

test_read.o: $(TEST_DIR)test_read.cpp $(READ_DIR)read.h
	$(CX) $(CFLAGS) -c $(TEST_DIR)test_read.cpp

#cible TEST pour la stack
test_stack: stack.o test_stack.o
	$(CX) $(CFLAGS) -o test_stack.exe test_stack.o stack.o
	mv test_stack.exe $(EXE_DIR)

test_stack.o: $(TEST_DIR)test_stack.cpp $(SOLUTION_DIR)stack.h
	$(CX) $(CFLAGS) -c $(TEST_DIR)test_stack.cpp

#Cible pour la solution 1
solution_1: read.o common.o solution_1.o
	$(CX) $(CFLAGS) -o solution_1.exe read.o common.o solution_1.o
	mv solution_1.exe $(EXE_DIR)

#Cible pour la solution 2
solution_2: read.o common.o solution_2.o
	$(CX) $(CFLAGS) -o solution_2.exe read.o common.o solution_2.o
	mv solution_2.exe $(EXE_DIR)

#Cible pour la solution 3
solution_3: read.o common.o solution_3.o
	$(CX) $(CFLAGS) -o solution_3.exe read.o common.o solution_3.o
	mv solution_3.exe $(EXE_DIR)

#Cible pour la solution 4
solution_4: read.o common.o stack.o solution_4.o
	$(CX) $(CFLAGS) -o solution_4.exe read.o common.o stack.o solution_4.o
	mv solution_4.exe $(EXE_DIR)

#utility objects
read.o: $(READ_DIR)read.cpp
	$(CX) $(CFLAGS) -c $(READ_DIR)read.cpp

common.o: $(SOLUTION_DIR)common.cpp
	$(CX) $(CFLAGS) -c $(SOLUTION_DIR)common.cpp

stack.o: $(SOLUTION_DIR)stack.cpp
	$(CX) $(CFLAGS) -c $(SOLUTION_DIR)stack.cpp

#solution objects
solution_1.o: $(SOLUTION_DIR)solution_1.cpp $(READ_DIR)read.h
	$(CX) $(CFLAGS) -c $(SOLUTION_DIR)solution_1.cpp

solution_2.o: $(SOLUTION_DIR)solution_2.cpp $(SOLUTION_DIR)common.h $(READ_DIR)read.h
	$(CX) $(CFLAGS) -c $(SOLUTION_DIR)solution_2.cpp

solution_3.o: $(SOLUTION_DIR)solution_3.cpp $(SOLUTION_DIR)common.h $(READ_DIR)read.h
	$(CX) $(CFLAGS) -c $(SOLUTION_DIR)solution_3.cpp

solution_4.o: $(SOLUTION_DIR)solution_4.cpp $(SOLUTION_DIR)common.h $(READ_DIR)read.h $(SOLUTION_DIR)stack.h
	$(CX) $(CFLAGS) -c $(SOLUTION_DIR)solution_4.cpp

#Cible de nettoyage
clean:
	rm -rf *.o
	
mrpropre: clean
	rm -rf ./exe/*
