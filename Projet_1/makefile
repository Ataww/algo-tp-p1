CX = g++
CFLAGS = -Wall
READ_DIR = read/
SOLUTION_DIR = solution/
TEST_DIR = test/
EXE_DIR = exe/
EXEC = solution_1 solution_2 solution_3 solution_4 test_read test_generator test_solution_1 test_solution_2 test_solution_3 test_solution_4 test_performance

#Cible pour une compilation total du projet
all: $(EXEC)

#Cible TEST fonction de lecture de fichier
test_read: read.o test_read.o
	$(CX) $(CFLAGS) -o test_read.exe test_read.o read.o
	mv test_read.exe $(EXE_DIR)

test_read.o: $(TEST_DIR)test_read.cpp $(READ_DIR)read.h
	$(CX) $(CFLAGS) -c $(TEST_DIR)test_read.cpp

#cible TEST pour la stack
test_stack: stack.o test_stack.o common.o
	$(CX) $(CFLAGS) -o test_stack.exe test_stack.o stack.o common.o
	mv test_stack.exe $(EXE_DIR)

test_stack.o: $(TEST_DIR)test_stack.cpp $(SOLUTION_DIR)stack.h $(SOLUTION_DIR)common.h
	$(CX) $(CFLAGS) -c $(TEST_DIR)test_stack.cpp

#cible TEST pour le générateur de fichier test
test_generator: generator test_generator.o  common.o read.o
	$(CX) $(CFLAGS) -o test_generator.exe test_generator.o read.o common.o
	mv test_generator.exe $(EXE_DIR)

test_generator.o: $(TEST_DIR)test_generator.cpp $(READ_DIR)read.h $(SOLUTION_DIR)common.h
	$(CX) $(CFLAGS) -c $(TEST_DIR)test_generator.cpp

#cible TEST pour la solution 1
test_solution_1: solution_1.o test_solution_1.o  common.o read.o
	$(CX) $(CFLAGS) -o test_solution_1.exe test_solution_1.o solution_1.o read.o common.o
	mv test_solution_1.exe $(EXE_DIR)

test_solution_1.o: $(TEST_DIR)test_solution_1.cpp $(READ_DIR)read.h $(SOLUTION_DIR)common.h $(SOLUTION_DIR)solution_1.h
	$(CX) $(CFLAGS) -c $(TEST_DIR)test_solution_1.cpp

#cible TEST pour la solution 2
test_solution_2: solution_2.o test_solution_2.o  common.o read.o
	$(CX) $(CFLAGS) -o test_solution_2.exe test_solution_2.o solution_2.o read.o common.o
	mv test_solution_2.exe $(EXE_DIR)

test_solution_2.o: $(TEST_DIR)test_solution_2.cpp $(READ_DIR)read.h $(SOLUTION_DIR)common.h $(SOLUTION_DIR)solution_2.h
	$(CX) $(CFLAGS) -c $(TEST_DIR)test_solution_2.cpp

#cible TEST pour la solution 3
test_solution_3: solution_3.o test_solution_3.o  common.o read.o
	$(CX) $(CFLAGS) -o test_solution_3.exe test_solution_3.o solution_3.o read.o common.o
	mv test_solution_3.exe $(EXE_DIR)

test_solution_3.o: $(TEST_DIR)test_solution_3.cpp $(READ_DIR)read.h $(SOLUTION_DIR)common.h $(SOLUTION_DIR)solution_3.h
	$(CX) $(CFLAGS) -c $(TEST_DIR)test_solution_3.cpp

#cible TEST pour la solution 4
test_solution_4: solution_4.o solution_3.o stack.o test_solution_4.o  common.o read.o
	$(CX) $(CFLAGS) -o test_solution_4.exe test_solution_4.o solution_4.o solution_3.o stack.o read.o common.o
	mv test_solution_4.exe $(EXE_DIR)

test_solution_4.o: $(TEST_DIR)test_solution_4.cpp $(READ_DIR)read.h $(SOLUTION_DIR)common.h $(SOLUTION_DIR)solution_4.h
	$(CX) $(CFLAGS) -c $(TEST_DIR)test_solution_4.cpp

#cible TEST pour le test de performance
test_performance: generator read.o common.o test_performance.o solution_1.o solution_2.o solution_3.o solution_4.o stack.o
	$(CX) $(CFLAGS) -o test_performance.exe test_performance.o solution_1.o solution_2.o solution_3.o solution_4.o stack.o read.o common.o
	mv test_performance.exe $(EXE_DIR)

