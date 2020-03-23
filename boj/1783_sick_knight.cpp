#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin>>N>>M;
    int answer = 0;
    // height 이 1인 경우
    if(N==1) answer = 1;
    // height 이 2인 경우
    else if(N==2) answer = min(4,((M-1)/2)+1);
    // height 이 3 이상인 경우
    else if(N>=3){
        if(M==1){
            answer = 1;
        }
        else if(M < 5){
            answer = M;
        }
        else if(M >= 5 && M < 7){
            answer = 4;
        }
        else{
            answer = M-2;
        }
    }
    cout<<answer;
    return 0;
}
