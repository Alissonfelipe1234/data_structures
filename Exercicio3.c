#include <stdio.h>
#include <stdlib.h>

typedef struct _no
{
    int val;
    struct _no* esq;
    struct _no* dir;
}No;

typedef struct _arv
{
    No* raiz;
}Arv;

///Cabecalhos

Arv* criarArvore();
No* criarNo(int valor);
void imprimeInOrder(Arv* arvore);
void imprimeInOrderRecursivo(No* galho);
void imprimeInPosOrder(Arv* arvore);
void imprimeInPosOrderRecursivo(No* galho);
int insereNo(Arv* arvore, int valor);
int insereNoRecursivo(No* galho, int valor);
int excluirNO(Arv* arvore, int valor);
int removerRaiz(Arv* arvore);
int removerNo(No* galho, int valor, No* anterior, int direcao);
int removerAqui(No* anterior, No* galho, int direcao);
void destroirArv(Arv** arvore);
void destroirNos(No* galho);
void alturaArv(Arv* arvore);
int alturaNo(No* galho, int atual);
int max(register int x, register int y);
void inverteArv(Arv* arvore);
void inverterNos(No* galho);


//códigos

Arv* criarArvore(){
    return (Arv*) calloc(1, sizeof(Arv));
}
No* criarNo(int valor){
    No* novo = (No*) calloc(1, sizeof(No));
    novo->val = valor;
    return novo;
}
void imprimeInOrder(Arv* arvore){
    if(arvore == NULL)
        printf("Arvore Vazia");
    imprimeInOrderRecursivo(arvore->raiz);
}
void imprimeInOrderRecursivo(No* galho){
    if(galho == NULL)
        return;
    imprimeInOrderRecursivo(galho->esq);
    printf("%i ", galho->val);
    imprimeInOrderRecursivo(galho->dir);
}
void imprimeInPOsOrder(Arv* arvore){
    if(arvore == NULL)
        printf("Arvore Vazia");
    imprimeInPosOrderRecursivo(arvore->raiz);
}
void imprimeInPosOrderRecursivo(No* galho){
    if(galho == NULL)
        return;
    imprimeInPosOrderRecursivo(galho->esq);
    imprimeInPosOrderRecursivo(galho->dir);
    printf("%i ", galho->val);
}
int insereNo(Arv* arvore, int valor){
    if(arvore->raiz == NULL){
        arvore->raiz = criarNo(valor);
        return 1;
    }
    return insereNoRecursivo(arvore->raiz, valor);
}
int insereNoRecursivo(No* galho, int valor){
    if(galho == NULL)
        return 0;
    if(galho->val < valor)
        return galho->dir == NULL? galho->dir = criarNo(valor), 1: insereNoRecursivo(galho->dir, valor);
    else
        return galho->esq == NULL? galho->esq = criarNo(valor), 1: insereNoRecursivo(galho->esq, valor);
}
int excluirNO(Arv* arvore, int valor){
    if(arvore == NULL)
        return 0;
    if(arvore->raiz->val == valor)
    {
        removerRaiz(arvore);
        return 1;
    }

    return removerNo(arvore->raiz, valor, NULL, -1);
}
int removerRaiz(Arv* arvore){
    if(arvore == NULL || arvore->raiz == NULL)
        return 0;
    if(arvore->raiz->dir == NULL && arvore->raiz->esq == NULL)
    {
        free(arvore->raiz);
        arvore->raiz = NULL;
        return 1;
    }
    No* aux;
    if(arvore->raiz->dir == NULL)
    {
        aux = arvore->raiz;
        arvore->raiz = arvore->raiz->esq;
        aux->esq = NULL;
        free(aux);
        return 1;
    }
    if(arvore->raiz->esq == NULL)
    {
        aux = arvore->raiz;
        arvore->raiz = arvore->raiz->dir;
        aux->dir = NULL;
        free(aux);
        return 1;
    }
    aux = arvore->raiz->dir;
    while (aux->esq != NULL)
    {
        aux = aux->esq;
    }
    int folhaMorta = aux->val;
    removerNo(arvore->raiz, folhaMorta, NULL, -1);
    arvore->raiz->val = folhaMorta;
    return 1;
}
int removerNo(No* galho, int valor, No* anterior, int direcao){
    if(galho == NULL)
        return 0;
    if(galho->val ==valor)
        return removerAqui(anterior, galho, direcao);
    if(galho->val < valor)
        return removerNo(galho->dir, valor, galho, 1);
    else
        return removerNo(galho->esq, valor, galho, 0);
}
int removerAqui(No* anterior, No* galho, int direcao){
    if(galho->dir == NULL && galho->esq == NULL)
    {
        free(galho);
        if(direcao == 1)
            anterior->dir = NULL;
        else
            anterior->esq = NULL;
        return 1;
    }
    No* aux;
    if(galho->dir == NULL)
    {
        aux = galho;
        if(direcao == 1)
            anterior->dir = galho->esq;
        else
            anterior->esq = galho->esq;
        galho = galho->esq;
        aux->esq = NULL;
        free(aux);
        return 1;
    }
    if(galho->esq == NULL)
    {
        aux = galho;
        if(direcao == 1)
            anterior->dir = galho->dir;
        else
            anterior->esq = galho->dir;
        galho = galho->dir;
        aux->dir = NULL;
        free(aux);
        return 1;
    }
    aux = galho->dir;
    while (aux->esq != NULL)
    {
        aux = aux->esq;
    }
    aux->esq = galho->esq;
    if(direcao == 1)
    {
        anterior->dir->esq = NULL;
        anterior->dir = anterior->dir->dir;
    }
    else
    {
        anterior->esq->esq = NULL;
        anterior->esq = anterior->esq->dir;
    }     
    free(galho);
    return 1;
}
void destroirArv(Arv** arvore){
    if(*arvore == NULL)
        return;
    destroirNos((*arvore)->raiz);
    free(*arvore);
    *arvore = NULL;
    arvore = NULL;
}
void destroirNos(No* galho)
{
    if(galho == NULL)
        return;
    destroirNos(galho->esq);
    destroirNos(galho->esq);
    free(galho);
}
void alturaArv(Arv* arvore){
    if(arvore == NULL)
        printf("Altura: 0");
    else
        printf("Altura: %i", alturaNo(arvore->raiz, 1));
}
int alturaNo(No* galho, int atual){
    if(galho == NULL)
        return 0;
    return 1 + max(alturaNo(galho->esq, atual+1), alturaNo(galho->dir, atual+1));
}
int max(register int x, register int y){
    return x>y? x: y;
}
void inverteArv(Arv* arvore){
    if(arvore == NULL)
        return;
    inverterNos(arvore->raiz);
}
void inverterNos(No* galho){
    if(galho == NULL)
        return;

    No* aux = galho->dir;
    galho->dir = galho->esq;
    galho->esq = aux;
    inverterNos(galho->dir);
    inverterNos(galho->esq);
}