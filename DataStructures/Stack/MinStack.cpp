#include <iostream>
#include <limits>

#include "MinStack.h"

MinStack::MinStack(int capacity) : capacity(capacity)
{
    data = new int[capacity];
    minstk = new Stack(capacity);   //optimize by using half stack
    minstk->push(INT32_MAX);
}

MinStack::~MinStack()
{
    delete minstk;
    delete[] data;
}

void MinStack::push(int x)
{
    if (!isFull()) {
        data[top++] = x;
        if(minstk->peek() >= x)
            minstk->push(x);
    }
}

int MinStack::pop()
{
    if (!isEmpty()) {
        if(data[top - 1] == minstk->peek())
            minstk->pop();
        return data[--top];
    }
    return -1;
}

int MinStack::peek()
{
    if (!isEmpty()) {
        return data[top - 1];
    }
    return -1;
}

int MinStack::min()
{
    return minstk->peek();
}

bool MinStack::isEmpty()
{
    return top == 0;
}

bool MinStack::isFull()
{
    return top == capacity;
}