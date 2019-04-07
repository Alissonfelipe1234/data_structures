#include<stdio.h>
#include<stdlib.h>

typedef struct _no {
 int val;
 struct _no *prox;
} No;

typedef struct _lista {
 No *inicio;
 No *fim;
 int tamanho; //adicionado para otimizar o contador de nós
} Lista;

Lista* novaLista(){
    return (Lista*) calloc(1, sizeof(Lista));
}
No* novoNoVazio(){
    return (No*) calloc(1, sizeof(No));
}
No* novoNo(int valor){
    No* novo = novoNoVazio();
    novo->val = valor;
    return novo;
}
/**
Todas as funções retornam 1 para casos de sucesso e 0 para erro ou inválido
*/
int insereInicio(Lista* l, int valor)
{
    if(l == NULL)
        return 0;
    l->tamanho++; //otimização do contador de nós
    No* novo = novoNo(valor);
    if(l->inicio == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
        return 1;
    }
    novo->prox = l->inicio;
    l->inicio = novo;
    return 1;
}
int insereFim(Lista* l, int valor)
{
    if(l == NULL)
        return 0;
    l->tamanho++; //otimização do contador de nós
    No* novo = novoNo(valor);
    if(l->inicio == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
        return 1;
    }
    l->fim->prox = novo;
    l->fim = novo;
    return 1;
}
int insereOrdenado(Lista*l, int valor){
    if(l == NULL)
        return 0;
    l->tamanho++; //otimização do contador de nós
    No* novo = novoNo(valor);
    if(l->inicio == NULL || l->inicio->val > valor)
    {
        return insereInicio(l, valor);
    }
    No* aux = l->inicio;
    No* ponteiro = aux->prox;
    while(ponteiro != NULL)
    {
        if(ponteiro->val > valor)
        {
            novo->prox = ponteiro;
            aux->prox = novo;
            return 1;
        }
        aux = aux->prox;
        ponteiro = aux->prox;
    }
    l->fim->prox = novo;
    l->fim = novo;
    return 1;
}
int removePrimeiro(Lista* l){
    if(l == NULL || l->inicio == NULL)
        return 0;
    if(l->tamanho == 1)
    {
        l->inicio = NULL;
        l->fim = NULL;
        l->tamanho--;
        return 1;
    }
    No* primeiro = l->inicio;
    l->inicio = l->inicio->prox;
    free(primeiro);
    l->tamanho--; //otimização do contador de nós
    return 1;

}
int removeUltimo(Lista* l){
    if(l == NULL || l->inicio == NULL)
        return 0;
    if(l->tamanho == 1)
    {
        l->inicio = NULL;
        l->fim = NULL;
        return 1;
    }
    No* ultimo = l->fim;
    No* aux = l->inicio;
    while(aux->prox->prox != NULL)
    {
        aux = aux->prox;
    }
    aux->prox = NULL;
    l->fim = aux;
    free(ultimo);
    l->tamanho--; //otimização do contador de nós
    return 1;
}
int removeImpares(Lista* l){
    if(tam(l) < 1)
        return 0;
    No* inicio = l->inicio;
    removeuInicio:
    if(l->inicio->val%2!=0){//diferente de 0 pois pode ser 1 ou -1
        inicio = l->inicio;
        l->inicio = inicio->prox;
        free(inicio);
        l->tamanho--; //otimização do contador de nós
        goto removeuInicio;
    }
    No* aux = l->inicio;
    No* ponteiro = aux->prox;
    while(ponteiro->prox!=NULL)
    {
        if(ponteiro->val%2 != 0)//pode ser 1 ou -1
        {
            aux->prox = ponteiro->prox;
            No* apagar = ponteiro;
            free(apagar);
            ponteiro = aux->prox;
            l->tamanho--; //otimização do contador de nós
            continue;
        }
        aux = aux->prox;
        ponteiro = aux->prox;
    }
    if(l->fim->val%2 != 0)//pode ser 1 ou -1
    {
        aux->prox = NULL;
        No* fim = l->fim;
        l->fim = aux;
        free(fim);
        l->tamanho--; //otimização do contador de nós
    }
    return 1;
}
Lista *ConcatenaListas(Lista *L1, Lista *L2){
    if(L1 == NULL || L2 == NULL)
        return NULL;
    Lista* retorno = novaLista();
    No* p = L1->inicio;
    while(p!=NULL)
    {
        insereFim(retorno, p->val);
        p = p->prox;
    }
    p = L2->inicio;
    while(p!=NULL)
    {
        insereFim(retorno, p->val);
        p = p->prox;
    }
    return retorno;
}
int tam(Lista* l)
{
    if(l == NULL)
        return -1;
    return l->tamanho;
    /**Maneira mais ineficiente*/
    /*
    No* ponteiro = l->inicio;
    int i = 0;
    for (;ponteiro != NULL; i++)
        ponteiro = ponteiro->prox;
    return i;
    */
}
int inverterLista(Lista* l){
    if(l == NULL)
        return 0;
    Lista* nova = novaLista();
    while(l->inicio != NULL)
    {
        insereInicio(nova, l->inicio->val);
        removePrimeiro(l);
    }
    l->inicio = nova->inicio;
    l->fim = nova->fim;
    return 1;
}
Lista *CopiaVetor(int *vet, int n){
    Lista* nova = novaLista();
    for (int i = n-1; i >= 0; i--)
        insereInicio(nova, vet[i]);
    return nova;
}
/**
12. Não precisamos usar Lista** L
*/
void DestroiLista(Lista *L){
    if(L == NULL)
        return;
    while(L->tamanho > 0)
        removePrimeiro(L);
    L = NULL;
}
void DivideListaAoMeio(Lista *L, Lista **L1, Lista **L2){
    int primeiro, segundo;
    primeiro = tam(L)/2;
    if(L->tamanho%2 == 1) //Só pode ser 1 pois não existe lista com tamanho negativo
        primeiro++;
    segundo = tam(L)/2;
    DestroiLista(*L1);
    DestroiLista(*L2);
    *L1 = novaLista();
    *L2 = novaLista();
    No* p = L->inicio;
    for(int i = 0; i < primeiro; i++)
    {
        insereFim(*L1, p->val);
        p = p->prox;
    }
     for(int i = 0; i < segundo; i++)
    {
        insereFim(*L2, p->val);
        p = p->prox;
    }
}
Lista* copiarLista(Lista* l){
    Lista* ret = novaLista();
    No* p = l->inicio;
    while(p!= NULL)
    {
        insereFim(ret, p->val);
        p = p->prox;
    }
    return ret;
}
Lista* copiarElementos(Lista* l, int n)
{
    if(l->tamanho < n)
        return copiarLista(l);
    Lista* ret = novaLista();
    No* p = l->inicio;
    int i = 0;
    while(i < n)
    {
        insereFim(ret, p->val);
        p = p->prox;
        i++;
    }
    return ret;
}


