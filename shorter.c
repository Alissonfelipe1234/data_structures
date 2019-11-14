#include <stdlib.h>
#include <stdio.h>

void quick_sort(char *a, int left, int right, int limit) {
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
    if(limit >= right - left){
    
   		    if(j > left) {
            quick_sort(a, left, j, limit);
   				  }
        if(i < right) {
            quick_sort(a, i, right, limit);
        }
    }
    else
    {
        insertionSort(a, right-left, left);
    }
}

void insertionSort(char * a, int len, int init)  
{  
    int i, key, j;  
    for (i = init; i < len; i++) 
    {  
        key = a[i];  
        j = i - 1;
        while (j >= 0 && a[j] > key) 
        {  
            a[j + 1] = a[j];  
            j = j - 1;  
        }  
        a[j + 1] = key;  
    }  
}
int main(){
    
}