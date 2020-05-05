#ifndef arraybasestack_hpp
#define arraybasestack_hpp
#define STACK_LEN 100
#include <stdio.h>
typedef int Data;

typedef struct _arrayStack
{
    Data stackArr[STACK_LEN];
    int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack *pstack);
bool SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);

#endif /* arraybasestack_hpp */