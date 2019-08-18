#include <stdio.h>
#include <stdlib.h>
#include "linked_list.c"
//it return the sum from first to last
int arithmetic_progression_sum(int first, int last)
{
    if (first == last)
        return last;
    if  (first > last)
        return 0;
    return first + arithmetic_progression_sum(first+1, last);
}
//it return true if the float has decimal numbers
int hasDecimal(float x)
{
    float integral = (int) x;
    return 0 != (x - integral);
}
//it return the power of base raised to exponent
float power(int base, int exponent)
{
    if(exponent == 0)
        return 1;
    if (exponent < 0)
        return 1/(power(base, -exponent));
    return base * power(base, exponent-1);
}

//given a int in base 10 will return a static unsigned long int into base 2
//max decimal is 524287 or 1111111111111111111 in binary
//!DISCONTINUED
static unsigned long int int_binary(register int decimal){
    if(decimal < 0)
        return int_binary(decimal*-1);
    if(decimal == 0)
        return 0;
    if(decimal == 1)
        return 1;
    return (10 * int_binary(decimal/2)) + decimal%2;
}

void decimal_to_binary(register int decimal)
{
    if(decimal < 0)
    {
        printf("-");
        return decimal_to_binary(decimal*-1);
    }
    if(decimal < 2)
    {    
        printf("%i", decimal); 
        return;
    }

    decimal_to_binary(decimal/2);
    printf("%i", decimal%2);    
}
int main()
{   
    decimal_to_binary(-10);
    return 0;
}