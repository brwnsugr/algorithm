#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string, pair<int, int>> map;
string amend_melody(string& melody){
    string res;
    for(int i = 0; i < melody.length(); i++){
        if(i+1 < melody.length() && melody[i+1] == '#'){
            res += melody[i]+32; i++;
        }
        else{
            res += melody[i];
        }
    }
    return res;
}

vector<string> convert_musicinfo(string &str){
    vector<string> res;
    int start_time = stoi(str.substr(0,2))*60 + stoi(str.substr(3,2));
    int end_time = stoi(str.substr(6,2))*60 + stoi(str.substr(9,11));
    int music_length = end_time - start_time;
    string title;
    int i = 12;
    for(; str[i] != ','; ++i){
        title += str[i];
    }
    string original_melody;
    for(int j = i+1; j < str.length(); ++j){
        original_melody += str[j];
    }
    string amended_melody = amend_melody(original_melody);
    int size = amended_melody.length();
    string full_melody;
    for(int k = 0; k < music_length; ++k){
        full_melody += amended_melody[k%size]; // Sliding Window
    }
    res.push_back(full_melody); res.push_back(title);
    map[title] = make_pair(music_length, start_time);
    return res;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<string> answer_candidates;
    string melody_memory = amend_melody(m);
    vector<vector<string>> converted_infos;
    for(int i = 0; i < musicinfos.size(); ++i){
        vector<string> tmp = convert_musicinfo(musicinfos[i]);
        converted_infos.push_back(tmp);
    }
    for(int i = 0; i < converted_infos.size(); i++){
        for(int j = 0; j < converted_infos[i][0].length(); j++){
            int count = 0;
            if(melody_memory[0] == converted_infos[i][0][j]){
                if(melody_memory.length()==1){
                    answer_candidates.push_back(converted_infos[i][1]);
                    break;
                }
                for(int k = 1; k < melody_memory.length() && j+1 < converted_infos[i][0].length(); k++){
                    if(melody_memory[k] == converted_infos[i][0][j+1]){
                        count++; j++;
                        if(count == melody_memory.length()-1){
                            answer_candidates.push_back(converted_infos[i][1]); break;
                        }
                        continue;
                    }
                    if( melody_memory[k] != converted_infos[i][0][j+1]){
                        break;
                    }
                }
            }
        }
    }
    int music_length = 0; int start_time = 10000;
    if(answer_candidates.size()==0) return "(None)";
    if(answer_candidates.size()==1) return answer_candidates[0];
    
    for(int i = 0; i < answer_candidates.size(); i++){
        if(music_length < map[answer_candidates[i]].first){
            answer = answer_candidates[i]; music_length = map[answer_candidates[i]].first; start_time = map[answer_candidates[i]].second;
            
        }
        else if(music_length == map[answer_candidates[i]].first){
            if(map[answer_candidates[i]].second < start_time){
                answer = answer_candidates[i];
            }
        }
    }
    return answer;
}