#include<stdio.h>
#include<stdlib.h>
typedef struct _no
{
    int value;
    struct _no *prox;
} No;

typedef struct _lista
{
    No *primeiro;
    No *ultimo;
    int replicar;
} Lista;

Lista* criarLista()
{
    return (Lista*) calloc (1, sizeof(Lista));
}
No* criarNoVazio()
{
    return (No*) calloc (1, sizeof(No));
}
No* criarNo(int val)
{
    No* retorno = (No*) calloc (1, sizeof(No));
    retorno->value = val;
    return retorno;
}
void adicionarFim(Lista* l, int valor)
{

    if(l->replicar == 1 && existeValor(l, valor) == 1)//apenas usado em listas tipo hash
        return;

    No* p = criarNo(valor);
    if(l->primeiro == NULL)
    {
        l->primeiro = p;
        l->ultimo = p;
    }
    else
    {
        l->ultimo->prox = p;
        l->ultimo = p;
    }
}
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
