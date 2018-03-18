/**
 * title: Recursive Implementation of Binary Search Tree
 * date:  23 June 2017
 */

#include <iostream>
#include <sstream>

#include <queue>

#include "BST.h"
#include "logging.h"

using namespace std;

BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    deleteTree(root);
}

// BASIC

void BST::insert(int x)
{
    stringstream stream;
    stream << "Inserting(" << x << ")" << endl;
    logger.log(stream.str(), LOG_INFO);

    root = insert(root, x);
}

node* BST::insert(node* t, int x)
{
    if (t == NULL)
        return new node(x);
    
    if (x < t->data)
        t->left = insert(t->left, x);
    else if (x > t->data)
        t->right = insert(t->right, x);

    return t;
}

void BST::remove(int x)
{
    root = remove(root, x);

    stringstream stream; 
    stream << "Deleting(" << x << ")" << endl; 
    logger.log(stream.str(), LOG_INFO);
}

node* BST::remove(node* t, int x)
{
    t = search(t, x);
    if (t == NULL)
        return NULL;    
    else // This is node to be deleted
    { 
        node* temp;
        if (t->left == NULL) { // node with only right child or no child
            temp = t;
            t = t->right;
            delete temp;
        }
        else if (t->right == NULL) { //node with only left child : left is not NULL and right is NULL 
            temp = t;
            t = t->left;
            delete temp;
        }
        else /*if(t->left && t->right)*/ {   // Node to be deleted has 2 children
            temp = findMin(t->right);        //find inorder successor
            t->data = temp->data;            //copy to this node and delete inorder successor
            t->right = remove(t->right, t->data);
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

// UTILITY

node *BST::search(int x)
{
    return search(root, x);
}

node* BST::search(node* t, int x)
{
    if (t == NULL)
        return NULL;
    else if (x < t->data)
        return search(t->left, x);
    else if (x > t->data)
        return search(t->right, x);
    else
        return t;
}

node* BST::findMin(node* t)
{
    if (t == NULL)
        return NULL;
    while (t->left != NULL)
        t = t->left;
    return t;
        
}

//node* BST::findMax(node* t)
//{
//    if (t == NULL)
//        return NULL;
//    else if (t->right == NULL)
//        return t;
//    else
//        return findMax(t->right);
//}

node* BST::findMax(node* t)
{
    if (t == NULL)
        return NULL;
    while (t->right != NULL)
        t = t->right;
    return t;
}

// TRAVERSAL

void DisplayTree::inorder()
{
    cout << "INORDER : ";
    inorder(root);
    cout << endl;
}

void DisplayTree::preorder()
{
    cout << "PREORDER: ";
    preorder(root);
    cout << endl;
}

void DisplayTree::postorder()
{
    cout << "POSTORDER : ";
    postorder(root);
    cout << endl;
}

void DisplayTree::inorder(node* t)
{
    if (t == NULL)
        return;
    inorder(t->left);
    cout << t->data << " ";
    inorder(t->right);
}

void DisplayTree::preorder(node* t)
{
    if (t == NULL)
        return;
    cout << t->data << " ";
    preorder(t->left);
    preorder(t->right);
}

void DisplayTree::postorder(node* t)
{
    if (t == NULL)
        return;
    postorder(t->left);
    postorder(t->right);
    cout << t->data << " ";
}

void DisplayTree::levelorder()
{
    queue<node *> q;
    q.push(root);
    cout << "Level Order : ";
    while (!q.empty()) {
        node *tmp = q.front();
        q.pop();
        cout << tmp->data << " ";
        if(tmp->left) q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
    }
    cout << endl;
}

void DisplayTree::rightview()
{
    int currentlevel = 0;
    cout << "Right View : ";
    rightview(root, 0, &currentlevel);
    cout << endl;
}

void DisplayTree::rightview(node *t, int nodelevel, int* currentlevel)
{
    if(t == NULL)
        return;

    if(*currentlevel == nodelevel) {
        cout << t->data << " ";
        *currentlevel += 1;
    }

    rightview(t->right, nodelevel + 1, currentlevel);
    rightview(t->left, nodelevel + 1, currentlevel);
}

// DEBUG

void BST::test()
{
    //BST t;
    DisplayTree t;
    t.insert(50);       //1                     50
    t.insert(75);       
    t.insert(25);       //2            25               75
    t.insert(10);   
    t.insert(90);
    t.insert(40);
    t.insert(60);       //3      10        40       60        90    
    t.insert(20);
    t.insert(70);       //4         20                 70
    t.insert(15);       //       15                     

    t.inorder();
    t.preorder();
    t.postorder();
    t.levelorder();
    t.rightview();

    node *tmp = t.search(20);
    if(tmp) cout << "Found : " << tmp->data << endl;
    else cout << "data not found" << endl;
    
    t.remove(20);
    t.inorder();

    t.remove(25);
    t.inorder();

    t.remove(60);
    t.inorder();
}

#if TEST_BST
int main()
{
    BST::test();
}
#endif