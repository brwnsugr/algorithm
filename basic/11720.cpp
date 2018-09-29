//숫자를 한개씩 끊어서 받아서 합을 출력하기
#include <stdio.h>

int main(){
    int n, i, sum, x;
    sum = 0; 
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%1d",&x);
        sum = sum +x;
    }
    printf("%d",sum);
    return 0;
}