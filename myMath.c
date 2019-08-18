#include <stdio.h>
#include <stdlib.h>
/*
please include '#include "myMath.c"' in your code
*/

//return the sum from first to last
int arithmetic_progression_sum(int first, int last)
{
    if (first == last)
        return last;
    if  (first > last)
        return 0;
    return first + arithmetic_progression_sum(first+1, last);
}
//return true if the float has decimal numbers
int hasDecimal(float x)
{
    float integral = (int) x;
    return 0 != (x - integral);
}
//return the power of base raised to n
float power(int base, int exponent)
{
    if(exponent == 0)
        return 1;
    if (exponent < 0)
        return 1/(power(base, -exponent));
    return base * power(base, exponent-1);
}
//return a number in base 10 to base 2
int binary(int decimal){
    if(decimal == 1)
        return 1;
    return (10 * binary(decimal/2)) + decimal%2;
}