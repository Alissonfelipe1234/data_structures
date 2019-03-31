#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#ifdef  __cplusplus
extern "C" {
#endif
typedef struct _node
{
    int value;
    struct _node *prox;
} Node;
extern Node root_node;

typedef struct _list
{
    Node *first;
    Node *last;
    int denyDuplicate;
} List;
extern List root_list;

List* newList();
List* sortList(List* l);

Node* newNodeEmpty();
Node* newNode(int v);
Node* findNode(List* l, int v);

int addLast(List* l, int v);
int addFirst(List* l, int v);
int addInOrder(List* l, int v);
int removeValue(List* l, int v);
int removeAllValues(List* l, int v);
int containsValue(List* l, int v);
int len(List* l);
int findValue(List* l, int v);
int isEmpty(List* l);


void printAll(List* l);

int containsRepeatedNode(List* l);
int allowRepeat(List* l);
int denyRepeat(List* l);

#ifdef  __cplusplus
}
#endif
#endif
