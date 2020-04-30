#include "doubly_linked_list.hpp"
#include <stdlib.h>
void ListInit(List *plist){
    plist->head = (Node*)malloc(sizeof(Node)); // head 에 더미 노드 생성.
    plist->head->next = NULL;
    plist->numOfData = 0;
}

void LInsert(List *plist, Data data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = plist->head->next;
    if(plist->head->next != NULL) plist->head->next->prev = newNode;
    plist->head->next = newNode;
    newNode->prev = NULL;
    (plist->numOfData)++;
}

bool LFirst(List *plist, Data *pdata){ // 1. cur 초기화, 2. 첫번째 데이터가 pdata가 가리키는 메모리에 저장된다.
    if(plist->head->next == NULL){
        return false;
    }
    else{
        plist->cur = plist->head->next;
        *pdata = plist->cur->data;
        return true;
    }
}

bool LNext(List *plist, Data *pdata){ // cur 의 다음 원소를 pdata가 가리키는 메모리에 저장하고, cur의 다음원소가 있으면 true, 없으면 false를 반환한다.
    if(plist->cur->next == NULL){
        return false;
    }
    else{
        plist->cur = plist->cur->next;
        *pdata = plist->cur->data;
        return true;
    }
}

bool LPrevious(List *plist, Data *pdata){ // cur 의 이전 원소를 pdata가 가리키는 메모리에 저장하고,cur의 이전 원소가 있으면 true, 없으면 false를 반환한다.
    if(plist->cur->prev == NULL){
        return false;
    }
    else{
        plist->cur = plist->cur->prev;
        *pdata = plist->cur->data;
        return true;
    }
}