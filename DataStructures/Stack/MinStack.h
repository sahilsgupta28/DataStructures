#pragma once
#include "stack.h"

class MinStack {
    int *data;
    int top;
    int capacity;
    Stack* minstk;

    public:
    MinStack(int capacity);
    ~MinStack();
    void push(int x);
    int pop();
    int peek();
    int min();
    bool isEmpty();
    bool isFull();
};