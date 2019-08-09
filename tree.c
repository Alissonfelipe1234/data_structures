/*
    please include '#include "tree.c"' in your code
*/
//===========================================================
//                                                           
//   ####  ######  #####    ##   ##   ####  ######   ####  
//  ##       ##    ##  ##   ##   ##  ##       ##    ##     
//   ###     ##    #####    ##   ##  ##       ##     ###   
//     ##    ##    ##  ##   ##   ##  ##       ##       ##  
//  ####     ##    ##   ##   #####    ####    ##    ####   
//                                                           
//===========================================================

typedef struct _node
{
    int value;
    struct _node *right;
    struct _node *left;
} Node;

typedef struct _tree
{
    Node* root;

} Tree;

//============================================================
//                                                            
//  ##   ##  #####    ###    ####    #####  #####     ####  
//  ##   ##  ##      ## ##   ##  ##  ##     ##  ##   ##     
//  #######  #####  ##   ##  ##  ##  #####  #####     ###   
//  ##   ##  ##     #######  ##  ##  ##     ##  ##      ##  
//  ##   ##  #####  ##   ##  ####    #####  ##   ##  ####   
//                                                            
//============================================================

#include<stdio.h>
#include<stdlib.h>
Tree* newTree();
Tree* cloneTree(Tree* original);
Tree* sortTree(Tree* l);
Node* newNodeEmpty();
Node* newNode(int v);
Node* findNode(Tree* l, int v);
int addRight(Node* l, int v);
int addLeft(Node* l, int v);
int addInOrder(Tree* l, int v);
int removeValue(Node* l, int v);
int removeAllOccurrences(Tree* l, int v);
int containsValue(Tree* l, int v);
int len(Tree* l);
int findLevel(Tree* l, int v);
int isEmpty(Tree* l);
void printAll(Tree* l);

//===================================
//                                   
//   ####   #####   ####    #####  
//  ##     ##   ##  ##  ##  ##     
//  ##     ##   ##  ##  ##  #####  
//  ##     ##   ##  ##  ##  ##     
//   ####   #####   ####    #####  
//                                   
//===================================