void imprimirLista(Lista* l)
{
    printf("[");
    if(l == NULL)
    {
        printf("NULL]\n");
        return;
    }
    if(l->inicio == NULL)
    {
        printf("]\n");
        return;
    }
    No* ponteiro = l->inicio;
    while(ponteiro->prox != NULL)
    {
        printf("%i, ", ponteiro->val);
        ponteiro = ponteiro->prox;
    }
    printf("%i]\n", l->fim->val);
}
/**
15. a Lista ligada é como um vetor dinâmico, mais intuitivo de ser usado e mais poderoso
    já o vetor é estático e um pouco mais dificil de tornar dinâmico, porém mais rápido de ser criado e implementado, além de permitir mais de uma dimensão
*/
int main(){
    int test[] = {1, 2, 3, 7, 4 ,2};
    Lista* a = CopiaVetor(test, 6);
    Lista* copia = copiarElementos(a, 100);
    imprimirLista(a);
    imprimirLista(copia);

}

/**
16. Maneira mais otimazada já está implementada
void InsereNoFimManeiraRuim(Lista *L, int val) {
    No *q = CriaNo(val);
    if (L->inicio == NULL) {
        L->inicio = q;
    }
    else {
        No *p = L->inicio;
        while (p->prox!=NULL) {
            p = p->prox;
        }
        p->prox = q;
    }
}
*/
