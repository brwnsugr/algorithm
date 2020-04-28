#include "circular_linked_list.hpp"
#include <stdlib.h>
#include <stdio.h>

void ListInit(List *plist){
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
}

void LInsert(List *plist, Data data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if(plist->tail == NULL){ // 아예 비어있는 원소인 경우,
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else{
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }
    plist->numOfData++;
}

bool LFirst(List *plist, Data *pdata){
    if(plist->tail == NULL){
        return false;
    }
    else{
        *pdata = plist->tail->next->data;
        return true;
    }
}