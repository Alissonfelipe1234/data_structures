/*
please include '#include "linked_list.c"' in your code
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

typedef struct _linked_node
{
    int value;
    struct _linked_node *next;
} linked_node;

typedef struct _linked_list
{
    linked_node *first;
    linked_node *last;
    int denyDuplicate;
} linked_list;

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
linked_list* newlinked_list();
linked_list* clonelinked_list(linked_list* original);
linked_list* sortlinked_list(linked_list* l);
linked_node* newlinked_node_empty();
linked_node* newlinked_node(int v);
linked_node* find_linked_node(linked_list* l, int v);
int add_last(linked_list* l, int v);
int add_first(linked_list* l, int v);
int add_in_order(linked_list* l, int v);
int remove_value(linked_list* l, int v);
int remove_all_values(linked_list* l, int v);
int contains_value(linked_list* l, int v);
int len(linked_list* l);
int find_value_index(linked_list* l, int v);
int is_empty(linked_list* l);
void print_all(linked_list* l);
int contains_repeated_linked_node(linked_list* l);
int allow_repeat(linked_list* l);
int deny_repeat(linked_list* l);

//===================================
//                                   
//   ####   #####   ####    #####  
//  ##     ##   ##  ##  ##  ##     
//  ##     ##   ##  ##  ##  #####  
//  ##     ##   ##  ##  ##  ##     
//   ####   #####   ####    #####  
//                                   
//===================================

linked_list* newlinked_list(){
    return (linked_list*) calloc (1, sizeof(linked_list));
}
linked_list* clonelinked_list(linked_list* original){
    linked_list* newest = newlinked_list();
    newest->denyDuplicate = original->denyDuplicate;
    linked_node* p = original->first;
    for(;p!=NULL;p=p->next)
        add_last(newest, p->value);
    return newest;
}
linked_list* sortlinked_list(linked_list* l){
    linked_node* p = l->first;
    linked_list* newest = newlinked_list();
    while(p!= NULL)
    {
        add_in_order(newest, p->value);
        p = p->next;
    }
    return newest;
}
linked_node* newlinked_node_empty(){
    return (linked_node*) calloc (1, sizeof(linked_node));
}
linked_node* newlinked_node(int v){
    linked_node* ret = newlinked_node_empty();
    ret->value = v;
    return ret;
}
linked_node* find_linked_node(linked_list* l, int v){
    linked_node* p;
    p = l->first;
    while(p != NULL)
    {
        if(v == p->value)
            return p;
        p = p->next;
    }
    return NULL;
}
int add_last(linked_list* l, int v){
    if(l->denyDuplicate && contains_value(l, v))
        return 0;
    linked_node* p = newlinked_node(v);
    if(l->first == NULL)
    {
        l->first = p;
        l->last = p;
        return 1;
    }

    l->last->next = p;
    l->last = p;
    return 1;
}
int add_first(linked_list* l, int v){
    if(l->denyDuplicate && contains_value(l, v))
        return 0;
    linked_node* p = newlinked_node(v);
    if(l->first == NULL)
        l->last = p;
    p->next = l->first;
    l->first = p;
    return 1;
}
int add_in_order(linked_list* l, int v){
    if(l->denyDuplicate && contains_value(l, v))
        return 0;
    linked_node* newest = newlinked_node(v);
    if(l->first == NULL)
    {
        l->first = newest;
        l->last = newest;
        return 1;
    }
    if(l->first->value >= v)
    {
        add_first(l, v);
        return 1;
    }
    if(l->last->value <= v)
    {
        add_last(l, v);
        return 1;
    }
    linked_node* p = l->first->next;
    linked_node* prev = l->first;
    while (p->next != NULL)
    {
        if(p->value >= v)
        {
            newest->next = p;
            prev->next = newest;
            return 1;
        }
        prev = p;
        p = p->next;
    }
    return 0;
}
int remove_value(linked_list* l, int v){
    linked_node* p;
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
        free(p);
        return 1;
    }
    linked_node* prev;
    p = l->first->next;
    prev = l->first;
    while (p->next != NULL)
    {
        if(p->value == v)
        {
            prev->next = p->next;
            free(p);
            return 1;
        }
        prev = p;
        p = p->next;
    }
    if(l->last->value == v)
    {
        l->last = prev;
        prev->next = NULL;
        free(p);
        return 1;
    }
    return 0;
}
int remove_all_values(linked_list* l, int v){
    int remove = 0;
    for(;remove_value(l,v);)
        remove = 1;
    return remove;
}
int contains_value(linked_list* l, int v){
    linked_node* p;
    p = l->first;
    while(p != NULL)
    {
        if(v == p->value)
            return 1;
        p = p->next;
    }
    return 0;
}
int len(linked_list* l){
    linked_node* p = l->first;
    int len = 1;
    for(; p->next != NULL; len++)
        p = p->next;
    return len;
}
int find_value_index(linked_list* l, int v){
    if(len(l) <= v)
        return -1;
    linked_node* p = l->first;
    for(int index = 0; index <= v; index++)
        p = p->next;
    return p->value;
}
int is_empty(linked_list* l){
    return l->first == NULL && l->last == NULL;
}
void print_all(linked_list* l){
    linked_node* p = l->first;
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
int contains_repeated_linked_node(linked_list* l){
    linked_node* slower = l->first;
    linked_node* faster = slower->next;
    for(; slower != NULL; slower = slower->next)
        for(faster = slower->next; faster != NULL; faster = faster->next)
            if(slower->value == faster->value)
                return 1;
    return 0;
}
int allow_repeat(linked_list* l){
    l->denyDuplicate = 0;
    return 1;
}
int deny_repeat(linked_list* l){
    if(contains_repeated_linked_node(l))
        return 0;
    l->denyDuplicate = 1;
    return 1;
}
