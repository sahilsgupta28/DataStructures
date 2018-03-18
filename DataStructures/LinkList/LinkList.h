/** Link List Header File
 *  @author     Sahil Gupta
 *  @date       03 March 2018
 */
#pragma once

#include <iostream>

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class LinkList
{
    Node *head;
    //Node *tail = nullptr;        //Improve Insert at end

    //For Palindrome
    class NodeState {
        public:
            Node *node;
            bool status;
        NodeState(Node *anode, bool astatus) : node(anode), status(astatus) {};
    };

    public:
    LinkList() : head(nullptr) {}
    ~LinkList() { clear(); }
    void insert(int x);
    void insert(Node* node);
    bool deleteNode(int x);
    void clear();
    void display();
    int length();
    
    //Extended
    void reverse();
    void rotate_right(int x);

    //Advanced

    /** Remove Duplicates
     *  Use set to identify duplicates - Needs Buffer, O(N)
     *  Use runner to compare next elements - No extra space, O(N^2)
     */
    void remove_duplicates();
    Node* nthLast(int n);       //get nth last node
    /* @todo Delete Middle Node */
    void partition(int x);      //partition around x, not stable (changes order)
    void partition_stable(int x);  //partition around x, stable (preserves order)
    
    LinkList* SumBackwardNo(LinkList *b);
    //todo
    //LinkList* SumBackwardNo(LinkList *b);

    //todo Strategy Design Pattern
    /*
     * 1. Fast Pointer + Stack. 1 Pass, Space
     * 2. Reverse + Compare Half. 2 Pass, Space
     * 3. Recursive. Need Length
     */
    bool IsPalindrome();        //Recursive
    bool IsPalindrome_stack();  //Fast Pointer + stack
    
    /* Intersection
     * Get Length, compare last, ignore difference, traverse untill node is same
     */
    Node* IfIntersect(LinkList *b);
    
    /* Loop
     * 1. Hashing - Put nodes in unordered-set
     * 2. Fast Pointer - Floyd’s Cycle-Finding Algorithm
     */
    bool IsLoop();

    //todo Remove Loop

    private:
    NodeState* checkPalindrome(Node* node, int length);
};