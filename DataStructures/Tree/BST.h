/**
 * title: Recursive Implementation of Binary Search Tree
 * date:  23 June 2017
 */

#pragma once

#include <iostream>
#include "logging.h"

#define TEST_BST 1

struct node
{
    int data;
    node* left;
    node* right;
};


class BST
{
    node* root;
    LOGGING logger;

private:
    node* newNode(int x);

public:

    BST();
    ~BST();

    // BASIC
    void insert(int x);
    void remove(int x);
    void deleteTree(node* t);
    
    // TRAVERSAL
    void inorder();
    
    // UTILITY
    node* find(int x);
    
    static void test();

    private:
    node* insert(int x, node* t);
    node* remove(int x, node* t);
    void inorder(node* t);
    node* find(node* t, int x);
    node* findMin(node* t);
    node* findMax(node* t);
};
