#include "basic_linked_list.hpp"
//#include "list.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    List plist;
    ListInit(&plist); // 왜 참조 변수를 넣어야 하는가? -> 이미 선언된 plist를 인자로 받기 때문이다.
    printCur(&plist);
    LInsert(&plist, 2);
    LInsert(&plist, 3);
    LInsert(&plist, 4);
    LData p;
    if(LFirst(&plist, &p)){
        printCur(&plist);
        while(LNext(&plist, &p)){
            printCur(&plist);
        }
    }
    return 0;
}