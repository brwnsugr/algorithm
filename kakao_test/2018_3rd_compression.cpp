#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

// 1. 사전을 해쉬맵에 담자.

vector<int> solution(string msg) {
    vector<int> answer;
    string basic = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string, int> m; // 해쉬로 저장하는 이유가 key로 찾을 때 Time Complexity가 O(1)이므로..
    // 새로운 값이 추가될때마다의 idx 값은 현재 해쉬 사이즈 +1 로 저장하면 size 구하는 Method가 O(1)이므로 시간 아낄 수 있음
    
    int basic_len = int(basic.length());
    for(int i = 0; i < basic_len; i++){
        string tmp = basic.substr(i,1);
        m[tmp] = i+1;
    }
    bool flag = false;
    while(true){
        int j = 0;
        if(msg.length()==1){
            answer.push_back(m[msg]);
            break;
        }
        string tmp = msg.substr(0,1);
        while(m.count(tmp) > 0){
            if(j == msg.length()){
                flag = true;
                answer.push_back(m[tmp]);
                break;
            }
            j++;
            tmp = msg.substr(0,j);
        }
        if(flag) break;
        m[tmp] = m.size()+1;
        j--;
        string cut = msg.substr(0,j);
        answer.push_back(m[cut]);
        msg = msg.substr(j);
    }
    return answer;
}

int main(){
    string s = "KAKAO";
    string s2 = "TOBEORNOTTOBEORTOBEORNOT";
    string s3 = "ABABABABABABABAB";
    string s4 = "AAA";
    vector<int> test = solution(s);
    
    return 0;
}