#include<stdio.h>
#include<stdlib.h>
/**
Implements of FIFO (First In First Out)
*/
typedef struct _queue
{
    Node* first;
    Node* last;

    int size;

} Queue;
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

Queue* create_queue(){
    return (Queue*) calloc(1, sizeof(Node));
}

Node* reuse_node(Node* n)
{
    n.next = NULL;
    return n;
}

int add_value(Queue* q, int value)
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
int add_node(Queue* q, Node* n)
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
int get_value(Queue* q)
{
    if(q.size = 0)
        return NULL;
    get_node(q).value;
}
Node* get_node(Queue* q)
{
    if(q.size = 0)
    {
        return NULL;
    }
    Node* ret = q.first
    q.first = q.first.next;
    q.size--;
    return reuse_node(ret);
}

void printQueue(Queue* q)
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
