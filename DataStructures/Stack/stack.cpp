#include <iostream>
#include "stack.h"

void Stack::push(int x)
{
    if (!isFull()) {
        data[top++] = x;
    }
}

int Stack::pop()
{
    if (!isEmpty()) {
        return data[--top];
    }

    return -1;
}

int Stack::peek()
{
    if (!isEmpty()) {
        return data[top - 1];
    }

    return -1;
}

bool Stack::isEmpty()
{
    return top == 0;
}

bool Stack::isFull()
{
    return top == capacity;
}

void Stack::sort()
{
    Stack s(capacity);

    while (!isEmpty()) {
        int temp = pop();
        int cnt = 0;
        while (!s.isEmpty() && s.peek() > temp) {
            push(s.pop());
            ++cnt;
        }
        s.push(temp);
        while (cnt > 0) {
            s.push(pop());
            --cnt;
        }
    }

    while (!s.isEmpty()) {
        push(s.pop());
    }
}