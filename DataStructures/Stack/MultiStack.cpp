#include <iostream>
#include "MultiStack.h"

MultiStack::MultiStack(int StackCount, int Capacity)
{
    this->StackCount = StackCount;
    this->Capacity = Capacity;
    data = new int [StackCount * Capacity];
        
    top = new int [StackCount];
    for(int i = 0; i < StackCount; i++)
        top[i] = stkBase(i);
}

MultiStack::~MultiStack()
{
    delete[] data;
    delete[] top;
}

void MultiStack::push(int StackNo, int x) {
    if(StackNo >= StackCount)
        throw -1;

    if (!isFull(StackNo))
    {
        data[top[StackNo]++] = x;
    }
}
int MultiStack::pop(int stackNo) {
    if (!isEmpty(stackNo)) {
        return data[--top[stackNo]];
    }
    return -1;
}
int MultiStack::peek(int stackNo) {
    if (!isEmpty(stackNo)) {
        return data[top[stackNo] - 1];
    }
    return -1;
}

bool MultiStack::isEmpty(int stackNo) {
    return top[stackNo] == stkBase(stackNo);
}

bool MultiStack::isFull(int StackNo) {
    return top[StackNo] == stkCapacity(StackNo);
}

int MultiStack::stkCapacity(int StackNo) {
    return ((StackNo + 1) * Capacity) - 1;
}

int MultiStack::stkBase(int StackNo) {
    return StackNo * Capacity;
}