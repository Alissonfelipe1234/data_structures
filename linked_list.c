#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"
/*
please include '#include "linked_list.c"' in your code
*/
typedef struct _node
{
    int value;
    struct _node *next;
} Node;

typedef struct _list
{
    Node *first;
    Node *last;
    int denyDuplicate;
} List;

List* newList(){
    return (List*) calloc (1, sizeof(List));
}
List* cloneList(List* original){

    List* newest = newList();
    newest->denyDuplicate = original->denyDuplicate;
    Node* p = original->first;
    for(;p!=NULL;p=p->next)
        addLast(newest, p->value);

    return newest;
}
List* sortList(List* l){
    Node* p = l->first;
    List* newest = newList();

    while(p!= NULL)
    {
        addInOrder(newest, p->value);
        p = p->next;
    }
    return newest;
}

Node* newNodeEmpty(){
    return (Node*) calloc (1, sizeof(Node));
}
Node* newNode(int v){
    Node* ret = newNodeEmpty();
    ret->value = v;
    return ret;
}
Node* findNode(List* l, int v){
    Node* p;
    p = l->first;
    while(p != NULL)
    {
        if(v == p->value)
            return p;
        p = p->next;
    }
    return NULL;
}

int addLast(List* l, int v){
    if(l->denyDuplicate && containsValue(l, v))
        return 0;

    Node* p = newNode(v);
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
int addFirst(List* l, int v){
    if(l->denyDuplicate && containsValue(l, v))
        return 0;

    Node* p = newNode(v);
    if(l->first == NULL)
        l->last = p;

    p->next = l->first;
    l->first = p;
    return 1;
}
int addInOrder(List* l, int v){
    if(l->denyDuplicate && containsValue(l, v))
        return 0;

    Node* newest = newNode(v);
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

    Node* p = l->first->next;
    Node* prev = l->first;
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
    return 0; //it will never be used
}
int removeValue(List* l, int v){
    Node* p;
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
    Node* prev;
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
int removeAllValues(List* l, int v){
    int remove = 0;
    for(;removeValue(l,v);)
        remove = 1;
    return remove;
}


int containsValue(List* l, int v){
    Node* p;
    p = l->first;
    while(p != NULL)
    {
        if(v == p->value)
            return 1;
        p = p->next;
    }
    return 0;
}
int len(List* l){
    Node* p = l->first;
    int len = 1;
    for(; p->next != NULL; len++)
        p = p->next;
    return len;
}
int findValueIndex(List* l, int v){
    if(len(l) <= v)
        return NULL;
    Node* p = l->first;
    for(int index = 0; index <= v; index++)
        p = p->next;
    return p->value;
}
int isEmpty(List* l){
    return l->first == NULL && l->last == NULL;
}

void printAll(List* l){
    Node* p = l->first;
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

int containsRepeatedNode(List* l){
    Node* slower = l->first;
    Node* faster = slower->next;
    for(; slower != NULL; slower = slower->next)
        for(faster = slower->next; faster != NULL; faster = faster->next)
            if(slower->value == faster->value)
                return 1;
    return 0;
}
int allowRepeat(List* l)
{
    l->denyDuplicate = 0;
    return 1;
}
int denyRepeat(List* l){
    if(containsRepeatedNode(l))
        return 0;
    l->denyDuplicate = 1;
    return 1;
}
