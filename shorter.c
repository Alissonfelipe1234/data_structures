#include <stdlib.h>
#include <stdio.h>
/** 
Neste exercício você irá implementar um algoritmo de ordenação misto. Este algoritmo terá como base o QuickSort. A medida que a recursão do QuickSort vai acontecendo, 
as sub-listas que devem ser ordenadas vão diminuindo de tamanho, ate que chegamos no caso base. 
Originalmente, este caso base são listas de tamanho um. 
Neste laboratório nos vamos modificar o tamanho das listas do caso base para um valor threshold que será fornecido como entrada do problema. 
A ideia e utilizar o InsertionSort para ordenar as sub-listas quando o tamanho desta seja menor do que este threshold. 
Assim, estaremos utilizando sempre o melhor método de ordenação possível, aproveitando o melhor de cada um.

*/

void quick_sort(char *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}
int main(){
    
}