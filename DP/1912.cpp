//acmicpc.net
//Continuous Sum (DP)
#include <iostream>
#include <stdio.h>
using namespace std;

int a[100001];
int d[100001];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        d[i]=a[i];
        if(i==1) continue;
        if(d[i]<d[i-1]+a[i]){
            d[i]=d[i-1]+a[i];
        }
    }
    int ans = d[1];
    for (int i=2; i<=n; i++) {
        if (ans < d[i]) {
            ans = d[i];
        }
    }
    cout << ans <<'\n';
    return 0;
}