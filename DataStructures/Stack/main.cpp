/* 1. Multiple stack in array
        - Fixed Partition                       [DONE]
        - Flexible Division (Complex)
 * 2. Stack Min
        - Min at each state
        - Stack to keep track of min            [DONE]
 * 3. Set of Stacks with PopAt(index)
 * 4. Queue with Stacks
        - 2 stacks
        - 2 stacks lazy approach
 * 5. Sort Stacks with 2 stacks
        - Insert in right place in stack 2      [DONE]
 * 6. Animal Shelter - return oldest animal
        - Maintain separate queue
 */

#include <iostream>

#include "stack.h"
#include "MultiStack.h"
#include "MinStack.h"

using namespace std;

void testStack()
{
    Stack s1(10);
    s1.push(3);
    s1.push(2);
    s1.push(4);
    s1.push(1);
    s1.push(5);

    s1.sort();

    cout << s1.peek() << " ";
    cout << s1.pop() << " ";
    cout << s1.peek() << endl;

    cout << s1.peek() << " ";
    cout << s1.pop() << " ";
    cout << s1.peek() << endl;

    cout << s1.peek() << " ";
    cout << s1.pop() << " ";
    cout << s1.peek() << endl;

    cout << s1.peek() << " ";
    cout << s1.pop() << " ";
    cout << s1.peek() << endl;
}

void testMultiStack()
{
    MultiStack s1(3, 10);
    s1.push(0, 1);
    s1.push(0, 2);
    s1.push(1, 3);
    s1.push(1, 4);
    s1.push(2, 4);
    s1.push(2, 5);

    cout << s1.peek(0) << " ";
    cout << s1.pop(0) << " ";
    cout << s1.peek(0) << endl;

    cout << s1.peek(1) << " ";
    cout << s1.pop(1) << " ";
    cout << s1.peek(1) << endl;

    cout << s1.peek(2) << " ";
    cout << s1.pop(2) << " ";
    cout << s1.peek(2) << endl;

    cout << s1.peek(0) << " ";
    cout << s1.pop(0) << " ";
    cout << s1.peek(0) << endl;

    cout << s1.peek(1) << " ";
    cout << s1.pop(1) << " ";
    cout << s1.peek(1) << endl;

    cout << s1.peek(2) << " ";
    cout << s1.pop(2) << " ";
    cout << s1.peek(2) << endl;

    //s1.push(3, 5);    //throw
}

void testMinStack()
{
    MinStack s1(10);
    s1.push(10);
    s1.push(5);
    s1.push(7);
    s1.push(2);
    s1.push(6);
    s1.push(0);
    s1.push(100);

    cout << s1.peek() << " ";
    cout << s1.min() << " ";
    cout << s1.pop() << " ";
    cout << s1.peek() << endl;

    cout << s1.peek() << " ";
    cout << s1.min() << " ";
    cout << s1.pop() << " ";
    cout << s1.peek() << endl;

    cout << s1.peek() << " ";
    cout << s1.min() << " ";
    cout << s1.pop() << " ";
    cout << s1.peek() << endl;

    cout << s1.peek() << " ";
    cout << s1.min() << " ";
    cout << s1.pop() << " ";
    cout << s1.peek() << endl;

    cout << s1.peek() << " ";
    cout << s1.min() << " ";
    cout << s1.pop() << " ";
    cout << s1.peek() << endl;

    cout << s1.peek() << " ";
    cout << s1.min() << " ";
    cout << s1.pop() << " ";
    cout << s1.peek() << endl;

    cout << s1.peek() << " ";
    cout << s1.min() << " ";
    cout << s1.pop() << " ";
    cout << s1.peek() << endl;
}

void main()
{
    testStack();
    //testMultiStack();
    //testMinStack();
}