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
    struct _stack_node *prev;
} StackNode;

typedef struct _stack
{
    StackNode * first;
    StackNode * last;
    int size;
} Stack;

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
Stack* newStack();
Stack* cloneStack(Stack* original);
StackNode* newNode(int v);
StackNode* find_Node(Stack* s, int value);
StackNode* pop_node(Stack* s);

int add_value(Stack* s, int value);
int add_node(Stack* s, StackNode* n);
int add_sortStackNode(Stack* s, StackNode* n);
int sort_Stack(Stack* s);
int pop_value(Stack* s);

int contains_stack_value(Stack* s, int v);
int stack_len(Stack* s);

void clear_Node(StackNode* n);
void printStack(Stack* s);

//===================================
//                                   
//   ####   #####   ####    #####  
//  ##     ##   ##  ##  ##  ##     
//  ##     ##   ##  ##  ##  #####  
//  ##     ##   ##  ##  ##  ##     
//   ####   #####   ####    #####  
//                                   
//===================================

Stack* newStack(){
    return (Stack*) calloc(1, sizeof(Stack));
}
Stack* cloneStack(Stack* original)
{
    if(original == NULL || original->size == 0)
        return newStack();
    Stack* ret = (Stack*) calloc(1, sizeof(Stack));
    StackNode* pointer = original->last;
    while (pointer!= NULL)
    {
        add_value(ret, pointer->value);
        pointer = pointer->prev;
    }
    return ret;
}
StackNode* newNode(int v){
    StackNode* ret = (StackNode*) calloc(1, sizeof(StackNode));
    ret->value = v;
    return ret;
}
StackNode* find_Node(Stack* s, int value){
    if(s==NULL)
        return NULL;
    StackNode* ret = s->last;
    while (ret!=NULL)
    {
        if(ret->value == value)
            return ret;
        ret = ret->prev;
    }    
    return ret;
}
StackNode* pop_node(Stack* s){
    if(s == NULL)
        return NULL;
    StackNode* ret = s->last;
    s->last = s->last->prev;
    s->last->next = NULL;
    s->size--;
    clear_Node(ret);    
    return ret;
}
int add_value(Stack* s, int value){
    if(s == NULL)
        return 0;
    s->size++;
    if(s->first == NULL)
    {
        s->first = newNode(value);
        s->last = s->first;
        return 1;
    }
    s->first->prev = newNode(value);
    s->first->prev->next = s->first;
    s->first = s->first->prev;
    return 1;
}
int add_node(Stack* s, StackNode* n){
    if(s == NULL || n == NULL)
        return 0;
    clear_Node(n);
    s->size++;
    if(s->first == NULL)
    {
        s->first = n;
        s->last = n;        
        return 1;
    }
    n->next = s->first;
    s->first->prev = n;
    s->first = n;
    return 1;
}
int pop_value(Stack* s){
    if(s == NULL)
        return 0;
    int ret = s->first->value;
    s->first = s->first->next;
    free(s->first->prev);
    s->first->prev = NULL;
    s->size--;
    return ret;
}
int contains_stack_value(Stack* s, int v){
    if(s == NULL)
        return 0;
    StackNode* pointer= s->last;
    while (pointer!=NULL)
    {
        if(pointer->value == v)
            return 1;
        pointer = pointer->prev;
    }
    return 0;
}
int stack_len(Stack* s){
    return s->size;
}

void clear_Node(StackNode* n){
    n->next = NULL;
    n->prev = NULL;
}
void printStack(Stack* s)
{
    if(s->size == 0)
        printf("empty\n");
    else{
        StackNode* n = s->last;
        printf("⬇\n");
        while (n!=NULL)
        {
            printf("%i\n", n->value);
            n = n->prev;
        }
        printf("▀\n");
    }
}