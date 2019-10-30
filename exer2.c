#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.c"
/*
2  -  Reescreva  a  função  contabiliza  baseada  em  lista  encadeada  de modo  que  as  chaves  sejam  armazenadas  na  lista  encadeada  em ordem  crescente.
Estime  o  desempenho.  Vale  a  pena  mantera  lista em ordem crescente? 
*/

clock_t comeco, fim;

linked_list* unicas;
int * chaves;
int numero;

int quantidade, chaves_qtd, maior_ocorrencia, maior_qtd, auxiliar;

int contem_qtd_int(int * list, int tam, int valor){
    if(list == NULL || tam == 0)
        return 0;
    int aux = 0;
    int retorno = 0;
    while(aux < tam)
    {
        if(list[aux] == valor)
            retorno++;
        aux++;
    }
    return retorno;
}


int contem_qtd(linked_list * list, int valor){
    if(list == NULL || list->size == 0)
        return 0;
    linked_node * ponteiro = list->first;
    int retorno = 0;
    while(ponteiro!=NULL)
    {
        if(ponteiro->value == valor)
            retorno++;
        ponteiro = ponteiro->next;
    }
    return retorno;
}
void ler_dados(char* nome, int qtd)
{
    FILE *arquivo;
    arquivo = fopen(nome, "r");
    chaves = (int*) calloc(qtd, sizeof(int));
    int i = 0;
    while (fscanf(arquivo, "%d", &numero) != EOF)
    {
        chaves[i] = numero;
        i++;
    }
    quantidade = i;
}
int contem(int * list, int tam, int valor){
    if(list == NULL || tam == 0)
        return 0;
    int aux = 0;
    while(aux < tam)
    {
        if(list[aux] == valor)
            return 1;
        aux++;
    }
    return 0;
}
    
void calcular_chaves_distintas(int qtd){
    unicas = newlinked_list();
    int i = 0;
    while(i < qtd)
        if(!contains_linked_value(unicas, chaves[i]))
            add_in_order_linked(unicas, chaves[i]);
}
void calcular_maior_ocorrencia(int qtd){
    maior_ocorrencia = unicas->first->value;    
    maior_qtd = contem_qtd_int(chaves, qtd, maior_ocorrencia);
    linked_node * ponteiro = unicas->first->next;
    while (ponteiro != NULL)
    {
        int qtd_aux = contem_qtd_int(chaves, qtd, ponteiro->value);
        if(qtd_aux > maior_qtd)
        {
            maior_qtd = qtd_aux;
            maior_ocorrencia = ponteiro->value;
        }
        ponteiro = ponteiro->next;
    }
}
void executar(char* nome, int qtd){
    comeco = clock();

    ler_dados(nome, qtd);
    
    calcular_chaves_distintas(qtd);

    calcular_maior_ocorrencia(qtd);

    printf("comprimento N do fluxo de entrada:  %d\n", quantidade);
    printf("o número de chaves distintas: %d\n", unicas->size);
    printf("chave mais frequente: %d e o número de ocorrências dessa chave: %d\n", maior_ocorrencia, maior_qtd);
    fim = clock();    
    printf("Tempo de processamento: %Lf", (long double)(fim - comeco));
}

int main(){
    printf("\n\n---PRIMEIRO ARQUIVO--- randInt1K.txt\n\n");
    executar("randInt1K.txt", 1000);
    printf("\n\n--- SEGUNDO ARQUIVO --- randInt10K.txt\n\n");
    executar("randInt10K.txt", 10000);
    printf("\n\n--- TERCEIRO ARQUIVO --- randInt100K.txt\n\n");
    executar("randInt100K.txt", 100000);
    printf("\n\n--- QUARTO ARQUIVO --- randInt1M.txt\n\n");
    executar("randInt1M.txt", 1000000);

    return 0;
}

/*
OUTPUT:

---PRIMEIRO ARQUIVO--- randInt1K.txt

comprimento N do fluxo de entrada:  1000
o número de chaves distintas: 948
chave mais frequente: 3943 e o número de ocorrências dessa chave: 3
Tempo de processamento: 3592.000000

--- SEGUNDO ARQUIVO --- randInt10K.txt

comprimento N do fluxo de entrada:  10000
o número de chaves distintas: 6396
chave mais frequente: 8887 e o número de ocorrências dessa chave: 6
Tempo de processamento: 220938.000000

--- TERCEIRO ARQUIVO --- randInt100K.txt

comprimento N do fluxo de entrada:  100000
o número de chaves distintas: 10000
chave mais frequente: 5145 e o número de ocorrências dessa chave: 23
Tempo de processamento: 3497490.000000

--- QUARTO ARQUIVO --- randInt1M.txt

comprimento N do fluxo de entrada:  1000000
o número de chaves distintas: 10000
chave mais frequente: 6777 e o número de ocorrências dessa chave: 151
Tempo de processamento: 37952936.000000

Vale a pena mantera lista em ordem crescente?: SIM, porém resultado melhor para grandes quantidades de dados
*/