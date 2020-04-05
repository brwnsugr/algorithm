//
//  list.cpp
//  practice
//
//  Created by Eun Ho Lee on 15/03/2020.
//  Copyright © 2020 Eun Ho Lee. All rights reserved.
//
#include <iostream>
#include "list.hpp"

void ListInit(List * plist){
    (plist->numOfData) = 0;
    (plist -> curPosition) = -1; // 현재 위치 아무것도 가리키지 않음
}

void LInsert(List * plist, LData data){
    // 더이상 저장할 공간이 없는 경우
    if(plist->numOfData >= LIST_LEN){
        puts("저장이 불가능합니다.");
        return;
    }
    plist->arr[plist->numOfData] = data;
    (plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata){ // LData는 포인터
    if(plist->numOfData == 0){ // 리스트에 데이터가 없는 경우
        return FALSE;
    }
    //데이터가 있는 경우
    (plist->curPosition) = 0; //참조위치 초기화, 첫번째 데이터 접근을 위해..
    *pdata = plist->arr[0];
    return TRUE;
}

int LNext(List * plist, LData * pdata){
    //더이상 참조할 데이터가 없을 때
    if(plist->curPosition >= (plist->numOfData)-1){
        return FALSE;
    }
    (plist->curPosition)++;
    *pdata = plist->arr[plist->curPosition];
    return TRUE;
}

LData LRemove(List * plist){
    //cur position 을 지움
    int rpos = plist->curPosition;
    int num = plist->numOfData;
    int i;
    LData RData = plist->arr[rpos]; //삭제할 데이터 선택
    for(i = rpos; i < num-1; i++){
        plist->arr[i] = plist->arr[i+1];
    }
    (plist->curPosition)--;
    (plist->numOfData)--;
    return RData;
}

int LCount(List * plist){
    return (plist->numOfData);
}
