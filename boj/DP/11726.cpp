//acmicpc.net
//Deploying the Tile Problem Solving 
#include <iostream>
#include <cmath>
using namespace std;

int d[1000];
int i, n;

int main(){
    cin>>n;
    d[1] = 1;
    d[2] = 2;
    for( i=3; i<=n; i++){
        d[i]=d[i-1]+d[i-2];
        d[i]%=10007; // if this statement is out of 'for', overflow will happen 
    }
    cout<<d[n]<<endl;
    return 0;
}