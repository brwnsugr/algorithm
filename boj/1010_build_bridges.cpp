#include<iostream>
using namespace std;
//Combination

int comb(int n, int r){
    if(n == r || r == 0){
        return 1;
    }
    else if(r == 1){
        return n;
    }
    else{
        return (comb(n-1, r-1) + comb(n-1,r));
    }
}

int main(){
    int T; cin>>T;
    while(T--){
        int N, M;
        cin>>N>>M;
        int ans = comb(M,N);
        cout<<ans<<endl;
    }
    return 0;
}