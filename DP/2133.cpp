//acmicpc.net
//filling the tiles DP
#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int d[10000];

int main(){
    scanf("%d",&n);
    d[0]=1;
    for(int i=2; i<=n ; i+=2){
        d[i]=d[i-2]*3;
        for(int j=i-4; j>=0; j-=2){
            d[i] += d[j]*2;
        }
    }
    cout<<d[n]<<'\n';
    return 0;
}