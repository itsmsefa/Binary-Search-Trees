#ifndef STACK_HPP
#define STACK_HPP

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack();
    ~Stack();
    void push(int value);
    int pop();
    bool isEmpty() const;
};

#endif
