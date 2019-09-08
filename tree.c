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

typedef struct _tree
{
    int value;
    struct _tree *right;
    struct _tree *left;
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
Tree* newTree(int value);
Tree* cloneTree(Tree* original);
void insertLeave(int value, Tree* root);
void printTree(Tree* root);
void printTreePreOrder(Tree* root);
void printTreePreOrder(Tree* root);
int hasValue(int value, Tree* root);
int len(Tree* root);
Tree* balanceTree(Tree* root);

int removeValue(Tree* l, int v);
int removeAllOccurrences(Tree* l, int v);
int containsValue(Tree* l, int v);

int findLevel(Tree* l, int v);
int isEmpty(Tree* l);

//===================================
//                                   
//   ####   #####   ####    #####  
//  ##     ##   ##  ##  ##  ##     
//  ##     ##   ##  ##  ##  #####  
//  ##     ##   ##  ##  ##  ##     
//   ####   #####   ####    #####  
//                                   
//===================================
Tree* newTree(int value){
    Tree* newest =  (Tree*) calloc(1, sizeof(Tree));
    newest->value = value;
    return newest;
}

void insertLeave(int value, Tree* root){
    if(root->value < value) 
    {
        if(root->right != NULL)
            insertLeave(value, root->right);
        else 
            root->right = newTree(value);
    }
    else 
    {
        if(root->left != NULL)
            insertLeave(value, root->left);
        else
            root->left = newTree(value);
    }
}

void printTree(Tree* root) {
    if(root==NULL)
        return;
    printTree(root->left);
    printf(" %i", root->value);
    printTree(root->right);
}

void printTreePostOrder(Tree* root) {
    if(root==NULL)
        return;
    printTreePostOrder(root->left);
    printTreePostOrder(root->right);
    printf(" %i", root->value);
}

void printTreePreOrder(Tree* root) {
    if(root==NULL)
        return;
    printf(" %i", root->value);
    printTreePreOrder(root->left);    
    printTreePreOrder(root->right);
}

int hasValue(int value, Tree* root){
    if(root == NULL)
        return 0;
    if(root->value == value)
        return 1;
    if(root->value > value)
        return hasValue(value, root->left);
    else
        return hasValue(value, root->right);
}

int len(Tree* root){
    if(root==NULL)
        return 0;
    return 1 + len(root->left) + len(root->right);
}