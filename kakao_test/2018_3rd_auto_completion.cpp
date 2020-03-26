//먼저, string vector를 정렬 후,
//인접한 string의 prev, next만을 비교하여 시간을 아끼자.
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<string> words) {
    if(words.size()==1) return 1;
    int answer = 0;
    sort(words.begin(), words.end());

    for(int i = 0; i < words.size(); i++){
        int last_pos = 0;
        string tmp_curr, tmp_prev, tmp_next;
        while(tmp_curr == tmp_prev || tmp_curr == tmp_next){
            last_pos++;
            if(i > 0) tmp_prev = words[i-1].substr(0,last_pos);
            tmp_curr = words[i].substr(0,last_pos);
            if(i < words.size()-1) tmp_next = words[i+1].substr(0,last_pos);
        }
        if(last_pos > int(words[i].length())) last_pos = int(words[i].length());
        answer+= last_pos;
    }
    return answer;
}

int main(){
    vector<string> w1 = {"go", "gone", "guild"};
    vector<string> w2 ={"abc","def","ghi","jklm"};
    vector<string> w3 = {"word", "war", "warrior", "world"};
    cout<<solution(w3);
    
    return 0;
}