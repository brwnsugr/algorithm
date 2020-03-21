#include<iostream>
#include<vector>

using namespace std;
vector<int> numbers;
vector<int> answer;
vector<bool> check;

void comb(int cnt){
    if(cnt == 6){
        for(int i = 0; i < 6; i++){
            cout<<answer[i]<<" ";
        }
        cout<<'\n'; return;
    }
    for(int i = 0; i < numbers.size(); i++){
        if(!check[numbers[i]] &&(answer.size()==0 || numbers[i] > answer.back())){
            answer.push_back(numbers[i]);
            check[numbers[i]] = true;
            comb(cnt+1);
            answer.pop_back();
            check[numbers[i]] = false;
        }
    }
}

int main(){
    while(1){
        int N; cin>>N; if(N==0) break;
        numbers.clear(); answer.clear();
        check.resize(50, false);
        for(int i = 0; i < N; i++){
            int element; cin>>element;
            numbers.push_back(element);
        }
        comb(0);
        cout<<endl;
    }
    return 0;
}