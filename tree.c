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
Tree* balanceTree(Tree* root);

void insertLeave(int value, Tree* root);
void printTree(Tree* root);
void printTreePreOrder(Tree* root);
void printTreePreOrder(Tree* root);
void printTreeLevedInternal(Tree* root, int order);
void printTreeLeved(Tree* root);
void printTree2Dinternal(Tree* root, int space);
void printTree2D(Tree* root);
int hasValue(int value, Tree* root);
int isBalanced(Tree* root);
int len(Tree* root);
int nivel(Tree* root);
int max(int left, int right);
int removeValueInternal(int value, Tree* root, Tree* prev, int direction);
int removeValue(int value, Tree** root);

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

void printTreeLevedInternal(Tree* root, int order) {
    if(root==NULL)
        return;
    int next = order+1;
    printTreeLevedInternal(root->left, next);
    printf(" %i (%i)\n", root->value, order);
    printTreeLevedInternal(root->right, next);
}
void printTreeLeved(Tree* root){
    if(root == NULL)
        printf("Empty Tree\n");
    printTreeLevedInternal(root, 0);
}

void printTree2Dinternal(Tree* root, int space) {
    if (root == NULL) 
        return;
    space += 10; 
    printTree2Dinternal(root->right, space); 
    printf("\n"); 

    for (int i = 10; i < space; i++) 
        printf(" "); 
    printf("%d", root->value); 
    if (root->right!=NULL && root->left!=NULL)
        printf("<");
    else if(root->right==NULL && root->left!=NULL)
        printf("↘");
    else if(root->right!=NULL && root->left==NULL)
        printf("↗");
    else
        printf("■");
    
    printf("\n");    
    printTree2Dinternal(root->left, space); 

}

void printTree2D(Tree *root) 
{ 
    if(root == NULL)
        printf("Empty Tree\n");
    printTree2Dinternal(root, 0); 
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

int balanceFactor(Tree* root){
    if (root==NULL)
        return 0;
    return nivel(root->left) - nivel(root->right);
}

int len(Tree* root){
    if(root==NULL)
        return 0;
    return 1 + len(root->left) + len(root->right);
}

int nivel(Tree* root){
    if(root==NULL)
        return 0;
    return 1 + max(nivel(root->left), nivel(root->right));
}

int max(int left, int right){
    return left > right? left: right;
}
int removeValueInternal(int value, Tree* root, Tree* prev, int direction){
    if(root==NULL)
        return 0;
    if(root->value == value)
    {
        if(prev == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
        {
            
            if(direction == 2)
                prev->right = NULL;
            else
                prev->left = NULL;
            free(root);
            return 1;
        }
        if(root->left == NULL)
        {
            if(direction == 1)
                prev->left = root->right;
            else
                prev->right = root->right;
            free(root);
            return 1;
        }
        if(root->right == NULL)
        {
            if(direction == 1)
                prev->left = root->left;
            else
                prev->right = root->left;
            free(root);
            return 1;
        }
        Tree* left_pointer;
        Tree* right_pointer;
        if(direction == 1)
        {
            left_pointer = prev->left->left;
            right_pointer = prev->left->right;
            while(right_pointer->left!=NULL)
                right_pointer = right_pointer->left;
            right_pointer->left = left_pointer;
            prev->left = prev->left->right;
            free(root);
            return 1;
        }
        else
        {
            right_pointer = prev->right->right;
            left_pointer = prev->right->left;            
            while(left_pointer->right!=NULL)
                left_pointer = left_pointer->right;
            left_pointer->right = right_pointer;
            prev->right = prev->right->left;
            free(root);
            return 1;
        }
        
    }
    return root->value > value? removeValueInternal(value, root->left, root, 1): removeValueInternal(value, root->right, root, 2);
}
int removeValue(int value, Tree** root){
    if((*root) == NULL)
        return 0;
    if((*root)->value == value)
    {
        if((*root)->left == NULL && (*root)->right == NULL)
        {
            free(*root);
            *root = NULL;
            return 1;
        }
        Tree* aux = *root;
        if((*root)->left == NULL)
        {
            *root = (*root)->right;
            free(aux);
            aux = NULL;
            return 1;
        }
        if((*root)->right == NULL)
        {
            *root = (*root)->left;
            free(aux);
            aux = NULL;
            return 1;
        }
        Tree* successor  = aux->right;
        int levels = 0;
        while (successor->left!=NULL)
        {
            levels++;
            aux = successor;
            successor = successor->left;
        }
        (*root)->value = successor->value--; //new root is successor minus 1 because the successor must be greater than the root
        removeValueInternal(successor->value, *root, NULL, 0);
        (*root)->value++; //return the root true value
        return 1;
    }
    return removeValueInternal(value, *root, NULL, 0);
}
int main()
{
    Tree* teste = newTree(20);
    insertLeave(10, teste);
    insertLeave(30, teste);
    insertLeave(40, teste);
    insertLeave(40, teste);
    insertLeave(22, teste);
    insertLeave(22, teste);
    removeValue(23, &teste);
    printTree2D(teste);
    return 0;
}