/*
please include '#include "tree_root.c"' in your code
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



typedef struct _node_root
{
    int val;
    struct _node_root* esq;
    struct _node_root* dir;
}NodeRoot;

typedef struct _tree_root
{
    NodeRoot* raiz;
}TreeRoot;

//============================================================
//                                                            
//  ##   ##  #####    ###    ####    #####  #####     ####  
//  ##   ##  ##      ## ##   ##  ##  ##     ##  ##   ##     
//  #######  #####  ##   ##  ##  ##  #####  #####     ###   
//  ##   ##  ##     #######  ##  ##  ##     ##  ##      ##  
//  ##   ##  #####  ##   ##  ####    #####  ##   ##  ####   
//                                                            
//============================================================

#include <stdio.h>
#include <stdlib.h>

TreeRoot* new_tree_root();
NodeRoot* new_node_root(int value);
void print_order_root(TreeRoot* tree);
void print_order_recursive(NodeRoot* branch);
void print_pos_order(TreeRoot* tree);
void print_pos_order_recursive(NodeRoot* branch);
int insert_leave_root(TreeRoot* tree, int value);
int insert_leave_recursive(NodeRoot* branch, int value);
int remove_value_root(TreeRoot* tree, int value);
int remove_root(TreeRoot* tree);
int remover_value_root_recursive(NodeRoot* branch, int value, NodeRoot* prev, int direction);
int remover_value_here_root(NodeRoot* prev, NodeRoot* branch, int direction);
void delete_tree_root(TreeRoot** tree);
void delete_node_root(NodeRoot* branch);
void height_root(TreeRoot* tree);
int height_node_root(NodeRoot* branch, int actual);
int max(register int x, register int y);
void reverse_root(TreeRoot* tree);
void reverse_node_root(NodeRoot* branch);

//===================================
//                                   
//   ####   #####   ####    #####  
//  ##     ##   ##  ##  ##  ##     
//  ##     ##   ##  ##  ##  #####  
//  ##     ##   ##  ##  ##  ##     
//   ####   #####   ####    #####  
//                                   
//===================================

TreeRoot* new_tree_root(){
    return (TreeRoot*) calloc(1, sizeof(TreeRoot));
}
NodeRoot* new_node_root(int value){
    NodeRoot* novo = (NodeRoot*) calloc(1, sizeof(NodeRoot));
    novo->val = value;
    return novo;
}
void print_order_root(TreeRoot* tree){
    if(tree == NULL)
        printf("Empty tree root");
    print_order_recursive(tree->raiz);
}
void print_order_recursive(NodeRoot* branch){
    if(branch == NULL)
        return;
    print_order_recursive(branch->esq);
    printf("%i ", branch->val);
    print_order_recursive(branch->dir);
}
void print_pos_order(TreeRoot* tree){
    if(tree == NULL)
        printf("Empty tree root");
    print_pos_order_recursive(tree->raiz);
}
void print_pos_order_recursive(NodeRoot* branch){
    if(branch == NULL)
        return;
    print_pos_order_recursive(branch->esq);
    print_pos_order_recursive(branch->dir);
    printf("%i ", branch->val);
}
int insert_leave_root(TreeRoot* tree, int value){
    if(tree->raiz == NULL){
        tree->raiz = new_node_root(value);
        return 1;
    }
    return insert_leave_recursive(tree->raiz, value);
}
int insert_leave_recursive(NodeRoot* branch, int value){
    if(branch == NULL)
        return 0;
    if(branch->val < value)
        return branch->dir == NULL? branch->dir = new_node_root(value), 1: insert_leave_recursive(branch->dir, value);
    else
        return branch->esq == NULL? branch->esq = new_node_root(value), 1: insert_leave_recursive(branch->esq, value);
}
int remove_value_root(TreeRoot* tree, int value){
    if(tree == NULL)
        return 0;
    if(tree->raiz->val == value)
    {
        remove_root(tree);
        return 1;
    }

    return remover_value_root_recursive(tree->raiz, value, NULL, -1);
}
int remove_root(TreeRoot* tree){
    if(tree == NULL || tree->raiz == NULL)
        return 0;
    if(tree->raiz->dir == NULL && tree->raiz->esq == NULL)
    {
        free(tree->raiz);
        tree->raiz = NULL;
        return 1;
    }
    NodeRoot* aux;
    if(tree->raiz->dir == NULL)
    {
        aux = tree->raiz;
        tree->raiz = tree->raiz->esq;
        aux->esq = NULL;
        free(aux);
        return 1;
    }
    if(tree->raiz->esq == NULL)
    {
        aux = tree->raiz;
        tree->raiz = tree->raiz->dir;
        aux->dir = NULL;
        free(aux);
        return 1;
    }
    aux = tree->raiz->dir;
    while (aux->esq != NULL)
    {
        aux = aux->esq;
    }
    int folhaMorta = aux->val;
    remover_value_root_recursive(tree->raiz, folhaMorta, NULL, -1);
    tree->raiz->val = folhaMorta;
    return 1;
}
int remover_value_root_recursive(NodeRoot* branch, int value, NodeRoot* prev, int direction){
    if(branch == NULL)
        return 0;
    if(branch->val ==value)
        return remover_value_here_root(prev, branch, direction);
    if(branch->val < value)
        return remover_value_root_recursive(branch->dir, value, branch, 1);
    else
        return remover_value_root_recursive(branch->esq, value, branch, 0);
}
int remover_value_here_root(NodeRoot* prev, NodeRoot* branch, int direction){
    if(branch->dir == NULL && branch->esq == NULL)
    {
        free(branch);
        if(direction == 1)
            prev->dir = NULL;
        else
            prev->esq = NULL;
        return 1;
    }
    NodeRoot* aux;
    if(branch->dir == NULL)
    {
        aux = branch;
        if(direction == 1)
            prev->dir = branch->esq;
        else
            prev->esq = branch->esq;
        branch = branch->esq;
        aux->esq = NULL;
        free(aux);
        return 1;
    }
    if(branch->esq == NULL)
    {
        aux = branch;
        if(direction == 1)
            prev->dir = branch->dir;
        else
            prev->esq = branch->dir;
        branch = branch->dir;
        aux->dir = NULL;
        free(aux);
        return 1;
    }
    aux = branch->dir;
    while (aux->esq != NULL)
    {
        aux = aux->esq;
    }
    aux->esq = branch->esq;
    if(direction == 1)
    {
        prev->dir->esq = NULL;
        prev->dir = prev->dir->dir;
    }
    else
    {
        prev->esq->esq = NULL;
        prev->esq = prev->esq->dir;
    }     
    free(branch);
    return 1;
}
void delete_tree_root(TreeRoot** tree){
    if(*tree == NULL)
        return;
    delete_node_root((*tree)->raiz);
    free(*tree);
    *tree = NULL;
    tree = NULL;
}
void delete_node_root(NodeRoot* branch)
{
    if(branch == NULL)
        return;
    delete_node_root(branch->esq);
    delete_node_root(branch->esq);
    free(branch);
}
void height_root(TreeRoot* tree){
    if(tree == NULL)
        printf("Altura: 0");
    else
        printf("Altura: %i", height_node_root(tree->raiz, 1));
}
int height_node_root(NodeRoot* branch, int actual){
    if(branch == NULL)
        return 0;
    return 1 + max(height_node_root(branch->esq, actual+1), height_node_root(branch->dir, actual+1));
}
int max(register int x, register int y){
    return x>y? x: y;
}
void reverse_root(TreeRoot* tree){
    if(tree == NULL)
        return;
    reverse_node_root(tree->raiz);
}
void reverse_node_root(NodeRoot* branch){
    if(branch == NULL)
        return;

    NodeRoot* aux = branch->dir;
    branch->dir = branch->esq;
    branch->esq = aux;
    reverse_node_root(branch->dir);
    reverse_node_root(branch->esq);
}