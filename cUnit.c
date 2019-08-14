#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "linked_list.c"

float powf(float x, float y);

int hasDecimal(float x)
{
    float integral = (int) x;
    return 0 != (x - integral);
}
float power(float x, float n)
{
    if(n==1)
        return x;
    if(n == 0)
        return 1;
    if (n < 0)
        return 1/(power(x, -n));
    if (hasDecimal(n)) //insolve for this time
        return 0;

    return x * power(x, n-1);
}

int main()
{   
    
    printf("result of x * n = %f\n", power(2, 0.2));
    return 0;
}