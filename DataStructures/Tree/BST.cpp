/**
 * title: Recursive Implementation of Binary Search Tree
 * date:  23 June 2017
 */

#include <iostream>
#include <sstream>

#include "BST.h"
#include "logging.h"

using namespace std;

//PRIVATE

node* BST::newNode(int x)
{
    node *t = new node;
    t->data = x;
    t->left = t->right = NULL;

    return t;
}

//PUBLIC

BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    deleteTree(root);
}

//BASIC

void BST::insert(int x)
{
    root = insert(x, root);
}

node* BST::insert(int x, node* t)
{
    if (t == NULL) {
        t = newNode(x);
        stringstream stream;
        stream << "Inserting(" << t->data << ")" << endl;
        logger.log(stream.str(), LOG_INFO);
    }
    else if (x < t->data)
        t->left = insert(x, t->left);
    else if (x > t->data)
        t->right = insert(x, t->right);
    return t;
}

void BST::remove(int x)
{
    root = remove(x, root);

    stringstream stream; 
    stream << "Deleting(" << x << ")" << endl; 
    logger.log(stream.str(), LOG_INFO);
}

node* BST::remove(int x, node* t)
{
    node* temp;
    if (t == NULL)
        return NULL;
    else if (x < t->data) //Search left sub-tree
        t->left = remove(x, t->left);
    else if (x > t->data) //Search right sub-tree
        t->right = remove(x, t->right);
    else // This is node to be deleted
    { 
        if (t->left == NULL) { // node with only right child or no child
            temp = t;
            t = t->right;
            stringstream stream; stream << "Deleting(" << temp->data << ")" << endl; logger.log(stream.str(), LOG_DEBUG);
            delete temp;
        }
        else if (t->right == NULL) { //node with only left child : left is not NULL and right is NULL 
            temp = t;
            t = t->left;
            stringstream stream; stream << "Deleting(" << temp->data << ")" << endl; logger.log(stream.str(), LOG_DEBUG);
            delete temp;
        }
        else /*if(t->left && t->right)*/ {   // Node to be deleted has 2 children
            temp = findMin(t->right);        //find inorder successor
            stringstream stream; stream << "Deleting(" << t->data << ")" << endl; logger.log(stream.str(), LOG_DEBUG);
            t->data = temp->data;            //copy to this node and delete inorder successor
            t->right = remove(t->data, t->right);
        }
    }
    return t;
}

void BST::deleteTree(node* t)
{
    if (t == NULL)
        return;

    deleteTree(t->left);
    deleteTree(t->right);
    delete t;
}

//TRAVERSAL

void BST::inorder()
{
    cout << "INORDER : ";
    inorder(root);
    cout << endl;
}

void BST::inorder(node* t)
{
    if (t == NULL)
        return;
    inorder(t->left);
    cout << t->data << " ";
    inorder(t->right);
}

//UTILITY

node *BST::find(int x)
{
    return find(root, x);
}

node* BST::find(node* t, int x)
{
    if (t == NULL)
        return NULL;
    else if (x < t->data)
        return find(t->left, x);
    else if (x > t->data)
        return find(t->right, x);
    else
        return t;
}

node* BST::findMin(node* t)
{
    if (t == NULL)
        return NULL;
    else if (t->left == NULL)
        return t;
    else
        return findMin(t->left);
}

node* BST::findMax(node* t)
{
    if (t == NULL)
        return NULL;
    else if (t->right == NULL)
        return t;
    else
        return findMax(t->right);
}

void BST::test()
{
    BST t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.inorder();

    node *tmp = t.find(20);
    if(tmp) cout << "Found : " << tmp->data << endl;
    else cout << "data not found" << endl;
    
    t.remove(20);
    t.inorder();

    t.remove(25);
    t.inorder();

    t.remove(30);
    t.inorder();
}

#if TEST_BST
int main()
{
    BST::test();
}
#endif