//acmicpc.net
//GCD, LCM Calculator
#include <iostream>
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
    cin>>a>>b;
    cout<<gcd(a,b)<<'\n';
    cout<<(a*b)/gcd(a,b)<<'\n';
    return 0;
}