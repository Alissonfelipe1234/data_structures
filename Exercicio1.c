#include <stdio.h>
#include <stdlib.h>
int sequencia(int x);

int main(){
    //testes
    printf("%i\n", sequencia(1));
    printf("%i\n", sequencia(0));
    printf("%i\n", sequencia(2));
    printf("%i\n", sequencia(10));
}

int sequencia(int x){//poderia usar long int ao inves de int para grandes operacoes
    if(x == 0)
        return 0;
    return x + sequencia(x-1);
} 