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

    node(int x) {
        data = x;
        left = right = NULL;
    }
};


class BST
{
protected:
    node* root;
    LOGGING logger;

public:

    BST();
    ~BST();

    // BASIC
    void insert(int x);
    void remove(int x);
    void deleteTree(node* t);
    
    // UTILITY
    node* search(int x);

    // DEBUG
    static void test();

    private:
    node* insert(node* t, int x);
    node* remove(node* t, int x);
    node* search(node* t, int x);
    node* findMin(node* t);
    node* findMax(node* t);
};

class DisplayTree : public BST
{
    
    public:
    void preorder();
    void inorder();
    void postorder();
    void levelorder();  //Print nodes level by level
    void rightview();

    private:
    void preorder(node *t);
    void inorder(node* t);
    void postorder(node* t);
    void rightview(node *t, int nodelevel, int* currentlevel);
};
