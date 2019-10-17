/*
please include '#include "queue.c"' in your code
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
typedef struct _queue_node
{
    int value;
    struct _queue_node *next;
} QueueNode;

typedef struct _queue
{
    QueueNode * first;
    QueueNode * last;
    int size;
} Queue;

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
Queue* newQueue();
Queue* cloneQueue(Queue* original);
Queue* sort_Queue(Queue* q);
QueueNode* newNode(int v);
QueueNode* find_Node(Queue* q, int value);
QueueNode* pop_node(Queue* q);

int add_value(Queue* q, int value);
int add_node(Queue* q, QueueNode* n);
int pop_value(Queue* q);


int contains_queue_value(Queue* q, int v);
int queue_len(Queue* l);

void clear_Node(QueueNode* n);
void printQueue(Queue* q);

//===================================
//                                   
//   ####   #####   ####    #####  
//  ##     ##   ##  ##  ##  ##     
//  ##     ##   ##  ##  ##  #####  
//  ##     ##   ##  ##  ##  ##     
//   ####   #####   ####    #####  
//                                   
//===================================

Queue* newQueue(){
    return (Queue*) calloc(1, sizeof(Queue));
}
Queue* cloneQueue(Queue* original)
{
    Queue* ret = (Queue*) calloc(1, sizeof(Queue));
    int value;
    for (int i = 0; i < queue_len(original); i++)
    {
        int value = pop_value(original);
        add_value(original, value);
        add_value(ret, value);
    }
    return ret;
}
Queue* sort_Queue(Queue* q){
    return q;
    //NOT IMPLEMENTED    
}
QueueNode* newNode(int v){
    QueueNode* ret = (QueueNode*) calloc(1, sizeof(QueueNode));
    ret->value = v;
    return ret;
}
QueueNode* find_Node(Queue* q, int value){
    QueueNode* ret = NULL;
    int walk = 0;
    int total = q->size;
    QueueNode* n = pop_node(q);
    while (walk < total)
    {
        if(n->value == value)
            ret = n;
        add_node(q, n);
        n = pop_node(q);
    }
    return ret;
}
QueueNode* pop_node(Queue* q){
    QueueNode* ret = q->first;
    q->first = q->first->next;
    clear_Node(ret);
    q->size--;
    return ret;
}
int add_value(Queue* q, int value){
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
int add_node(Queue* q, QueueNode* n){
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
int pop_value(Queue* q){
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
int contains_queue_value(Queue* q, int v){
    int walk = 0;
    int ret = 0;
    int total = q->size;
    QueueNode* n = pop_node(q);
    while (walk < total)
    {
        if(n->value == v)
            ret = 1;
        add_node(q, n);
        n = pop_node(q);
    }
    return ret;
}
int queue_len(Queue* l){
    return l->size;
}

void clear_Node(QueueNode* n){
    n->next = NULL;
}
void printQueue(Queue* q)
{
    if(q->size == 0)
    {
        printf("empty\n");
        return;
    }
    int i;
    QueueNode* n = q->first;
    printf("[");
    for (i=0; i < q->size-1; i++)
    {
        printf("%i, ", n->value);
        n = n->next;
    }
    printf("%i]\n", n->value);
}