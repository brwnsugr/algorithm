#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <string>
#include "Vector1.h"
#include "Vector2.hpp"
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> ans;
    unordered_map<char, int> m;
    vector<char> parentheses_set = { '(', ')'};
    void recursion(int n, string s, int count, int open, int close){
        static string tmp;
        if(count == n){
            ans.push_back(s);
            return;
        }
        else{
            if(open < (n/2)){
                recursion(n, s +'(', count+1, open+1, close);
            }
            if(open > close){
                recursion(n, s+')', count+1, open, close+1);
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        recursion(n*2, s, 0, 0, 0);
        res = ans;
        return res;
    }
};