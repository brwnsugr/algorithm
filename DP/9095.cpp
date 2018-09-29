//acmicpc.net
//Integer Summation only using 1,2,3
#include <iostream>
using namespace std;

int d[11];
int t;
int i;

int abc(int n){
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for (int i=4; i<=n; i++) {
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }
    return d[n];
}

int main() {
    int n2;
    cin>>t;
    
    while(t--){
        cin >> n2;
        cout<<abc(n2)<<'\n';
    }
    return 0;
}