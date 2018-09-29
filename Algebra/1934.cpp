//acmicpc.net
//LCM 
#include <iostream>
#include <stdio.h>
using namespace std;

int a,b;

int gcd(int x, int y){
    while(y!=0){
        int r = x%y;
        x=y;
        y=r;
    }
    return x;
}

int main() {
    int t;
    cin>>t;
    while(t--){
    cin>>a>>b;
    cout<<(a*b)/gcd(a,b)<<'\n';
    }
    return 0;
}