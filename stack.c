/*
please include '#include "stack.c"' in your code
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
typedef struct _stack_node
{
    int value;
    struct _stack_node *next;
} StackNode;

typedef struct _stack
{
    StackNode * first;
    StackNode * last;
    int size;
} stack;

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
stack* newStack();
stack* cloneStack(stack* original);
stack* sort_Stack(stack* q);
StackNode* newNode(int v);
StackNode* find_Node(stack* q, int value);
StackNode* pop_node(stack* q);

int add_value(stack* q, int value);
int add_node(stack* q, StackNode* n);
int pop_value(stack* q);


int contains_stack_value(stack* q, int v);
int stack_len(stack* l);

void clear_Node(StackNode* n);
void printStack(stack* q);

//===================================
//                                   
//   ####   #####   ####    #####  
//  ##     ##   ##  ##  ##  ##     
//  ##     ##   ##  ##  ##  #####  
//  ##     ##   ##  ##  ##  ##     
//   ####   #####   ####    #####  
//                                   
//===================================

stack* newStack(){
    return (stack*) calloc(1, sizeof(stack));
}
stack* cloneStack(stack* original)
{
    stack* ret = (stack*) calloc(1, sizeof(stack));
    int value;
    for (int i = 0; i < stack_len(original); i++)
    {
        int value = pop_value(original);
        add_value(original, value);
        add_value(ret, value);
    }
    return ret;
}
stack* sort_Stack(stack* q){
    return q;
    //NOT IMPLEMENTED    
}
StackNode* newNode(int v){
    StackNode* ret = (StackNode*) calloc(1, sizeof(StackNode));
    ret->value = v;
    return ret;
}
StackNode* find_Node(stack* q, int value){
    StackNode* ret = NULL;
    int walk = 0;
    int total = q->size;
    StackNode* n = pop_node(q);
    while (walk < total)
    {
        if(n->value == value)
            ret = n;
        add_node(q, n);
        n = pop_node(q);
    }
    return ret;
}
StackNode* pop_node(stack* q){
    StackNode* ret = q->first;
    q->first = q->first->next;
    clear_Node(ret);
    q->size--;
    return ret;
}
int add_value(stack* q, int value){
    if(q == NULL)
        return 0;
    q->size++;
    if(q->last == NULL)
    {
        q->last = newNode(value);
        q->first = q->last;
        return 1;
    }
    q->last->next = newNode(value);
    q->last = q->last->next;
    return 1;
}
int add_node(stack* q, StackNode* n){
    if(q == NULL || n == NULL)
        return 0;
    clear_Node(n);
    if(q->last == NULL)
    {
        q->last = n;
        q->first = n;
        return 1;
    }
    q->last->next = n;
    q->last = n;
    return 1;
}
int pop_value(stack* q){
    if(q == NULL)
        return 0;
    int ret = q->first->value;
    q->last->next = q->first;
    q->first = q->first->next;
    free(q->last->next);
    clear_Node(q->last);
    q->size--;
    return ret;
}
int contains_stack_value(stack* q, int v){
    int walk = 0;
    int ret = 0;
    int total = q->size;
    StackNode* n = pop_node(q);
    while (walk < total)
    {
        if(n->value == v)
            ret = 1;
        add_node(q, n);
        n = pop_node(q);
    }
    return ret;
}
int stack_len(stack* l){
    return l->size;
}

void clear_Node(StackNode* n){
    n->next = NULL;
}
void printStack(stack* q)
{
    if(q->size == 0)
    {
        printf("empty\n");
        return;
    }
    int i;
    StackNode* n = q->first;
    printf("[");
    for (i=0; i < q->size-1; i++)
    {
        printf("%i, ", n->value);
        n = n->next;
    }
    printf("%i]\n", n->value);
}