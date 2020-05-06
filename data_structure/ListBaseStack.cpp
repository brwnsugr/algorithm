#include "ListBaseStack.hpp"
#include <stdlib.h>

void StackInit(Stack *pstack){
    pstack->head = NULL;
}

bool SIsEmpty(Stack *pstack){
    if(pstack->head == NULL){
        return true;
    }
    else{
        return false;
    }
}

void SPush(Stack *pstack, Data data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = pstack->head;
    pstack->head = newNode;
}

Data SPop(Stack *pstack){
    if(SIsEmpty(pstack)){
        printf("There's nothing to pop in the stack!");
        return 0;
    }
    else{
        Data rData = pstack->head->data;
        Node *rNode = pstack->head;
        pstack->head = rNode->next;
        free(rNode);
        return rData;
    }
}

Data SPeek(Stack *pstack){
    if(SIsEmpty(pstack)){
        printf("There's nothing in the stack!");
        return 0;
    }
    else{
        return pstack->head->data;
    }
}