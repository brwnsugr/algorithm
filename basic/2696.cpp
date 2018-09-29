//acmicpc.net
//Median Value 
#include <iostream>
#include <algorithm>
using namespace std;

int t,n;
int a[10000];

int main(){
    cin>>t;
    while(t--){
        a[10000]={0,};
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>a[i];
        }
        cout<<(n/2)+1<<endl;
        cout<<a[1]<<' ';
        for(int i=3; i<=n;i+=2){
            sort(a+1,a+i+1);
            cout<<a[(1+i)/2]<<' ';
        }
        cout<<endl;
    }
    return 0;
}