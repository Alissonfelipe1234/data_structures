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
    doubly_node *first;
    doubly_node *last;
    int denyDuplicate;
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
doubly_list* sortlinked_list(doubly_list* l); //! not implemented
doubly_node* newdoubly_node_empty();
doubly_node* newdoubly_node(int v);
doubly_node* find_doubly_node(doubly_list* l, int v);
int add_last(doubly_list* l, int v);
int add_first(doubly_list* l, int v);
int remove_value(doubly_list* l, int v);
int contains_value(doubly_list* l, int v);
int len(doubly_list* l);
int find_value_index(doubly_list* l, int v);  //! not implemented
int is_empty(doubly_list* l); //! not implemented
void print_all(doubly_list* l); 

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
    newest->denyDuplicate = original->denyDuplicate;
    doubly_node* p = original->first;
    for(;p!=NULL;p=p->next)
        add_last(newest, p->value);

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
doubly_node* find_doubly_node(doubly_list* l, int v){
    doubly_node* p;
    p = l->first;
    while(p != NULL)
    {
        if(v == p->value)
            return p;
        p = p->next;
    }
    return NULL;
}
int add_last(doubly_list* l, int v){
    if(l->denyDuplicate && contains_value(l, v))
        return 0;

    doubly_node* p = newdoubly_node(v);
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
int add_first(doubly_list* l, int v){

    doubly_node* p = newdoubly_node(v);
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
int remove_value(doubly_list* l, int v){
    doubly_node* p;
    int size = len(l);
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
        return 1;
    }
    if(l->first->value == v)
    {
        p = l->first;
        l->first = p->next;
        l->first->prev = NULL;
        free(p);
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
        return 1;
    }
    return 0;
}
int contains_value(doubly_list* l, int v){
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
int len(doubly_list* l){
    doubly_node* p = l->first;
    int len = 1;
    for(; p->next != NULL; len++)
        p = p->next;
    return len;
}
void print_all(doubly_list* l){
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
