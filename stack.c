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
Stack* new_stack();
Stack* clone_stack(Stack* original);
StackNode* new_node_stack(int v);
StackNode* find_node_stack(Stack* s, int value);
StackNode* pop_node_stack(Stack* s);

int add_value_stack(Stack* s, int value);
int add_node_stack(Stack* s, StackNode* n);
int add_sort_node_stack(Stack* s, StackNode* n);
int sort_stack(Stack* s); //!deprecated
int pop_value_stack(Stack* s);

int contains_value_in_stack(Stack* s, int v);
int stack_len(Stack* s);

void clear_node_stack(StackNode* n);
void print_stack(Stack* s);

//===================================
//                                   
//   ####   #####   ####    #####  
//  ##     ##   ##  ##  ##  ##     
//  ##     ##   ##  ##  ##  #####  
//  ##     ##   ##  ##  ##  ##     
//   ####   #####   ####    #####  
//                                   
//===================================

Stack* new_stack(){
    return (Stack*) calloc(1, sizeof(Stack));
}
Stack* clone_stack(Stack* original)
{
    if(original == NULL || original->size == 0)
        return new_stack();
    Stack* ret = (Stack*) calloc(1, sizeof(Stack));
    StackNode* pointer = original->last;
    while (pointer!= NULL)
    {
        add_value_stack(ret, pointer->value);
        pointer = pointer->prev;
    }
    return ret;
}
StackNode* new_node_stack(int v){
    StackNode* ret = (StackNode*) calloc(1, sizeof(StackNode));
    ret->value = v;
    return ret;
}
StackNode* find_node_stack(Stack* s, int value){
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
StackNode* pop_node_stack(Stack* s){
    if(s == NULL)
        return NULL;
    StackNode* ret = s->last;
    s->last = s->last->prev;
    s->last->next = NULL;
    s->size--;
    clear_node_stack(ret);    
    return ret;
}
int add_value_stack(Stack* s, int value){
    if(s == NULL)
        return 0;
    s->size++;
    if(s->first == NULL)
    {
        s->first = new_node_stack(value);
        s->last = s->first;
        return 1;
    }
    s->first->prev = new_node_stack(value);
    s->first->prev->next = s->first;
    s->first = s->first->prev;
    return 1;
}
int add_node_stack(Stack* s, StackNode* n){
    if(s == NULL || n == NULL)
        return 0;
    clear_node_stack(n);
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
int pop_value_stack(Stack* s){
    if(s == NULL)
        return 0;
    int ret = s->first->value;
    s->first = s->first->next;
    free(s->first->prev);
    s->first->prev = NULL;
    s->size--;
    return ret;
}
int contains_value_in_stack(Stack* s, int v){
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

void clear_node_stack(StackNode* n){
    n->next = NULL;
    n->prev = NULL;
}
void print_stack(Stack* s)
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
        printf("❎\n");
    }
}