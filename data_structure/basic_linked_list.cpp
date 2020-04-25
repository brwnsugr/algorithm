//
//  basic_linked_list.cpp
//  practice
//
//  Created by st on 13/04/2020.
//  Copyright © 2020 st. All rights reserved.
//

#include "basic_linked_list.hpp"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List *plist){
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->NumOfData = 0;
    plist->comp = NULL;
}

void FInsert(List *plist, LData data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = data;
    newNode->next = plist->head->next;
    plist->head->next = newNode;
    
    (plist->NumOfData)++;
}

void LInsert(List *plist, LData data){
    if(plist->comp ==NULL){
        FInsert(plist, data);
    }
    else{
        SInsert(plist, data);
    }
}

bool LFirst(List *plist, LData *pdata){ // list의 첫번째 데이터의 참조값으로 인자를 바꿔주면서, 첫번째 원소가 있는지 없는지를 유무를 bool로 반환한다.
    if(plist->head->next == NULL) return false; // Head에 Dummy 가 null로 있으므로, 원소가 있는지 판별기준은 plist->head->next 이다.
    plist->before = plist->head; // head 노드, 즉 더미 노드를 before로 한다.
    plist->cur = plist->head->next; // head 다음인 첫번째 노드를 cur 로 한다.
    
    *pdata = plist->cur->data;
    return true;
}

bool LNext(List *plist, LData *pdata){
    if(plist->cur->next == NULL) return false;
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    
    *pdata = plist->cur->data;
    return true;
}

void printCur(List *plist){
    if(plist->cur != NULL){
        printf("Curr Node: %d\n", plist->cur->data);
    }
    else{
        printf("Current Node Doesn't exist!");
    }
}

void SetSortRule(List *plist, int(*comp)(LData  d1, LData d2)){
    plist->comp = comp; // plist의 구조체의 함수에 등록합니다.
}

void SInsert(List *plist, LData data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    Node *pred = plist->head; //pred는 더미 노드를 가리킴
    newNode->data = data;
    
    while(pred->next != NULL && plist->comp(data, pred->next->data)!= 0){
        pred = pred->next;
    }
    
    newNode->next = pred->next; //newNode 의 오른쪽을 연결
    pred->next = newNode;
    
    (plist->NumOfData)++;
}

int sort_func1(int d1, int d2){
    if(d1 < d2) return 0;
    else return 1;
}

void SetSortRule(List *plist, int(*comp)(LData  d1, LData d2)){
    plist->comp = comp; // plist의 구조체의 함수에 등록합니다.
}

void SInsert(List *plist, LData data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    Node *pred = plist->head; //pred는 더미 노드를 가리킴
    
    while(pred->next != NULL && plist->comp(data, pred->next->data)!= 0){
        pred = pred->next;
    }
    
    newNode->next = pred->next; //newNode 의 오른쪽을 연결
    pred->next = newNode;
    
    (plist->NumOfData)++;
}