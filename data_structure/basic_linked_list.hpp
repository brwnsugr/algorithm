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
    Node *before;
    int NumOfData; // Data의 갯수
    int (*comp)(LData d1, LData d2); // 시그니처가 정수인 함수의 포인터를 구조체의 변수로 갖습니다. 이 함수는 d1, d2 인자를 갖습니다.
} LinkedList;

typedef LinkedList List; // LinkedList 라는 구조체의 타입이름을 List 로 다시 정의해줌

void ListInit(List *plist); // List 의 포인터 변수를 인자로 받아서 List 를 초기화 해줍니다.
void FInsert(List *plist, LData data); // List 에 아무것도 없을 때 최초의 데이터를 넣어줍니다.
void LInsert(List *plist, LData data); // data 를 새로 넣어줍니다.
void LInsert2(List *plist, LData data); // Head에 더미 노드를 설정한 경우의 정렬 코드입니다.

bool LFirst(List *plist, LData *pdata); //첫번 데이터가 pdata가리키는 메모리에 저장. *pdata인자로 갖는 이유는 uninit된 포인터 변수에 참조 값을 할당하기 위함
bool LNext(List *plist, LData *pdata); // 참조된 데이터의 다음 데이터가 pdata가 가리키는 메모리에 저장된다.

int LCount(List *plist); // List의 포인터 변수를 인자로 받아서 List 의 데이터 갯수를 반환합니다. this Function's Signature is Integer.

void LRemove(List *plist); // List 의 포인터 변수를 인자로 받아서... LFirst 에 의한 값이나, LNext 에 의한 Node 구조체 값을 제거합니다...??

void printCur(List *plist); // 현재를 가리키는 노드의 값을 출력해줍니다.

void SetSortRule(List *plist, int(*comp)(LData d1, LData d2)); // 연결 리스트의 정렬 기준이 되는 함수 comp의 포인터를 인자로 넣어서 비교 함수를 등록합니다.

void SInsert(List *plist, LData data); //comp에 등록된 정렬기준을 근거로 데이터를 저장하는 SInsert 함수

int sort_func1(LData d1, LData d2);



#endif /* basic_linked_list_hpp */