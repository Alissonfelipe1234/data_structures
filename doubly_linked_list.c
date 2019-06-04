#include<stdio.h>
#include<stdlib.h>

/*
please include '#include "doubly_linked_list.c"' in your code
*/

typedef struct _node
{
    int value;
    struct _node *next;
    struct _node *prev;
} Node;
extern Node root_node;

typedef struct _list
{
    Node *first;
    Node *last;
    int denyDuplicate;
} List;
extern List root_list;

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

    p->prev = l->last;
    l->last->next = p;
    l->last = p;
    return 1;
}
int addFirst(List* l, int v){

    Node* p = newNode(v);
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
