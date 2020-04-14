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
    plist->cur = NULL;
    plist->head = NULL;
    plist->tail = NULL;
    plist->NumOfData = 0;
    plist->comp = NULL;
}

void LInsert(List *plist, LData data){
    //먼저 새로운 노드 데이터를 동적으로 할당하자.
    Node *newNode = (Node*)malloc(sizeof(Node)); // Node 타입을 시그니처로 갖는 포인터 변수를 할당 하기 위해서는 malloc 앞에 형을 적어줘야한다.(Node*)
    newNode->data = data;// Node 의 data 값에 새 데이터를 넣어주자.
    newNode->next = NULL; // 우선 Node의 next pointer는 Null로 설정해두자.
    //헤드가 없는 경우(즉, 아예 비어있는 경우) head 부터 새로운 원소를 밀어넣자.
    if(plist->head == NULL){ // 참고로 구조체 pointer 에서 구조체 내 변수를 가리킬 때는, Arrow Notation 을 사용한다.
        plist->head = newNode;
        plist->tail = newNode;
    }
    else if(plist->head != NULL){
        newNode->next = plist->head;
        plist->head = newNode;
    }
    plist->cur = plist->head;
    plist->NumOfData++;
}

bool LFirst(List *plist, LData *pdata){
    bool flag = false;
    LData ret;
    if(plist->head != NULL){
        flag = true;
        ret = plist->head->data; // 노드의 첫번째는 Head 가 적절하다.
        pdata = &ret; // pdata라는 포인터 변수에 첫번째 노드 데이터의 참조값을 담는다.
    }
    return flag;
}

bool LNext(List *plist, LData *pdata){
    bool flag = false;
    LData ret = 0;
    if(plist->cur->next != NULL){
        flag = true;
        plist->cur = plist->cur->next;
        ret = plist->cur->data;
    }
    if(flag) pdata = &ret;
    return flag;
}

void printCur(List *plist){
    if(plist->cur != NULL){
        printf("Curr Node: %d\n", plist->cur->data);
    }
    else{
        printf("Current Node Doesn't exist!");
    }
}
