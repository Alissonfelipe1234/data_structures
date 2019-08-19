#include <stdio.h>
#include <stdlib.h>
#define LEN(x)  ((&x)[1] - x)
/*
please include '#include "myMath.c"' in your code
*/

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
//! DEPRECATED
static unsigned long int int_binary(register int decimal){
    if(decimal < 0)
        return int_binary(decimal*-1);
    if(decimal == 0)
        return 0;
    if(decimal == 1)
        return 1;
    return (10 * int_binary(decimal/2)) + decimal%2;
}
//it write a decimal nuber in binary base
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

//!internal use only
int vector_sum(int * vector, register int size)
{
    if(size == 1)
        return vector[0];
    return vector[size-1] + vector_sum(vector, size-1);
}
//it return the sum of array 2D's elements
//! this functions need a cast in static arrays, use (int**)
int sum(int** vector)
{
    return vector_sum((int*)vector, (int)LEN(vector));
}