#include<stdio.h>
#include<stdlib.h>

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

Lista* novaLista(){
    return (Lista*) calloc(1, sizeof(Lista));
}
No* novoNo(int valor){
    No* retorno = (No*) calloc(1, sizeof(No));
    retorno->valor = valor;
    return retorno;
}
No* novoNoProx(int valor, No* prox){
    No* retorno = (No*) calloc(1, sizeof(No));
    retorno->valor = valor;
    retorno->pos = prox;
    return retorno;
}

int adicionarDepoisDoAtual(Lista* l, int valor){
    if(l->atual == NULL)
    {
        l->atual = novoNo(valor);
        l->atual->pos = l->atual;
        l->atual->pre = l->atual;
        return 1;
    }
    if(&l->atual == &l->atual->pos && &l->atual == &l->atual->pre)
    {
        l->atual->pos = novoNo(valor);
        l->atual->pre = l->atual->pos;
        l->atual->pos->pre = l->atual;
        l->atual->pre->pos = l->atual;
        l->atual = l->atual->pos;
        return 1;
    }
    l->atual->pos = novoNoProx(valor, l->atual->pos);
    l->atual->pos->pre = l->atual;
    l->atual->pos->pos->pre = l->atual->pos;
}
/*
int adicionarAntesDoAtual(Lista* l, int valor){
    if(l->atual == NULL)
    {
        l->atual = novoNo(valor);
        return 1;
    }
}
*/

void printarTodos(Lista* l)
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
    printf("atual é o ultimo elemento");
}

int main(){
    Lista* l = novaLista();
    printarTodos(l);
    adicionarDepoisDoAtual(l, 1);
    adicionarDepoisDoAtual(l, 2);
    adicionarDepoisDoAtual(l, 3);
    adicionarDepoisDoAtual(l, 4);
    adicionarDepoisDoAtual(l, 4);
    printarTodos(l);
}

