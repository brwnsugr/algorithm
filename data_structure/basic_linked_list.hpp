//
//  basic_linked_list.hpp
//  practice
//
//  Created by st on 13/04/2020.
//  Copyright © 2020 st. All rights reserved.
//

#ifndef basic_linked_list_hpp
#define basic_linked_list_hpp

#include <stdio.h>
typedef int LData;

typedef struct _node{
    LData data; // LData 의 data 변수, LData 라는 타입은 위에서 typedef에 의해 정의되었다.
    struct _node *next; // _node라는 구조체 포인터 변수를 선언함
} Node;

typedef struct _linkedlist{
    Node *head; // Node 구조체의 포인터 변수인 head 선언
    Node *cur; // Node 구조체의 포인터 변수인 cur 선언
    Node *tail; // Node 구조체의 포인터 변수인 Tail 선언
    int NumOfData; // Data의 갯수
    int (*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List; // LinkedList 라는 구조체의 타입이름을 List 로 다시 정의해줌

void ListInit(List *plist); // List 의 포인터 변수를 인자로 받아서 List 를 초기화 해줍니다.
void LInsert(List *plist, LData data); // data 를 새로 넣어줍니다.

LData LFirst(List *plist); // List의 포인터 변수를 인자로 받아서 첫번째 데이터의 참조값을 반환합니다.

int LCount(List *plist); // List의 포인터 변수를 인자로 받아서 List 의 데이터 갯수를 반환합니다. this Function's Signature is Integer.

void LRemove(List *plist); // List 의 포인터 변수를 인자로 받아서... LFirst 에 의한 값이나, LNext 에 의한 Node 구조체 값을 제거합니다...??





#endif /* basic_linked_list_hpp */