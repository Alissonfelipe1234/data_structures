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
Queue* new_queue();
Queue* clone_queue(Queue* original);

QueueNode* new_node_queue(int v);
QueueNode* find_node_queue(Queue* q, int value);
QueueNode* pop_node_queue(Queue* q);

int add_value_queue(Queue* q, int value);
int add_node_queue(Queue* q, QueueNode* n);
int add_sort_node_queue(Queue* q, QueueNode* n);
int sort_queue(Queue* q);
int pop_value_queue(Queue* q);


int contains_value_in_queue(Queue* q, int v);
int queue_len(Queue* q);

void clear_node_queue(QueueNode* n);
void print_queue(Queue* q);

//===================================
//                                   
//   ####   #####   ####    #####  
//  ##     ##   ##  ##  ##  ##     
//  ##     ##   ##  ##  ##  #####  
//  ##     ##   ##  ##  ##  ##     
//   ####   #####   ####    #####  
//                                   
//===================================

Queue* new_queue(){
    return (Queue*) calloc(1, sizeof(Queue));
}
Queue* clone_queue(Queue* original)
{
    if(original == NULL || original->size == 0)
        return new_queue();
    Queue* ret = (Queue*) calloc(1, sizeof(Queue));
    int value;
    for (int i = 0; i < queue_len(original); i++)
    {
        int value = pop_value_queue(original);
        add_value_queue(original, value);
        add_value_queue(ret, value);
    }
    return ret;
}
QueueNode* new_node_queue(int v){
    QueueNode* ret = (QueueNode*) calloc(1, sizeof(QueueNode));
    ret->value = v;
    return ret;
}
QueueNode* find_node_queue(Queue* q, int value){
    QueueNode* ret = NULL;
    int walk = 0;
    int total = q->size;
    QueueNode* n = pop_node_queue(q);
    while (walk < total)
    {
        if(n->value == value)
            ret = n;
        add_node_queue(q, n);
        n = pop_node_queue(q);
    }
    return ret;
}
QueueNode* pop_node_queue(Queue* q){
    QueueNode* ret = q->first;
    q->first = q->first->next;
    clear_node_queue(ret);
    q->size--;
    return ret;
}
int add_value_queue(Queue* q, int value){
    if(q == NULL)
        return 0;
    q->size++;
    if(q->last == NULL)
    {
        q->last = new_node_queue(value);
        q->first = q->last;
        return 1;
    }
    q->last->next = new_node_queue(value);
    q->last = q->last->next;
    return 1;
}
int add_node_queue(Queue* q, QueueNode* n){
    if(q == NULL || n == NULL)
        return 0;
    clear_node_queue(n);
    q->size++;
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
int add_sort_node_queue(Queue* q, QueueNode* n){
    if(q == NULL || n == NULL)
        return 0;
    if(q->size == 0)
    {
        q->first = n;
        q->last = n;
        q->size++;
        return 1;
    }
    if(q->first->value >= n->value)
    {
        n->next = q->first;
        q->first = n;
        q->size++;
        return 1;
    }
    if(q->last->value <= n->value)
        return add_node_queue(q,n);
    
    QueueNode* point = q->first;
    while (point->value < n->value)
        point = point->next;
    
    n->next = point->next;
    point->next = n;
    q->size++;
    return 1;
}
int sort_queue(Queue* q){
    if(q == NULL)
        return 0;
    if(q->size == 1)
        return 1;
    
    Queue* empty = new_queue();
    while (q->size > 0)
        add_sort_node_queue(empty, pop_node_queue(q));
    q->first = empty->first;
    q->last = empty->last;
    q->size = empty->size;
    free(empty);
    return q;
    //NOT IMPLEMENTED    
}
int pop_value_queue(Queue* q){
    if(q == NULL)
        return 0;
    int ret = q->first->value;
    q->last->next = q->first;
    q->first = q->first->next;
    free(q->last->next);
    clear_node_queue(q->last);
    q->size--;
    return ret;
}
int contains_value_in_queue(Queue* q, int v){
    if(q == NULL)
        return 0;
    int walk = 0;
    int ret = 0;
    int total = q->size;
    QueueNode* n = pop_node_queue(q);
    while (walk < total)
    {
        if(n->value == v)
            ret = 1;
        add_node_queue(q, n);
        n = pop_node_queue(q);
    }
    return ret;
}
int queue_len(Queue* q){
    return q->size;
}
void clear_node_queue(QueueNode* n){
    n->next = NULL;
}
void print_queue(Queue* q)
{
    if(q->size == 0)
    {
        printf("empty\n");
        return;
    }
    int i;
    QueueNode* n = q->first;
    printf("⬇\n");
    for (i=0; i < q->size-1; i++)
    {
        printf("%i\n", n->value);
        n = n->next;
    }
    printf("%i\n❎", n->value);
}