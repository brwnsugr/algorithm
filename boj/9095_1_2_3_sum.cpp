#include<iostream>
using namespace std;

int cnt=0;
void comb(int n){
    if(n==0){
        cnt++; return;
    }
    //1의 합 추가, 남는건(n-1)
    if(n-1 >= 0) comb(n-1);
    //2의 합 추가, 남는건(n-2)
    if(n-2 >= 0) comb(n-2);
    //3의 합 추가, 남는건(n-3)
    if(n-2 >= 0) comb(n-3);
}

int main(){
    int T; cin>>T;
    while(T > 0){
        int n;
        cnt = 0;
        cin>>n;
        comb(n);
        T--;
        cout<<cnt<<endl;
    }
    return 0;
}