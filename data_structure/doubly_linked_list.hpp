#ifndef doubly_linked_list_hpp
#define doubly_linked_list_hpp

#include <stdio.h>
typedef int Data;
typedef struct _node{
    Data data;
    _node *prev;
    _node *next;
} Node;

typedef struct _DLinkedList{
    Node *head;
    Node *cur;
    int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, Data data);
bool LFirst(List *plist, Data *pdata);
bool LNext(List *plist, Data *pdata);
bool LPrevious(List *plist, Data *pdata);
Data LRemove(List *plist);
int LCount(List *plist);
#endif /* doubly_linked_list_hpp */
