#include <stdio.h>
#include <stdlib.h>
double somatoria_expressao(double n, int qtdLoops);

int main(){
    //testes
    printf("%lf\n", somatoria_expressao(1,1));
    printf("%lf\n", somatoria_expressao(1,2));
    printf("%lf\n", somatoria_expressao(1,3));
    printf("%lf\n", somatoria_expressao(1,4));
}

double somatoria_expressao(double n, int qtdLoops){
    if(qtdLoops == 0)
        return 0;
    return (((n*n)+1)/(n+3)) + somatoria_expressao(n+1, qtdLoops-1);
} 