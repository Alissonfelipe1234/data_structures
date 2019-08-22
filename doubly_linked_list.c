/*
please include '#include "doubly_linked_list.c"' in your code
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
 
typedef struct _doubly_node
{
    int value;
    struct _doubly_node *next;
    struct _doubly_node *prev;
} doubly_node;

typedef struct _doubly_list
{
    int size;
    doubly_node *first;
    doubly_node *last;
} doubly_list;

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
doubly_list* newdoubly_list();
doubly_list* clonedoubly_list(doubly_list* original);
doubly_list* sort_doubly_list(doubly_list* l);
doubly_node* newdoubly_node_empty();
doubly_node* newdoubly_node(int v);
doubly_node* indexof_doubly(doubly_list* l, int x);
int add_last_doubly(doubly_list* l, int v);
int add_first_doubly(doubly_list* l, int v);
int add_in_order_doubly(doubly_list* l, int v);
int remove_doubly_value(doubly_list* l, int v);
int contains_doubly_value(doubly_list* l, int v);
int doubly_len(doubly_list* l);
int is_doubly_empty(doubly_list* l); //! not implemented
void print_doubly(doubly_list* l); 

//===================================
//                                   
//   ####   #####   ####    #####  
//  ##     ##   ##  ##  ##  ##     
//  ##     ##   ##  ##  ##  #####  
//  ##     ##   ##  ##  ##  ##     
//   ####   #####   ####    #####  
//                                   
//===================================

doubly_list* newdoubly_list(){
    return (doubly_list*) calloc (1, sizeof(doubly_list));
}
doubly_list* clonedoubly_list(doubly_list* original){
    doubly_list* newest = newdoubly_list();
    doubly_node* p = original->first;
    for(;p!=NULL;p=p->next)
        add_last_doubly(newest, p->value);
    return newest;
}
doubly_list* sort_doubly_list(doubly_list* l){
    if (l == NULL)
     return NULL;
    if (l->size == 0)
        return  l;
    doubly_list* newest = newdoubly_list();
    doubly_node* p = l->first;
    while (p!=NULL)
    {
        add_in_order_doubly(newest, p->value);
        p = p->next;
    }
    return newest;    
}
doubly_node* newdoubly_node_empty(){
    return (doubly_node*) calloc (1, sizeof(doubly_node));
}
doubly_node* newdoubly_node(int v){
    doubly_node* ret = newdoubly_node_empty();
    ret->value = v;
    return ret;
}
doubly_node* indexof_linked(doubly_list* l, int x){
    doubly_node* p;
    if(x <= l->size/2)
    {
        p = l->first;
        for (int i = 0; i < x; i++)
            p = p->next;
    }
    else
    {
        p = l->last;
        for (int i = l->size; i >= x; i--)
            p = p->prev;
    }
        
    return p;
}
int add_last_doubly(doubly_list* l, int v){

    doubly_node* p = newdoubly_node(v);
    l->size++;
    if(l->first == NULL)
    {
        l->first = p;
        l->last = p;
        return 1;
    }

    p->prev = l->last;
    l->last->next = p;
    l->last = p;
    return 1;
}
int add_first_doubly(doubly_list* l, int v){

    doubly_node* p = newdoubly_node(v);
    l->size++;
    if(l->first == NULL)
    {
        l->last = p;
        l->first = p;
        return 1;
    }

    l->first->prev = p;
    p->next = l->first;
    l->first = p;
    return 1;
}
int add_in_order_doubly(doubly_list* l, int v){
    doubly_node* newest = newdoubly_node(v);
    if(l->first == NULL)
    {
        l->first = newest;
        l->last = newest;
        l->size++;
        return 1;
    }
    if(l->first->value >= v)
    {
        add_first_doubly(l, v);
        return 1;
    }
    if(l->last->value <= v)
    {
        add_last_doubly(l, v);
        return 1;
    }
    doubly_node* p = l->first->next;
    while (p->next != NULL)
    {
        if(p->value >= v)
        {
            newest->next = p;
            newest->prev = p->prev;
            p->prev->next = newest;
            p->prev = newest;
            l->size++;
            return 1;
        }
        p = p->next;
    }
    return 0;
}
int remove_doubly_value(doubly_list* l, int v){
    doubly_node* p;
    int size = doubly_len(l);
    if(size < 1)
        return 0;
    if(size == 1)
    {
        if(l->first->value != v)
            return 0;
        p = l->first;
        free(p);
        l->first = NULL;
        p = l->last;
        free(p);
        l->last = NULL;
        l->size--;
        return 1;
    }
    if(l->first->value == v)
    {
        p = l->first;
        l->first = p->next;
        l->first->prev = NULL;
        free(p);
        l->size--;
        return 1;
    }

    p = l->first->next;
    while (p->next != NULL)
    {
        if(p->value == v)
        {
            p->prev = p->next;
            p->next = p->prev;
            free(p);
            l->size--;
            return 1;
        }
        p = p->next;
    }

    if(l->last->value == v)
    {
        p = l->last;
        l->last = l->last->prev;
        l->last->next = NULL;
        free(p);
        l->size--;
        return 1;
    }
    return 0;
}
int contains_doubly_value(doubly_list* l, int v){
    doubly_node* p;
    p = l->first;
    while(p != NULL)
    {
        if(v == p->value)
            return 1;
        p = p->next;
    }
    return 0;
}
int doubly_len(doubly_list* l){
    return l->size;
}
void print_doubly(doubly_list* l){
    doubly_node* p = l->first;
    printf("[");
    if(l->last == NULL)
    {
        printf("NULL]");
        return;
    }
    for(; p->next != NULL;)
    {
        printf("%i, ", p->value);
        p = p->next;
    }
    printf("%i]", l->last->value);
}
