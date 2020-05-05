#include "arraybasestack.hpp"

void StackInit(Stack *pstack){
    pstack->topIndex = -1;
}

bool SIsEmpty(Stack *pstack){
    if(pstack->topIndex == -1) return true;
    else return false;
}

void SPush(Stack *pstack, Data data){
    if(pstack->topIndex >= STACK_LEN){
        printf("The Stack is already full\n");
    }
    else{
        pstack->topIndex++;
        pstack->stackArr[pstack->topIndex] = data;
    }
}

Data SPop(Stack *pstack){
    int rIdx;
    if(SIsEmpty(pstack)){
        printf("There's no element in the Stack!");
        return 0;
    }
    else{
        rIdx = pstack->topIndex;
        pstack->topIndex--;
        
        return pstack->stackArr[rIdx];
    }
}

Data SPeek(Stack *pstack){
    if(SIsEmpty(pstack)){
        printf("There's no Element in the Stack");
        return 0;
    }
    else{
        return pstack->stackArr[pstack->topIndex];
    }
}