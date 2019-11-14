#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int tamanho;
int threshold;

typedef struct _carro{
    char modelo[16];
    int ano;
    char nome[16];
    int preco;
    char placa[8];
}Carro;

void adicionarCarro(char placa[8],char modelo[16], int ano, char nome[16],int preco,Carro *carros, int index);
void entradaCarros(Carro *carros);
int comparaPlaca(Carro a, Carro b);
int comparaPreco(Carro a, Carro b);
int comparaAno(Carro a, Carro b);
int comparaModelo(Carro a, Carro b);
void placaNome(Carro a);
void placaValor(Carro a);
void nomeAnoPlaca(Carro a);
void modeloValorPlaca(Carro a);
void printCarros(Carro* carros , void (*criterio)(Carro a));
void quick(Carro* carros , int (*comparacao)(Carro a, Carro b),int began, int end);
void insertion(Carro* carros , int (*comparacao)(Carro a, Carro b),int began, int end);

int main (){
    scanf("%d", &tamanho);
    scanf("%d", &threshold);

    Carro *carros = (Carro *)calloc(tamanho,sizeof(Carro));

    entradaCarros(carros);

    printf("\n");

    quick(carros,comparaPlaca,0,tamanho);
    printCarros(carros,placaNome);
    printf("\n");

    quick(carros,comparaPreco,0,tamanho);
    printCarros(carros,placaValor);
    printf("\n");

    quick(carros,comparaAno,0,tamanho);
    printCarros(carros,nomeAnoPlaca);
    printf("\n");

    quick(carros,comparaModelo,0,tamanho);
    printCarros(carros,modeloValorPlaca);
    printf("\n");

    free(carros);
    return 1;
}

void adicionarCarro(char placa[8],char modelo[16], int ano, char nome[16],int preco,Carro *carros, int index){
    strcpy(carros[index].placa, placa);
    strcpy(carros[index].modelo, modelo);
    carros[index].ano = ano;
    strcpy(carros[index].nome, nome);
    carros[index].preco = preco;
}

void entradaCarros(Carro *carros){
    int i, ano, preco;
    char placa[8], modelo[16], nome[16];
    for(i = 0; i < tamanho; i++){
        scanf("%7s %15s %d %15s %d",placa,modelo,&ano,nome,&preco);
        adicionarCarro(placa,modelo,ano,nome,preco,carros,i);
    }
}

int comparaPlaca(Carro a, Carro b){
    return strcmp(a.placa, b.placa);
}

int comparaPreco(Carro a, Carro b){
    if(a.preco == b.preco)
        return 0;

    if(a.preco < b.preco)
        return -1;

    return 1;
}

int comparaAno(Carro a, Carro b){
    if(a.ano == b.ano)
        return 0;

    if(a.ano < b.ano)
        return 1;

    return -1;
}

int comparaModelo(Carro a, Carro b){
    return strcmp(a.modelo, b.modelo);
}

void placaNome(Carro a){
    printf("%s %s\n",a.placa,a.nome);
}

void placaValor(Carro a){
    printf("%s %d\n",a.placa,a.preco);
}
void nomeAnoPlaca(Carro a){
    printf("%s %d %s\n",a.nome,a.ano,a.placa);
}
void modeloValorPlaca(Carro a){
    printf("%s %d %s\n",a.modelo,a.preco,a.placa);
}
void printCarros(Carro* carros , void (*criterio)(Carro a)){
    int i;
    for(int i = 0; i < tamanho; i++)
        (*criterio)(carros[i]);
}

void quick(Carro* carros , int (*comparacao)(Carro a, Carro b),int began, int end){
    if(end - began > threshold){
        int i,j;
        Carro pivo, aux;
        i = began;
        j = end-1;
        pivo = carros[(began + end) / 2];
        while(i <= j){
            while((*comparacao)(carros[i], pivo) < 0 && i < end){
                i++;
            }
            while((*comparacao)(carros[j], pivo) > 0 && j > began){
                j--;
            }
            if(i <= j){
                aux = carros[i];
                carros[i] = carros [j];
                carros[j] = aux;
                i++;
                j--;
            }
        }
        if(j > began)
            quick(carros,comparacao,began,j+1);
        if(i < end)
            quick(carros,comparacao,i,end);
    }
    else
        insertion(carros,comparacao,began,end);
}

void insertion(Carro* carros , int (*comparacao)(Carro a, Carro b),int began, int end){
    int i,j;
    Carro escolhido;
    for(i=began;i<end;i++){
        escolhido = carros[i];
        j=i-1;
        while((j >= began)&&((*comparacao)(carros[j], escolhido)> 0)){
            carros[j+1] = carros[j];
            j--;
        }
        carros[j+1] = escolhido;
    }
}
