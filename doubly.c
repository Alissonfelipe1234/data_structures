#include<stdio.h>
#include<stdlib.h>
/*
please include '#include "doubly.c"' in your code
*/

typedef struct _no
{
    int valor;
    struct _no *pos;
    struct _no *pre;
} No;

typedef struct _lista
{
    No *atual;
} Lista;

Lista* newList(){
    return (Lista*) calloc(1, sizeof(Lista));
}
No* newNode(int valor){
    No* retorno = (No*) calloc(1, sizeof(No));
    retorno->valor = valor;
    return retorno;
}
No* newNodeProx(int valor, No* prox){
    No* retorno = (No*) calloc(1, sizeof(No));
    retorno->valor = valor;
    retorno->pos = prox;
    return retorno;
}

int addAfterCurrent(Lista* l, int valor){
    if(l->atual == NULL)
    {
        l->atual = newNode(valor);
        l->atual->pos = l->atual;
        l->atual->pre = l->atual;
        return 1;
    }
    if(&l->atual == &l->atual->pos && &l->atual == &l->atual->pre)
    {
        l->atual->pos = newNode(valor);
        l->atual->pre = l->atual->pos;
        l->atual->pos->pre = l->atual;
        l->atual->pre->pos = l->atual;
        l->atual = l->atual->pos;
        return 1;
    }
    l->atual->pos = newNodeProx(valor, l->atual->pos);
    l->atual->pos->pre = l->atual;
    l->atual->pos->pos->pre = l->atual->pos;
}

void printAll(Lista* l)
{
    if(l->atual == NULL)
    {
        printf("[NULL]\n");
        return;
    }
    No* ultimo = l->atual;
    l->atual = l->atual->pos;
    printf("[");
    while (l->atual != ultimo)
    {
        printf("%i, ", l->atual->valor);
        l->atual = l->atual->pos;
    }
    printf("%i]\n", l->atual->valor);
    printf("atual � o ultimo elemento");
}
