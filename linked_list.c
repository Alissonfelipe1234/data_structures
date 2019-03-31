#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"

typedef struct _node
{
    int value;
    struct _node *prox;
} Node;

typedef _list
{
    Node *first;
    Node *last;
    int denyDuplicate;
} List;

List* newList(){
     return (List*) calloc (1, sizeof(List));
}
List* sortList(List* l){
    Node* p = l->primeiro;
    List* newest = newList();
    while(p!= NULL)
    {
        addInOrder(newest, p->value);
        p = p->prox;
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
        p = p->prox;
    }
    return NULL;
}

int addLast(List* l, int v){
    if(l->denyDuplicate && containsValue(l, v))
        return 0;

    Node* p = createNode(v);
    if(l->first == NULL)
    {
        l->first = p;
        l->last = p;
        return 1;
    }

    l->last->prox = p;
    l->last = p;
    return 1;
}
int addFirst(List* l, int v){
    if(l->denyDuplicate && containsValue(l, v))
        return 0;

    Node* p = createNode(v);
    if(l->first == NULL)
        l->last = p;

    p->prox = l->first;
    l->first = p;
    return 1;
}
int addInOrder(List* l, int v){
    if(l->denyDuplicate && containsValue(l, v))
        return 0;

    Node* newest = criarNo(v);
    if(l->first == NULL)
    {
        l->first = newest;
        l->first = newest;
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

    Node* p = l->first->prox;
    Node* prev = l->first;
    while (p->prox != NULL)
    {
        if(p->value >= v)
        {
            newest->prox = p;
            prev->prox = newest;
            return 1;
        }
        prev = p;
        p = p->prox;
    }
    return 0; //it will never be used
}
int removeValue(List* l, int v){
    Node* p;
    if(l->first->value == v)
    {
        p = l->first;
        l->first = p->prox;
        free(p);
        return 1;
    }
    Node* prev;
    p = l->first->prox;
    prev = l->first;
    while (p->prox != NULL)
    {
        if(p->value == v)
        {
            prev->prox = p->prox;
            free(p);
            return 1;
        }
        prev = p;
        p = p->prox;
    }
    if(l->last->value == v)
    {
        l->last = prev;
        prev->prox = NULL;
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
        p = p->prox;
    }
    return 0;
}
int len(List* l){
    Node* p = l->first;
    int len = 1;
    for(; p->prox != NULL; len++)
        p = p->prox;
    return len;
}
int findValueIndex(List* l, int v){
    if(len(l) <= v)
        return NULL;
    Node* p = l->first;
    for(int index = 0; index <= v; index++)
        p = p->prox;
    return p->value;
}
int isEmpty(List* l){
    return l->first == NULL && l->last == NULL;
}

void printAll(List* l){
    Node* p = l->first;
    printf("[");
    for(; p->prox != NULL; len++)
    {
        printf("%i, ", p->value);
        p = p->prox;
    }
    if(l->last == NULL)
    {
        printf("NULL]");
        return;
    }
    printf("%i]", l->last);
}

int containsRepeatedNode(List* l){
    int len = len(l);

    Node* slower = l->first;
    Node* faster = slower->prox;
    for(int slow = 0; slow <= len; slow++)
    {
        for(int fast = 1; fast <= len; fast++)
        {
            if(slower->value == faster->value)
                return 1;
            faster = faster->prox;
        }
        slower = slower->prox;
        faster = slower->prox;
    }
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



void printAll(Lista* l)
{
    No* p = l->primeiro;
    printf("[");

    while(p->prox != NULL)
    {
        printf("%i, ",p->value);
        p = p->prox;
    }
    printf("%i",l->ultimo->value);
    printf("]");
}
void proibirReplica(Lista* l)
{
    if(existeReplica(l) == 1)
        return;
    l->replicar = 1;
}
void permitirReplicar(Lista* l)
{
    l->replicar = 0;
}
/*
int existeReplica(Lista* l)
{
    No* rapido;
    No* lento;
    rapido = l->primeiro;
    lento = l->primeiro;
    while(lento != NULL)
    {
        while(rapido != NULL)
        {
            rapido = rapido->prox;
            if(rapido->value == lento->value)
                return 1;
        }
        lento = lento->prox;
        rapido = lento;
    }
    return 0;
}
*/
int main()
{
}
