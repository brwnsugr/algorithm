#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int n = dartResult.length();
    vector<int> original_scores;
    for(int i = 0; i < n; ++i){
        if(dartResult[i] >= '0' && dartResult[i] <= '9'){
            if(dartResult[i] =='1'){
                if( i+1 < n && dartResult[i+1] == '0'){
                    original_scores.push_back(10); i++; continue;
                }
                else{
                    original_scores.push_back(1); continue;
                }
            }
            original_scores.push_back(dartResult[i]-'0');
        }
        int end_idx = original_scores.size()-1;
        if(dartResult[i] == 'S'){
            continue;
        }
        if(dartResult[i] == 'D'){
            original_scores[end_idx] *= original_scores[end_idx];
        }
        if(dartResult[i] == 'T'){
            original_scores[end_idx] *= original_scores[end_idx]*original_scores[end_idx];
        }
        if(dartResult[i] == '*'){
            original_scores[end_idx] *= 2;
            if(end_idx >= 1){
                original_scores[end_idx-1] *= 2;
            }
        }
        if(dartResult[i] == '#'){
            original_scores[end_idx] *= (-1);
        }
    }
    for(int j= 0; j < original_scores.size(); ++j){
        answer += original_scores[j];
    }
    return answer;
}