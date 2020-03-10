#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <iostream>

using namespace std;

string to_lower_case(string &str){
    for_each(str.begin(), str.end(), [](char &c){
        c = tolower(c);
    });
    return str;
}

unordered_map<string, int> string_to_map(string &str, set<string> &s){
    unordered_map<string, int> m;
    for(int i = 0; i < str.size()-1; ++i){
        string tmp = str.substr(i, 2);
        for(int j = 0; j < 2; ++j){
            if(tmp[j]-'a' < 0 || tmp[j]-'a' > 25){
                break;
            }
            else{
                if(j == 1){
                    m[tmp]++; s.insert(tmp);
                }
            }
        }
    }
    return m;
}

int solution(string str1, string str2) {
    str1 = to_lower_case(str1);
    str2 = to_lower_case(str2);
    set<string> s;
    unordered_map<string, int> m1 = string_to_map(str1, s);
    unordered_map<string, int> m2 = string_to_map(str2, s);
    int union_number = 0;
    int intersection_number = 0;
    for(auto it = s.begin(); it != s.end(); ++it){
        //Count union
        union_number += max(m1[*it], m2[*it]);
        //Count intersection
        intersection_number += min(m1[*it], m2[*it]);
    }
    if (union_number == 0) return 65536;
    float tmp = (intersection_number * 65536 / union_number);
    return tmp;
}