#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.c"
/*
4 - Refaça o exercício 1 usando um vetor de células no lugar de uma lista encadeada. Redimensione o vetor à medida que o número de chaves distintas aumenta. 
Qual o consumo de tempo dessa versão?
Agora mantenha o vetor em ordem crescente de chaves e refaça a análise.
*/

clock_t comeco, fim;
int numero;

typedef struct reg celula;
struct reg {
    int chave, ocorr;
    celula *prox;
};

celula **nova_celula()
{
    return calloc (1,  sizeof (celula *));
}

int hash(){

}

void contabiliza (int ch, celula ** tb) {
    int h = hash (ch, 1000);
    celula *p = tb[h];
    while (p != NULL && p->chave != ch)
        p = p->prox;

    if (p != NULL)
        p->ocorr += 1;
    else {
        p = malloc (sizeof (celula));
        p->chave = ch;
        p->ocorr = 1;
        p->prox = tb[h];
        tb[h] = p;
    }
}

void ler_dados(char* nome, int qtd)
{
    FILE *arquivo;
    arquivo = fopen(nome, "r");
    int i = 0;
    while (fscanf(arquivo, "%d", &numero) != EOF)
    {
        
        i++;
    }
}
void executar(char* nome, int qtd){
    comeco = clock();
    celula **tb;

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