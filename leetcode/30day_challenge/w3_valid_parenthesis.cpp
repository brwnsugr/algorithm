#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        bool flag = false;
        //min_bal: 괄호 밸런스의 최솟값, '('는 항상 +1 이므로 min_val +1을 해주며, ')' or '*'인 경우, '*'가 가장 최소를 지향하는 경우로 생각하여 -1을 해준다.
        //max_bal: ~~ 최댓값 ')'은 -1을 해주고, '(' or '*'인 경우, +1을 해준다. max_val 은 항상 0 이상의 상황이어야 한다.
        int min_val = 0;
        int max_val = 0;
        
        int len = int(s.length());
        for(int i = 0; i < len; i++){
            min_val += (s[i]=='(') ? 1 : -1;
            max_val += (s[i]==')') ? -1 : 1;
            min_val = max(min_val, 0);
            if(max_val < 0) return false;
        }
        if(min_val == 0) flag = true;
        return flag;
    }
};