//acmicpc.net 
//Fibonacci Function
#include <iostream>
using namespace std;

int main(){
    int iN, iT, i, j, iCount0, iCount1, temp;
    cin>>iT;
    for(i=0;i<iT;i++){
        cin>>iN;
        iCount0=1;
        iCount1=0;
        for(j=0;j<iN;j++){
            temp=iCount1;
            iCount1+=iCount0;
            iCount0=temp;
        }
        cout<<iCount0<<" "<<iCount1<<'\n';
    }
    return 0;
}