test_performance.o: $(TEST_DIR)test_performance.cpp $(READ_DIR)read.h $(SOLUTION_DIR)common.h $(SOLUTION_DIR)solution_1.h $(SOLUTION_DIR)solution_2.h $(SOLUTION_DIR)solution_3.h $(SOLUTION_DIR)solution_4.h
	$(CX) $(CFLAGS) -c $(TEST_DIR)test_performance.cpp

#Cible pour la solution 1
solution_1: read.o common.o solution_1.o main_solution_1.o
	$(CX) $(CFLAGS) -o solution_1.exe read.o common.o solution_1.o main_solution_1.o
	mv solution_1.exe $(EXE_DIR)

#Cible pour la solution 2
solution_2: read.o common.o solution_2.o main_solution_2.o
	$(CX) $(CFLAGS) -o solution_2.exe read.o common.o solution_2.o main_solution_2.o
	mv solution_2.exe $(EXE_DIR)

#Cible pour la solution 3
solution_3: read.o common.o solution_3.o main_solution_3.o
	$(CX) $(CFLAGS) -o solution_3.exe read.o common.o solution_3.o main_solution_3.o
	mv solution_3.exe $(EXE_DIR)

#Cible pour la solution 4
solution_4: read.o common.o stack.o solution_4.o main_solution_4.o solution_3.o
	$(CX) $(CFLAGS) -o solution_4.exe read.o common.o stack.o solution_4.o main_solution_4.o solution_3.o
	mv solution_4.exe $(EXE_DIR)

#Cible pour le générateur de test
generator: generator.o
	$(CX) $(CFLAGS) -o generator.exe generator.o
	mv generator.exe $(EXE_DIR)

#utility objects
read.o: $(READ_DIR)read.cpp
	$(CX) $(CFLAGS) -c $(READ_DIR)read.cpp

common.o: $(SOLUTION_DIR)common.cpp
	$(CX) $(CFLAGS) -c $(SOLUTION_DIR)common.cpp

stack.o: $(SOLUTION_DIR)stack.cpp
	$(CX) $(CFLAGS) -c $(SOLUTION_DIR)stack.cpp

generator.o: $(SOLUTION_DIR)generator.cpp
	$(CX) $(CFLAGS) -c $(SOLUTION_DIR)generator.cpp

#solution objects
solution_1.o: $(SOLUTION_DIR)solution_1.cpp $(SOLUTION_DIR)common.h $(READ_DIR)read.h
	$(CX) $(CFLAGS) -c $(SOLUTION_DIR)solution_1.cpp

solution_2.o: $(SOLUTION_DIR)solution_2.cpp $(SOLUTION_DIR)common.h $(READ_DIR)read.h
	$(CX) $(CFLAGS) -c $(SOLUTION_DIR)solution_2.cpp

solution_3.o: $(SOLUTION_DIR)solution_3.cpp $(SOLUTION_DIR)common.h $(READ_DIR)read.h
	$(CX) $(CFLAGS) -c $(SOLUTION_DIR)solution_3.cpp

solution_4.o: $(SOLUTION_DIR)solution_4.cpp $(SOLUTION_DIR)common.h $(READ_DIR)read.h $(SOLUTION_DIR)stack.h $(SOLUTION_DIR)solution_3.h
	$(CX) $(CFLAGS) -c $(SOLUTION_DIR)solution_4.cpp

#main objects
main_solution_2.o: $(SOLUTION_DIR)main_solution_2.cpp $(SOLUTION_DIR)solution_2.h $(SOLUTION_DIR)common.h $(READ_DIR)read.h
	$(CX) $(CFLAGS) -c $(SOLUTION_DIR)main_solution_2.cpp

main_solution_1.o: $(SOLUTION_DIR)main_solution_1.cpp $(SOLUTION_DIR)solution_1.h $(SOLUTION_DIR)common.h $(READ_DIR)read.h
	$(CX) $(CFLAGS) -c $(SOLUTION_DIR)main_solution_1.cpp

main_solution_3.o: $(SOLUTION_DIR)main_solution_3.cpp $(SOLUTION_DIR)solution_3.h $(SOLUTION_DIR)common.h $(READ_DIR)read.h
	$(CX) $(CFLAGS) -c $(SOLUTION_DIR)main_solution_3.cpp

main_solution_4.o: $(SOLUTION_DIR)main_solution_4.cpp $(SOLUTION_DIR)solution_4.h $(SOLUTION_DIR)common.h $(READ_DIR)read.h
	$(CX) $(CFLAGS) -c $(SOLUTION_DIR)main_solution_4.cpp
#Cible de nettoyage
clean:
	rm -rf *.o
	rm -rf *.txt

mrpropre: clean
	rm -rf ./exe/*
