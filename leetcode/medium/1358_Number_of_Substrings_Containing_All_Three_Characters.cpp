//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ret = 0;
        int len = int(s.length());
        
        int max_list[] = {len, len, len};
        
        for(int i = len-1; i >= 0; i--){
            max_list[s[i]-'a'] = i;
            int max_idx = max(max_list[0],max(max_list[1],max_list[2]));
            ret += len - max_idx;
        }
        return ret;
    }
};