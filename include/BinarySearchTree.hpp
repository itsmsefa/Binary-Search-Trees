#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include "StackOperations.hpp"

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree();
    ~BinaryTree();
    void insert(int value);
    void postorderPrint();
    void printAsciiValues();
    void processLine(Stack& lineStack);
    void processFile(const string& filename);
    void postorderPrint(TreeNode* node);
    void printAsciiValues(TreeNode* node);
};

#endif