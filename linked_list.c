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
linked_node* newlinked_nodeEmpty();
linked_node* newlinked_node(int v);
linked_node* findlinked_node(linked_list* l, int v);
int addLast(linked_list* l, int v);
int addFirst(linked_list* l, int v);
int addInOrder(linked_list* l, int v);
int removeValue(linked_list* l, int v);
int removeAllValues(linked_list* l, int v);
int containsValue(linked_list* l, int v);
int len(linked_list* l);
int findValueIndex(linked_list* l, int v);
int isEmpty(linked_list* l);
void printAll(linked_list* l);
int containsRepeatedlinked_node(linked_list* l);
int allowRepeat(linked_list* l);
int denyRepeat(linked_list* l);

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
        addLast(newest, p->value);
    return newest;
}
linked_list* sortlinked_list(linked_list* l){
    linked_node* p = l->first;
    linked_list* newest = newlinked_list();
    while(p!= NULL)
    {
        addInOrder(newest, p->value);
        p = p->next;
    }
    return newest;
}
linked_node* newlinked_nodeEmpty(){
    return (linked_node*) calloc (1, sizeof(linked_node));
}
linked_node* newlinked_node(int v){
    linked_node* ret = newlinked_nodeEmpty();
    ret->value = v;
    return ret;
}
linked_node* findlinked_node(linked_list* l, int v){
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
int addLast(linked_list* l, int v){
    if(l->denyDuplicate && containsValue(l, v))
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
int addFirst(linked_list* l, int v){
    if(l->denyDuplicate && containsValue(l, v))
        return 0;
    linked_node* p = newlinked_node(v);
    if(l->first == NULL)
        l->last = p;
    p->next = l->first;
    l->first = p;
    return 1;
}
int addInOrder(linked_list* l, int v){
    if(l->denyDuplicate && containsValue(l, v))
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
        addFirst(l, v);
        return 1;
    }
    if(l->last->value <= v)
    {
        addLast(l, v);
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
int removeValue(linked_list* l, int v){
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
int removeAllValues(linked_list* l, int v){
    int remove = 0;
    for(;removeValue(l,v);)
        remove = 1;
    return remove;
}
int containsValue(linked_list* l, int v){
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
int findValueIndex(linked_list* l, int v){
    if(len(l) <= v)
        return -1;
    linked_node* p = l->first;
    for(int index = 0; index <= v; index++)
        p = p->next;
    return p->value;
}
int isEmpty(linked_list* l){
    return l->first == NULL && l->last == NULL;
}
void printAll(linked_list* l){
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
int containsRepeatedlinked_node(linked_list* l){
    linked_node* slower = l->first;
    linked_node* faster = slower->next;
    for(; slower != NULL; slower = slower->next)
        for(faster = slower->next; faster != NULL; faster = faster->next)
            if(slower->value == faster->value)
                return 1;
    return 0;
}
int allowRepeat(linked_list* l){
    l->denyDuplicate = 0;
    return 1;
}
int denyRepeat(linked_list* l){
    if(containsRepeatedlinked_node(l))
        return 0;
    l->denyDuplicate = 1;
    return 1;
}
