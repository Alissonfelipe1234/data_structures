#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * lista, * chaves;
clock_t comeco, fim;
int numero;
int quantidade, chaves_qtd, maior_ocorrencia, maior_qtd, auxiliar;

int contem_qtd(int * list, int tam, int valor){
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
    
void executar(char* nome, int qutd){
    comeco = clock();
    FILE *arquivo;
    lista = (int*) calloc(qutd, sizeof(int));
    chaves = (int*) calloc(qutd, sizeof(int));
    
    arquivo = fopen(nome, "r");
    
    quantidade = 0;
    chaves_qtd = 0;
    while (fscanf(arquivo, "%d", &numero) != EOF)
    {
        lista[quantidade] = numero;
        if(chaves_qtd == 0 || !contem(chaves, chaves_qtd, numero))
        {
            chaves[chaves_qtd] = numero;
            chaves_qtd++;
        }
        quantidade++;
    }
    maior_ocorrencia = chaves[0];
    maior_qtd = contem_qtd(lista, quantidade, chaves[0]);
    auxiliar = 0;
    while(auxiliar < chaves_qtd)
    {
        int temp = contem_qtd(lista, quantidade, chaves[auxiliar]);
        if(temp > maior_qtd)
        {
            maior_qtd = temp;
            maior_ocorrencia = chaves[auxiliar];
        }
        auxiliar++;
    }
    printf("comprimento N do fluxo de entrada:  %d\n", quantidade);
    printf("o número de chaves distintas: %d\n", chaves_qtd);
    printf("chave mais frequente: %d e o número de ocorrências dessa chave: %d\n", maior_ocorrencia, maior_qtd);
    fim = clock();    
    printf("Tempo de processamento: %Lf", (long double)(fim - comeco)/CLOCKS_PER_SEC);
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

    printf("\n\nOs resultados estão de acordo com as previsões teóricas?: NÃO");
    return 0;
}

/*
OUTPUT:

---PRIMEIRO ARQUIVO--- randInt1K.txt

comprimento N do fluxo de entrada:  1000
o número de chaves distintas: 948
chave mais frequente: 3943 e o número de ocorrências dessa chave: 3
Tempo de processamento: 0.000000

--- SEGUNDO ARQUIVO --- randInt10K.txt

comprimento N do fluxo de entrada:  10000
o número de chaves distintas: 6396
chave mais frequente: 8887 e o número de ocorrências dessa chave: 6
Tempo de processamento: 203125.000000

--- TERCEIRO ARQUIVO --- randInt100K.txt

comprimento N do fluxo de entrada:  100000
o número de chaves distintas: 10000
chave mais frequente: 5145 e o número de ocorrências dessa chave: 23
Tempo de processamento: 3265625.000000

--- QUARTO ARQUIVO --- randInt1M.txt

comprimento N do fluxo de entrada:  1000000
o número de chaves distintas: 10000
chave mais frequente: 6777 e o número de ocorrências dessa chave: 151
Tempo de processamento: 32828125.000000

Os resultados estão de acordo com as previsões teóricas?: NÃO
*/