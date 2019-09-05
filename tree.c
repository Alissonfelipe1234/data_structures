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
Tree* newTree(int value){
    return (Tree*) calloc(1, sizeof(Tree));
}
void insertLeave(int value, Tree* root){
    
}