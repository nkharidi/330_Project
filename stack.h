#ifndef STACK_H
#define STACK_H

#include "node.h"
#include <iostream>

class stack
{
public:
    stack();

    void Push(int data);
    Node* Pop();
    void printStack();

    Node* peek();
private:
    Node *head_;


};

#endif // STACK_H






