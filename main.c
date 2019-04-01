#include<stdio.h>
#include<stdlib.h>
#include "linked_list.c"

int main()
{
    List* l = newList();
    addFirst(l, 10);
    addFirst(l, 2);

    printAll(l);
}
