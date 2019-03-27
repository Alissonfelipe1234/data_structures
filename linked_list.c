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
List* sortList(List* l);

Node* newNodeEmpty();
{
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

    No* p = createNode(v);
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
int addFirst(List* l, int v)
{
    if(l->denyDuplicate && containsValue(l, v))
        return 0;

    No* p = createNode(v);
    if(l->primeiro == NULL)
        l->ultimo = p;

    p->prox = l->primeiro;
    l->primeiro = p;
    return 1;
}
int removeValue(List* l, int v);
int removeAllValues(List* l, int v);


int addInOrder(List* l, int v);
int containsValue(List* l, int v);
int findValue(List* l, int v);
int len(List* l);
int isEmpty(List* l);



void printAll(List* l);

int allowRepeat(List* l);
int denyRepeat(List* l);
int containsRepeatedNode(List* l);


void adicionarInicio(Lista* l, int valor)
{
    if(l->replicar == 1 && existeValor(l, valor) == 1)//apenas usado em listas tipo hash
        return;

    No* p = criarNo(valor);

    if(l->primeiro == NULL)
        l->ultimo = p;

    p->prox = l->primeiro;
    l->primeiro = p;
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
int remover(Lista* l, int v) //remove apenas o primeiro elemento achado
{
    No* p;
    No* ant;
    if(l->primeiro->value == v)
    {
        p = l->primeiro;
        l->primeiro = p->prox;
        free(p);
        return 1;
    }
    p = l->primeiro->prox;
    ant = l->primeiro;
    while (p->prox != NULL)
    {
        if(p->value == v)
        {
            ant->prox = p->prox;
            free(p);
            return 1;
        }
        ant = p;
        p = p->prox;
    }
    if(l->ultimo->value == v)
    {
        l->ultimo = ant;
        ant->prox = NULL;
        free(p);
        return 1;
    }
    return 0;
}
void removerTodos(Lista* l, int v) //remove todos os elementos
{
    int remove = 1;
    while (remove == 1)
    {
        remove = remover(l, v);
    }
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

No* buscarElemento(Lista* l, int v)//N�o ordenado!
{
    No* p = l->primeiro;
    while (p != NULL)
    {
        if(p->value == v)
            return p;
        p = p->prox;
    }
}

Lista* OrdenarLista(Lista* l)
{
    No* p = l->primeiro;
    Lista* nova = criarLista();
    while(p!= NULL)
    {
        inserirOrdenado(nova, p->value);
        p = p->prox;
    }
    return nova;
}
void inserirOrdenado(Lista* l, int v)
{
    No* novo = criarNo(v);
    if(l->primeiro == NULL)
    {
        l->primeiro = novo;
        l->ultimo = novo;
        return;
    }
    if(l->primeiro->value >= v)
    {
        adicionarInicio(l, v);
        return;
    }
    if(l->ultimo->value <= v)
    {
        adicionarFim(l, v);
        return;
    }

    No* p = l->primeiro->prox;
    No* ant = l->primeiro;
    while (p->prox != NULL)
    {
        if(p->value >= v)
        {
            novo->prox = p;
            ant->prox = novo;
            return;
        }
        ant = p;
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
