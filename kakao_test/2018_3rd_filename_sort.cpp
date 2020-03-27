#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;
//1. 먼저 파일을 Head, Number, Tail로 쪼개서 해쉬의 배열로 저장하자.
//Head: 숫자가 나오기전까지의 string, Number: Head이후의 숫자가 시작해서 숫자가 끝날때까지, Tail: 숫자가 끝난 이후의 나머지 파트.
//2. sort 내, compare method 를 따로 요구사항에 맞게 정의하자.
bool compare(unordered_map<char, string>a, unordered_map<char, string>b){
    string a_head,b_head; int a_num, b_num;
    a_head = a['h'];
    b_head = b['h'];
    a_num = stoi(a['n']);
    b_num = stoi(b['n']);
    return (a_head < b_head) ? true : ((a_head > b_head) ? false : a_num < b_num);
}


vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<unordered_map<char, string>> files_map;
    
    for(int i = 0; i < files.size(); i++){
        int pos = 0;
        unordered_map<char, string> m;
        while(!isdigit(files[i][pos]) && pos < files[i].length()){
            pos++;
        }
        int num_start = pos;
        string head;
        for(int j = 0; j < pos; j++){
            head += tolower(files[i][j]);
        }
        while(isdigit(files[i][pos]) && pos-num_start < 5){
            pos++;
        }
        string number;
        if(pos != num_start) number = files[i].substr(num_start, pos-num_start);
        string tail = files[i].substr(pos);
        m['h'] = head;
        m['n'] = number;
        m['i'] = to_string(i);
        files_map.push_back(m);
    }
    stable_sort(files_map.begin(), files_map.end(), compare);
    for(int i = 0; i < files_map.size(); i++){
        int idx = stoi(files_map[i]['i']);
        answer.push_back(files[idx]);
    }
    return answer;
}


int main(){
    vector<string> w1 = {"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"};
    vector<string> w2 ={"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"};
    vector<string> test = solution(w2);
    
    for(int i = 0; i < test.size(); i++){
        cout<<test[i]<<" ";
    }
    return 0;
}