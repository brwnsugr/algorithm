#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main(){
    int N, M, K;
    vector<int> answer;
    cin>>N>>M>>K;
    vector<bool> check(N+1, false);
    if(M > N-K+1 || N > M*K){
        cout<<-1; return 0;
    }
    for(int i = 1; i <= N; i++){
        answer.push_back(i);
    }
    vector<int> divide_set;
    divide_set.push_back(0);
    divide_set.push_back(K);
    N-=K;
    M-=1;
    
    int gr = M == 0 ? 1 : N/M;
    int r  = M == 0 ? 0 : N%M;
    
    for(int i = 0; i < M; i++){
        int element = divide_set.back() + gr;
        if(r > 0){
            element += 1; r--;
        }
        divide_set.push_back(element);
    }
    for(int i = 0; i < divide_set.size()-1; i++){
        reverse(answer.begin()+divide_set[i], answer.begin()+divide_set[i+1]);
    }
    for(int i = 0; i < answer.size(); i++){
        cout<<answer[i]<<" ";
    }
    return 0;
}