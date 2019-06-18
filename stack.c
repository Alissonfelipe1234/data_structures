#include<stdio.h>
#include<stdlib.h>
/**
Implements of LIFO (Last In First Out)
*/
typedef struct _stack
{
    Node* first;
    Node* last;

    int size;

} Stack;

typedef struct _node
{
    int value;
    _node* next;
} Node;

Node* create_node(int v)
{
    Node * newest =(Node*) calloc(1, sizeof(Node));
    newest.value = v;
    return newest;
}

Stack* create_stack(){
    return (Stack*) calloc(1, sizeof(Node));
}

Node* reuse_node(Node* n)
{
    n.next = NULL;
    return n;
}

int add_value(Stack* q, int value)
{
    if(q == NULL)
        return 0;
    if(q.size == 0)
    {
        q.size++;
        q.first = create_node(value);
        q.last = q.first;
        return 1;
    }
    q.size++;
    q.last.next = create_node(value);
    q.last = q.last.next;
    return 1;
}
int add_node(Stack* q, Node* n)
{
    n = reuse_node(n);
    if(q.size == 0)
    {
        q.size++;
        q.first = n;
        q.last = q.first;
        return 1;
    }
    q.size++;
    q.last.next = n;
    q.last = q.last.next;
    return 1;
}
int get_value(Stack* q)
{
    if(q.size = 0)
        return NULL;
    get_node(q).value;
}
Node* get_node(Stack* q)
{
    if(q.size = 0)
    {
        return NULL;
    }
    Node* aux = q.first;
    int i;
    for (i = 0; i < q.size-1; i++)
        ret = ret.next;
    Node* ret = q.last;
    q.last = reuse_node(ret);
    q.size--;
    return ret;
}

void printStack(Stack* q)
{
    int i;
    Node* n = q.first;
    printf("[");
    for (i=0; i < q.size-1; i++)
    {
        printf("%i, ", n.value);
        n = n.next;
    }
    printf("%i]", n.value);
}
