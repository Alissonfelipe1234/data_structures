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
void printTreeLeved(Tree* root, int order);
int hasValue(int value, Tree* root);
int isBalanced(Tree* root);
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
        root->right == NULL ? root->right = newTree(value) : insertLeave(value, root->right);
    else
        root->left == NULL ? root->left = newTree(value) : insertLeave(value, root->left);
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

void printTreeLeved(Tree* root, int order) {
    if(root==NULL)
        return;
    int next = order+1;
    printTreeLeved(root->left, next);
    printf(" %i (%i)\n", root->value, order);
    printTreeLeved(root->right, next);
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

int isBalanced(Tree* root){
    if (root==NULL)
        return 1;
    return 
        isBalanced(root->left) && 
        isBalanced(root->right) && 
        (len(root->left) - len(root->right) <= 1);
}

int len(Tree* root){
    if(root==NULL)
        return 0;
    return 1 + len(root->left) + len(root->right);
}

Tree* balanceTreeInternal(Tree* root, int half, int left, int right){
    if (half == 0)
        return newTree(root->value);
    else if(half > left)
    {
        Tree* branch = balanceTreeInternal(root->right, half--, len(root->right->left), len(root->right->left));
        insertLeave (root->value, branch);
        return branch;
    }
    else
    {
        Tree* branch = balanceTreeInternal(root->left, half--, len(root->left->left), len(root->left->left));
        insertLeave (root->value, branch);
        return branch;
    }    
    
    /*
    if(half == 0)
        return newTree(root->value);

    half--;
    if(root->left!=NULL)
    {
        Tree* branch = balanceTreeInternal(root->left, half);
        insertLeave(root->value, branch);
        return branch;
    }
    else if (root->right!=NULL)
    {
        Tree* branch = balanceTreeInternal(root->right, half);
        insertLeave(root->value, branch);
        return branch;
    }
    else
    {
        Tree* branch = balanceTreeInternal(root->right, half++);
        insertLeave(root->value, branch);
        return branch;
    }
    */
}

Tree* balanceTree(Tree* root){
    return balanceTreeInternal(root, len(root), len(root->left), len(root->left));;
}

int main()
{
    Tree* teste = newTree(5);
    insertLeave(4, teste);
    insertLeave(8, teste);
    insertLeave(1, teste);
    insertLeave(5, teste);
    insertLeave(9, teste);
    if(isBalanced(teste))
        printf("Está balanceada");
    else
        printf("Não está balanceada");
    printTreeLeved(teste, 0);
    return 0;
}