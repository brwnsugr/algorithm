//acmicpc.net
//Crocus Algorithm DP , 파도반 수열
#include <iostream>
#include <stdio.h>
using namespace std;

int n;
long long p[101]={0,1,1,1,2,2,3,4,5,7,9};

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=10;i<=n;i++){
            p[i]=p[i-1]+p[i-5];
        }
        cout<<p[n]<<'\n';
    }
    return 0;
}