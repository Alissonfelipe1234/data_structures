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
} Linked_node;

typedef struct _linked_list
{
    Linked_node *first;
    Linked_node *last;
    int denyDuplicate;
} Linked_list;

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
Linked_list* newLinked_list();
Linked_list* cloneLinked_list(Linked_list* original);
Linked_list* sortLinked_list(Linked_list* l);
Linked_node* newLinked_nodeEmpty();
Linked_node* newLinked_node(int v);
Linked_node* findLinked_node(Linked_list* l, int v);
int addLast(Linked_list* l, int v);
int addFirst(Linked_list* l, int v);
int addInOrder(Linked_list* l, int v);
int removeValue(Linked_list* l, int v);
int removeAllValues(Linked_list* l, int v);
int containsValue(Linked_list* l, int v);
int len(Linked_list* l);
int findValueIndex(Linked_list* l, int v);
int isEmpty(Linked_list* l);
void printAll(Linked_list* l);
int containsRepeatedLinked_node(Linked_list* l);
int allowRepeat(Linked_list* l);
int denyRepeat(Linked_list* l);

//===================================
//                                   
//   ####   #####   ####    #####  
//  ##     ##   ##  ##  ##  ##     
//  ##     ##   ##  ##  ##  #####  
//  ##     ##   ##  ##  ##  ##     
//   ####   #####   ####    #####  
//                                   
//===================================


Linked_list* newLinked_list(){
    return (Linked_list*) calloc (1, sizeof(Linked_list));
}
Linked_list* cloneLinked_list(Linked_list* original){

    Linked_list* newest = newLinked_list();
    newest->denyDuplicate = original->denyDuplicate;
    Linked_node* p = original->first;
    for(;p!=NULL;p=p->next)
        addLast(newest, p->value);

    return newest;
}
Linked_list* sortLinked_list(Linked_list* l){
    Linked_node* p = l->first;
    Linked_list* newest = newLinked_list();

    while(p!= NULL)
    {
        addInOrder(newest, p->value);
        p = p->next;
    }
    return newest;
}

Linked_node* newLinked_nodeEmpty(){
    return (Linked_node*) calloc (1, sizeof(Linked_node));
}
Linked_node* newLinked_node(int v){
    Linked_node* ret = newLinked_nodeEmpty();
    ret->value = v;
    return ret;
}
Linked_node* findLinked_node(Linked_list* l, int v){
    Linked_node* p;
    p = l->first;
    while(p != NULL)
    {
        if(v == p->value)
            return p;
        p = p->next;
    }
    return NULL;
}

int addLast(Linked_list* l, int v){
    if(l->denyDuplicate && containsValue(l, v))
        return 0;

    Linked_node* p = newLinked_node(v);
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
int addFirst(Linked_list* l, int v){
    if(l->denyDuplicate && containsValue(l, v))
        return 0;

    Linked_node* p = newLinked_node(v);
    if(l->first == NULL)
        l->last = p;

    p->next = l->first;
    l->first = p;
    return 1;
}
int addInOrder(Linked_list* l, int v){
    if(l->denyDuplicate && containsValue(l, v))
        return 0;

    Linked_node* newest = newLinked_node(v);
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

    Linked_node* p = l->first->next;
    Linked_node* prev = l->first;
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
int removeValue(Linked_list* l, int v){
    Linked_node* p;
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
    Linked_node* prev;
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
int removeAllValues(Linked_list* l, int v){
    int remove = 0;
    for(;removeValue(l,v);)
        remove = 1;
    return remove;
}


int containsValue(Linked_list* l, int v){
    Linked_node* p;
    p = l->first;
    while(p != NULL)
    {
        if(v == p->value)
            return 1;
        p = p->next;
    }
    return 0;
}
int len(Linked_list* l){
    Linked_node* p = l->first;
    int len = 1;
    for(; p->next != NULL; len++)
        p = p->next;
    return len;
}
int findValueIndex(Linked_list* l, int v){
    if(len(l) <= v)
        return -1;
    Linked_node* p = l->first;
    for(int index = 0; index <= v; index++)
        p = p->next;
    return p->value;
}
int isEmpty(Linked_list* l){
    return l->first == NULL && l->last == NULL;
}

void printAll(Linked_list* l){
    Linked_node* p = l->first;
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

int containsRepeatedLinked_node(Linked_list* l){
    Linked_node* slower = l->first;
    Linked_node* faster = slower->next;
    for(; slower != NULL; slower = slower->next)
        for(faster = slower->next; faster != NULL; faster = faster->next)
            if(slower->value == faster->value)
                return 1;
    return 0;
}
int allowRepeat(Linked_list* l)
{
    l->denyDuplicate = 0;
    return 1;
}
int denyRepeat(Linked_list* l){
    if(containsRepeatedLinked_node(l))
        return 0;
    l->denyDuplicate = 1;
    return 1;
}
