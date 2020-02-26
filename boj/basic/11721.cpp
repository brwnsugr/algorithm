//acmicpc.net
//10 Letters print 
#include <stdio.h>
#include <iostream>
using namespace std;

char a[100];

int main(){
    while(scanf("%10s",a)==1){
        printf("%s\n",a);
    }
    return 0;
}