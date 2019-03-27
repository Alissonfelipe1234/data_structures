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


int containsValue(List* l, int v);
int findValue(List* l, int v);
int len(List* l);
int isEmpty(List* l);



void printAll(List* l);

int allowRepeat(List* l);
int denyRepeat(List* l);
int containsRepeatedNode(List* l);


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
int existeValor(Lista* l, int v)
{
    No* p;
    p = l->primeiro;
    while(p != NULL)
    {
        if(v == p->value)
            return 1;
        p = p->prox;
    }
    return 0;
}

int quantidadeElementos(Lista* l)
{
    No* p = l->primeiro;
    int i = 1;
    for (;p->prox != NULL; i++)
        p = p->prox;

    return i;
}
int vazio(Lista* l)
{
    return l->primeiro == NULL;
}
Lista* ConcatenarLista(Lista* L1, Lista* L2)
{
    L1->ultimo->prox = L2->primeiro;
    L1->ultimo = L2->ultimo;
    free(L2);
    return L1;
}

No* buscarElemento(Lista* l, int v)//Não ordenado!
{
    No* p = l->primeiro;
    while (p != NULL)
    {
        if(p->value == v)
            return p;
        p = p->prox;
    }
}


int main()
{
    Lista *L = criarLista();
    adicionarInicio(L, 1);
    adicionarFim(L, 2);
    adicionarInicio(L, 3);
    adicionarInicio(L, 7);
    adicionarInicio(L, 52);
    adicionarInicio(L, 8);
    adicionarInicio(L, 8);
    removerTodos(L, 8);
    Lista *N = OrdenarLista(L);
    printAll(N);

}
