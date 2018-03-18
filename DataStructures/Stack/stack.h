#pragma once

class Stack {
    int* data;
    int top;
    int capacity;

    public:
    Stack(int capacity) {
        this->capacity = capacity;
        data = new int[capacity];
    }
    ~Stack() {
        delete[] data;
    }

    void push(int x);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    void sort();
};
