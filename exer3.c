#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.c"
/*
3 - Repita os testes sugeridos no exercício 1, desta vez usando uma
lista encadeada para armazenar as contagens.
*/

clock_t comeco, fim;

linked_list* chaves;
linked_list* unicas;
int numero;

int quantidade, chaves_qtd, maior_ocorrencia, maior_qtd, auxiliar;

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
void ler_dados(char* nome)
{
    FILE *arquivo;
    arquivo = fopen(nome, "r");

    chaves = newlinked_list();
    while (fscanf(arquivo, "%d", &numero) != EOF)
        add_in_order_linked(chaves, numero);
}
void calcular_chaves_distintas(){
    unicas = newlinked_list();
    linked_node* p = chaves->first;
    while(p != NULL)
    {
        if(!binary_search_linked_value(unicas, p->value))
            add_in_order_linked(unicas, p->value);
        p = p->next;
    }
}
void calcular_maior_ocorrencia(){
    maior_ocorrencia = unicas->first->value;    
    maior_qtd = contem_qtd(chaves, maior_ocorrencia);
    linked_node * ponteiro = unicas->first->next;
    while (ponteiro != NULL)
    {
        int qtd_aux = contem_qtd(chaves, ponteiro->value);
        if(qtd_aux > maior_qtd)
        {
            maior_qtd = qtd_aux;
            maior_ocorrencia = ponteiro->value;
        }
        ponteiro = ponteiro->next;
    }
}
void executar(char* nome){
    comeco = clock();

    ler_dados(nome);
    
    calcular_chaves_distintas();

    calcular_maior_ocorrencia();

    printf("comprimento N do fluxo de entrada:  %d\n", chaves->size);
    printf("o número de chaves distintas: %d\n", chaves_qtd);
    printf("chave mais frequente: %d e o número de ocorrências dessa chave: %d\n", maior_ocorrencia, maior_qtd);
    fim = clock();    
    printf("Tempo de processamento: %Lf", (long double)(fim - comeco));
}

int main(){
    printf("\n\n---PRIMEIRO ARQUIVO--- randInt1K.txt\n\n");
    executar("randInt1K.txt");
    printf("\n\n--- SEGUNDO ARQUIVO --- randInt10K.txt\n\n");
    executar("randInt10K.txt");
    printf("\n\n--- TERCEIRO ARQUIVO --- randInt100K.txt\n\n");
    executar("randInt100K.txt");
    printf("\n\n--- QUARTO ARQUIVO --- randInt1M.txt\n\n");
    executar("randInt1M.txt");

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

Os resultados estão de acordo com as previsões teóricas?: NÃO
*/