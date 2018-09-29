//acmicpc.net
//Summation of Square Num (DP)
#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int d[100001];

int main(){
    scanf("%d",&n);
    for(int i=1; i<=n ; i++){
        d[i]=i;
        for(int j=1; j*j<=i;j++){
            if(d[i]>d[i-j*j]+1){
                d[i]=d[i-j*j]+1;
            }
        }
    }
    cout<<d[n]<<'\n';
}