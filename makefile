all: compile bind launch

compile:

	g++ -I "./include" -c ./src/StackOperations.cpp -o ./lib/StackOperations.o

	g++ -I "./include" -c ./src/BinarySearchTree.cpp -o ./lib/BinarySearchTree.o

	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o

bind:
	g++ ./lib/StackOperations.o ./lib/BinarySearchTree.o ./lib/main.o -o ./bin/program

launch:
	./bin/program.exe