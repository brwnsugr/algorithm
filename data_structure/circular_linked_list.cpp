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
        plist->before = plist->tail;
        plist->cur = plist->tail->next;
        *pdata = plist->cur->data;
        return true;
    }
}

bool LNext(List *plist, Data *pdata){
    if(plist->tail == NULL){
        return false;
    }
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    
    *pdata = plist->cur->data;
    return true;
}

Data LRemove(List *plist){
    Node *rpos = plist->cur;
    Data rdata = rpos->data;
    
    if(rpos == plist->tail){
        if(plist->tail->next == plist->tail){
            plist->tail = NULL;
        }
        else{
            plist->tail = plist->before;
        }
    }
    
    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    
    free(rpos);
    (plist->numOfData)--;
    return rdata;
}