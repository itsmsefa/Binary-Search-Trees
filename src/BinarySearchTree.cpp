#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // For sleep function
#include "StackOperations.hpp"
#include "BinarySearchTree.hpp"

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:

    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            // Handle underflow
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

};



struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

class BinaryTree {

private:
    TreeNode* root;

public:

    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        // Implement destructor to release allocated memory
    }

    void insert(int value) {
        if (!root) {
            root = new TreeNode;
            root->data = value;
            root->left = nullptr;
            root->right = nullptr;
            return;
        }

        // Implement insertion into binary tree
    }

    void postorderPrint() {
        postorderPrint(root);
        cout << endl;
    }

    void postorderPrint(TreeNode* node) {
        if (node) {
            postorderPrint(node->left);
            postorderPrint(node->right);
            cout << node->data << " ";
        }
    }

    void printAsciiValues() {
        printAsciiValues(root);
        cout << endl;
    }

    void printAsciiValues(TreeNode* node) {
        if (node) {
            printAsciiValues(node->left);
            printAsciiValues(node->right);

            int sum = 0;
            int value = node->data;

            while (value > 0) {
                sum += value % 10;
                value /= 10;
            }

            cout << static_cast<char>(sum); // Convert sum to ASCII character
        }
    }

    void processLine(Stack& lineStack) {
        Stack tempStack;
        int value;

        while (!lineStack.isEmpty()) {
            value = lineStack.pop();

            if (value % 2 == 0) {
                BinaryTree* newTree = new BinaryTree; // Create a dynamic object
                newTree->insert(value);
                tempStack.push(reinterpret_cast<int>(newTree));
            }
            else {
                if (tempStack.isEmpty()) {
                    cerr << "Error: No tree available for odd value" << endl;
                    return;
                }
                BinaryTree* currentTree = reinterpret_cast<BinaryTree*>(tempStack.pop());
                currentTree->insert(value);
                tempStack.push(reinterpret_cast<int>(currentTree));
            }
        }

        while (!tempStack.isEmpty()) {
            lineStack.push(tempStack.pop());
        }
    }

    void processFile(const string& filename) {
        ifstream inputFile(filename);
        if (!inputFile) {
            cerr << "Error: Could not open file " << filename << endl;
            return;
        }

        string line;
        Stack lineStack;

        while (getline(inputFile, line)) {
            istringstream iss(line);
            int value;
            while (iss >> value) {
                lineStack.push(value);
            }
            processLine(lineStack);
        }

        inputFile.close();
    }
};