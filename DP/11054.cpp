//acmicpc.net
//Longest bitonic Subsequence(DP)
#include <iostream>
#include <stdio.h>
#include <algorithm>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

long long a[1001];
long long d[1001];
long long d2[1001];

int main(){
    int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=n;i++){
            d[i]=1;
            for(int j=1;j<i;j++){
                if((a[i]>a[j])&&d[i]<d[j]+1){
                    d[i]=d[j]+1;
                    }
                }
            }
            for(int i=n;i>=1;i--){
                d2[i]=1;
                for(int j=i+1;j<=n;j++){
                    if(a[j]<a[i] && d2[i]<d2[j]+1){
                        d2[i]=d2[j]+1;
                    }
                }
            }
    
    long long ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,(d[i]+d2[i]-1));
        }
    
    cout<<ans<<'\n';
    return 0;
}