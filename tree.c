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



Tree* sortTree(Tree* l);
Tree* findNode(Tree* l, int v);
int removeValue(Tree* l, int v);
int removeAllOccurrences(Tree* l, int v);
int containsValue(Tree* l, int v);
int len(Tree* l);
int findLevel(Tree* l, int v);
int isEmpty(Tree* l);
void printTree(Tree* l);

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

void insertLeave(register int value, register Tree* root){
    if(root==NULL) root = newTree(value);
    else if(root->value < value) insertLeave(value, root->right);
    else insertLeave(value, root->left);
}
void printTree(Tree* root) {
    if(root==NULL)
        return;
    printTree(root->left);
    printf(" %i", root->value);
    printTree(root->right);
}
int main()
{
    Tree* teste = newTree(5);
    insertLeave(1, teste);
    insertLeave(2, teste);
    insertLeave(3, teste);
    insertLeave(4, teste);
    insertLeave(6, teste);
    printTree(teste);
    return 0;
}