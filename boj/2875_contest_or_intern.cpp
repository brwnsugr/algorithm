#include <vector>
#include <iostream>
using namespace std;

int main(){
    int N, M, K;
    int answer = 0;
    cin>>N>>M>>K;
    while(K>0){
        if(N > M*2){
            N--; K--;
        }
        else if(N < M*2){
            M--; K--;
        }
        else{
            N--; K--;
        }
    }
    while(N>=2 && M>=1){
        N-=2;
        M-=1;
        answer++;
    }
    cout<<answer;
    return 0;
}