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
    int size;
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
linked_list* sort_linked_list(linked_list* l);
linked_node* newlinked_node_empty();
linked_node* newlinked_node(int v);
linked_node* find_linked_node(linked_list* l, int v);
linked_node* indexof_linked(linked_list* l, int x);
int add_last_linked(linked_list* l, int v);
int add_first_linked(linked_list* l, int v);
int add_in_order_linked(linked_list* l, int v);
int remove_linked_value(linked_list* l, int v);
int remove_all_linked_value(linked_list* l, int v);
int contains_linked_value(linked_list* l, int v);
int ordened_search_linked_value(linked_list* l, int v);
int linked_len(linked_list* l);
int is_linked_empty(linked_list* l);
void print_linked(linked_list* l);
int contains_repeated_linked_node(linked_list* l);

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
    newest->size = original->size;
    linked_node* p = original->first;
    for(;p!=NULL;p=p->next)
        add_last_linked(newest, p->value);
    return newest;
}
linked_list* sort_linked_list(linked_list* l){
    linked_node* p = l->first;
    linked_list* newest = newlinked_list();
    while(p!= NULL)
    {
        add_in_order_linked(newest, p->value);
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
linked_node* indexof_linked(linked_list* l, int x){
    linked_node* p = l->first;
    for (int i = 0; i < x; i++)
        p = p->next;
    return p;
}
int add_last_linked(linked_list* l, int v){
    l->size++;
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
int add_first_linked(linked_list* l, int v){
    l->size++;
    linked_node* p = newlinked_node(v);
    if(l->first == NULL)
        l->last = p;
    p->next = l->first;
    l->first = p;
    return 1;
}
int add_in_order_linked(linked_list* l, int v){
    linked_node* newest = newlinked_node(v);
    if(l->first == NULL)
    {
        l->first = newest;
        l->last = newest;
        l->size++;
        return 1;
    }
    if(l->first->value >= v)
        return add_first_linked(l, v);
    if(l->last->value <= v)
        return add_last_linked(l, v);

    linked_node* p = l->first->next;
    linked_node* prev = l->first;
    while (p != NULL)
    {
        if(p->value > v)
        {
            newest->next = p;
            prev->next = newest;
            l->size++;
            return 1;
        }
        prev = p;
        p = p->next;
    }
    printf("ERROR IT ISN'T A NUMBER: %d, \n", v);
    return 0;
}
int remove_linked_value(linked_list* l, int v){
    linked_node* p;
    int size = linked_len(l);
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
        free(p);
        l->size--;
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
            l->size--;
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
        l->size--;
        return 1;
    }
    return 0;
}
int remove_all_linked_value(linked_list* l, int v){
    int remove = 0;
    for(;remove_linked_value(l,v);)
        remove = 1;
    return remove;
}
int index_linked_value(linked_list * l, int index){
    linked_node* p = l->first;
    for(register int i = 0; i < index; i++)
        p = p->next;
    return p->value;   
}
int contains_linked_value(linked_list* l, int v){
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
int ordened_search_linked_value(linked_list* l, int v){
    if(l->first->value > v || l->last->value < v)
        return 0;
    linked_node* p;
    p = l->first;
    while(p != NULL)
    {
        if(v == p->value)
            return 1;
        if(v > p->value)
            return 0;
        p = p->next;
    }
    return 0; 
}
int binary_search_linked_value(linked_list* l, int v){
    if(l->size = 0)
        return 0;
    int low, max, mean;
    low = 0;
    max = l->size;
    mean = max/2;
    while(low <= max && low > 0 && max < l->size)
    {
        int actual = index_linked_value(l, mean);
        if(actual == v)
            return 1;
        if(actual < v)
            low = mean + 1;
        else
            max = mean - 1;
        mean = (max - low)/2;
    }
    return 0;    
}
int linked_len(linked_list* l){
    return l->size;
}
int is_linked_empty(linked_list* l){
    return l->first == NULL && l->last == NULL;
}
void print_linked(linked_list* l){
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