// List has 2 types -> 1. Sequential list (배열을 기반으로 구현된 리스트), 2. linked list(메모리의 동적 할당을 기반으로 구현된 리스트)
// ADT에 따라 리스트가 제공할 기능에 따라 먼저 정의
// 리스트 자료구조는 데이터를 나란히 저장 // 중복된 데이터 저장도 허용
#ifndef list_hpp
#define list_hpp
#include "Point.hpp"

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100
typedef Point * LData; // list data 를 포인트 좌표로 선언한다. 이때 포인트 좌표 구조체는 포인터 변수로 선언하자.

typedef struct __ArrayList
{
    LData arr[LIST_LEN];
    int numOfData;
    int curPosition;
} ArrayList; // aliased name of that struct(__ArrayList) 별칭을 설정하는 이유는 struct를 별칭 없이 꺼내쓴다면 계속 'struct'를 명시적으로 붙여줘야 하므로..

typedef ArrayList List;

//리스트를 초기화 , 즉 리스트 생성을 의미함
void ListInit(List * plist); // 리스트의 주소값을 인자로 넣어서 리스트를 초기화 해준다

//리스트에 데이터 저장
void LInsert(List * plist, LData data); // 1. 들어갈 데이터(데이터는 사전 정의된 LData 타입), 2. 리스트의 주소값

// 첫 데이터를 참조
int LFirst(List * plist, LData * pdata); // 데이터 리스트의 주소값을 인자로 받음

// 두번째 이후의 데이터 참조(다음 데이터 참조) // 1. '다음의 기준'이 되는 데이터, 2. 리스트의 주소값을 인자로 받음
int LNext(List * plist, LData * pdata);

// 참조한 데이터 삭제
LData LRemove(List * plist);

// 저장되있는 데이터의 갯수
int LCount(List * plist);

#endif
