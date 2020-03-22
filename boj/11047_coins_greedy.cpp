#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N, K;
    cin>>N>>K;
    vector<int> coins;
    for(int i = 0; i < N; ++i){
        int element; cin>>element;
        coins.push_back(element);
    }
    // Coins Travese by reverse order because we have to consider the bigger unit of coin to find the optimal Solution 
    int count = 0;
    for(int i = N-1; i >= 0; i--){ 
        if(K/coins[i] >= 1){
            int q = K/coins[i];
            count += q;
            K -= coins[i]*q;
        }
        if(K==0) break;
    }
    cout<<count<<endl;
    return 0;
}