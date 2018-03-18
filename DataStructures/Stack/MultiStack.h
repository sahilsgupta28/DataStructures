#pragma once

class MultiStack {
    int StackCount;
    int Capacity;
    int *data;
    int *top;

public:
    MultiStack(int StackCount, int Capacity);
    ~MultiStack();

    void push(int StackNo, int x);
    int pop(int stackNo);
    int peek(int stackNo);
    bool isEmpty(int stackNo);
    bool isFull(int StackNo);

private:
    int stkCapacity(int StackNo);
    int stkBase(int StackNo);
};