//acmicpc.net
//LIS Algorithm_2 DP
#include <iostream>
#include <stdio.h>
#include <algorithm>
#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;
long long a[1001];
long long d[1001];

int main(){
    int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
    d[1]=1;
        for(int i=2;i<=n;i++){
            d[i]=1;
            for(int j=1;j<i;j++){
                if((a[i]<a[j])&&d[i]<d[j]+1){
                    d[i]=d[j]+1;
                    }
                }
            }
    long long ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,d[i]);
    }
    cout<<ans<<'\n';
    return 0;
}