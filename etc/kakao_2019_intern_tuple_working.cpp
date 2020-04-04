#include <string>
#include <vector>
#include <stack>
#include<iostream>
#include<unordered_map>

//pair에 시작점하고, '{', or '}'의 갯수 해쉬로 넣기
//hash['{'] = ( 개수, 해당 idx) 넣기,
//['}'] 의 해당 idx가 나왔을 때, } idx - { idx 뺀 길이 및 시작 idx를 pair max에 저장
//pair max(시작idx, 길이)
using namespace std;
vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<char, pair<int, int>> m; // pair(
    pair<int, int> max_case = make_pair(0,0);
    
    int len = int(s.length());
    for(int i = 0; i < len; i++){
        if(i == 0 || i == len-1) continue;
        if(s[i] == '{'){
            m['{'].first = 1;
            m['{'].second = i;
        }
        else if(s[i]=='}'){
            int part_len = i - m['{'].second;
            if(part_len > max_case.second){
                max_case = make_pair(m['{'].second, part_len);
            }
        }
    }
    string tmp = s.substr(max_case.first+1, max_case.second-1);
    int comma_pos = 0;
    for(int j = 0; j < int(tmp.length()); j++){
        if(tmp[j] == ','){
            if(comma_pos == 0){
                string part = tmp.substr(comma_pos,j);
                int element = stoi(part);
                answer.push_back(element);
                comma_pos = j;
            }
            else{
                string part = tmp.substr(comma_pos+1, j-comma_pos-1);
                int element = stoi(part);
                answer.push_back(element);
                comma_pos = j;
            }
        }
        else{
            continue;
        }
    }
    string last;
    if(comma_pos !=0) last = tmp.substr(comma_pos+1);
    if(comma_pos == 0) last = tmp;
    int last_num = stoi(last);
    answer.push_back(last_num);
    for(int i = 0; i < answer.size(); i++){
        cout<<answer[i]<<" ";
    }
    return answer;
}


int main(){
    string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    string s2 = "{{1,2,3},{2,1},{1,2,4,3},{2}}";
    string s3 = "{{20,111},{111}}";
    string s4 = "{{123}}";
    solution(s4);
    return 0;
}