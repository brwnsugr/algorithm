//acmicpc.net
#include <iostream>
using namespace std;

int d[1000001];
int min(int i){
    if(i==1){
        return 0;
    }
    if(d[i]>0) {
        return d[i]; 
    }
    d[i] = min(i-1)+1;
    if(i%2==0){
        int temp = min(i/2)+1;
        if(d[i]>temp){
        d[i]=temp;
        }
    }
    if(i%3==0){
        int temp = min(i/3)+1;
        if(d[i]>temp){
        d[i]=temp;
        }
    }
    return d[i];
}

int main(){
    int i;
    cin>>i;
    cout<<min(i)<<'\n';
    return 0;
}