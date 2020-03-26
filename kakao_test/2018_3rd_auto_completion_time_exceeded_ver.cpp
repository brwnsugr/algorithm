#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;
//해당 단어들은 이미 학습이 사전에 되어있다고 생각하고 접근해야 한다.
// 즉, words배열을 순회하면서 동적으로 학습을 시키면 안되는 것이다.
// 두 가지 스텝 으로 쪼개서 접근해야 함 -> 1. 단어들을 학습시키는 단계, 2. 학습 시켜놓은 단어 구축 시스템 위에서 words를 순회하며 필요한 입력개수를 평가하기
// 1단게: 각 단어들의 처음부터 시작하는 모든 substr 들을 해쉬에 넣어주자. ex) "abcd" 가 있으면 -> "a", "ab", "abc", "abcd"를 모두 저장하자.
// 2단계: 단어 벡터들을 순회하면서 각 단어에서 처음부터 시작하는 substr 을 길이를 하나씩 늘려가며 순회하면서 해당 substr 에 대해 해쉬 키값이 2이상일 때 길이 값을 출력해준다.
// 예로들어, 키값이 시작부터 존재하지 않으면(즉, 자기 자신만 있는 1이 되면) 1이 된다. (즉, 해당 단어는 1글자만 입력해도 오케이..)

int solution(vector<string> words) {
    int answer = 0;
    unordered_map<string, int> m;
    //Step1
    for(int i = 0; i < words.size(); i++){
        for(int j = 1; j <= words[i].length(); j++){
            string tmp = words[i].substr(0,j);
            m[tmp]++;
        }
    }
    //Step2
    for(int i = 0; i < words.size(); i++){
        int last_pos = 1;
        string tmp = words[i].substr(0,last_pos);
        while(m[tmp] > 1 && tmp.length() < words[i].length()){
            last_pos++;
            tmp = words[i].substr(0,last_pos);
        }
        answer += last_pos;
    }
    return answer;
}