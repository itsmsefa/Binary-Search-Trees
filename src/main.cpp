#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // For sleep function
#include "StackOperations.hpp"
#include "BinarySearchTree.hpp"

using namespace std;

int main() {
    BinaryTree binaryTree;
    binaryTree.processFile("Sayilar.txt");

    cout << "Postorder traversal: ";
    binaryTree.postorderPrint();
    cout << endl;

    cout << "ASCII values: ";
    binaryTree.printAsciiValues();
    cout << endl;

    return 0;
}
