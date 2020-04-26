#ifndef circular_linked_list_hpp
#define circular_linked_list_hpp

#include <stdio.h>
typedef int Data;

typedef struct _node{
    Data data;
    struct _node *next;
} Node;

typedef struct _linkedlist{
    Node *head;
    Node *before;
    Node *cur;
    int numOfData;
} CList;

typedef CList List;

void ListInit(List *plist);
void LInsert(List *plist, Data data);
void LInsertFront(List *plist, Data data);

int LFirst(List *plist, Data *pdata);
int LNext(List *plist, Data *pdata);
Data LRemove(List *plist); // 현재 cur가 가리키는 data를 지우고, 해당 지운 데이터를 반환합니다.
int LCount(List *plist); // 현재 링크드리스트의 노드 숫자를 반환해줍니다.


#endif /* circular_linked_list_hpp */