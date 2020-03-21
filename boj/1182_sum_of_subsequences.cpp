#include<vector>
#include<iostream>
using namespace std;
vector<int> numbers;
int ans = 0;
void go(int i, int sum, int target, int N, int count){
    if(i == N){
        if(sum == target){
            ans+=1;
        }
        return;
    }
    go(i+1, sum, target, N, count+1);
    
    go(i+1, sum+numbers[i], target, N, count+1);
}

int main(){
    int N, S;
    cin>>N>>S;
    for (int i = 0; i < N; ++i) {
        int element; cin>>element;
        numbers.push_back(element);
    }
    go(0, 0, S, N, 0);
    if(S==0) ans--;
    cout<<ans<<endl;
    return 0;
}