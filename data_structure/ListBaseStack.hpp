#ifndef ListBaseStack_hpp
#define ListBaseStack_hpp

#include <stdio.h>
typedef int Data;

typedef struct _node // 연결리스트의 노드를 표현한 구조체
{
    Data data;
    struct _node *next;
} Node;

typedef struct _listStack
{
    Node *head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack);
bool SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);

#endif /* ListBaseStack_hpp */