//acmicpc.net
//Drinking wine DP
#include <iostream>
#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

long long a[10001];
long long d[10001][3];

int main(){
    int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
    d[1][0]=d[1][1]=d[1][2]=a[1];
        for(int i=1;i<=n;i++){
            d[i][0]=max(d[i-1][1],max(d[i-1][0],d[i-1][2]));
            d[i][1]=d[i-1][0]+a[i];
            d[i][2]=d[i-1][1]+a[i];
            }
        long long ans = 0;
        for(int i=1;i<=n;i++){
            ans=max(max(ans,d[i][0]),max(d[i][1],d[i][2]));
        }
        
        cout<<ans<<'\n';
    return 0;
    }