#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(int& a, int& b){
    return a > b;
}

int main(){
    int N; cin>>N;
    int answer, ones, zeros;
    answer = ones = zeros = 0;
    vector<int> positive_num; // But Except in case integer 1.
    vector<int> negative_num;
    while(N--){
        int element; cin>>element;
        if(element == 0) zeros++;
        if(element == 1) ones++;
        if(element > 1) positive_num.push_back(element);
        if(element < 0) negative_num.push_back(element);
    }
    sort(positive_num.begin(), positive_num.end(), compare);
    sort(negative_num.begin(), negative_num.end());
    int r = positive_num.size()%2; // r이 1이면 홀수, r이 0이면 짝수
    for(int i = 0; i < positive_num.size()-r; i+=2){
        answer += (positive_num[i]*positive_num[i+1]);
    }
    if(r==1) answer += positive_num.back();
    r = negative_num.size()%2;
    for(int i = 0; i < negative_num.size()-r; i+=2){
        answer += (negative_num[i]*negative_num[i+1]);
    }
    if(r==1){
        if(zeros==0){
            answer+=negative_num.back();
        }
    }
    answer += ones; // 남은 1들은 다 더하자.
    cout<<answer;
}