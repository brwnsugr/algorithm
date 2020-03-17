class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int len = p.length();
        unordered_map<char, int> s_map;
        unordered_map<char, int> p_map;
        int count = 0;
        for(int i = 0; i < s.length() && i + len <= s.length(); i++){
            if(i == 0){
                for(int j = 0; j < len; j++){
                    p_map[p[j]]++;
                    s_map[s[j]]++;
                }
                for(auto &a: s_map){
                    int tmp = min(a.second, p_map[a.first]);
                    count += tmp;
                }
                if(count == len){
                    res.push_back(i);
                }
            }
            else{
                s_map[s[i-1]]--;
                if (p_map[s[i-1]] > s_map[s[i-1]]) count--;
                s_map[s[i+len-1]]++;
                if (s_map[s[i+len-1]] <= p_map[s[i+len-1]]) count++;
                if (count == len) res.push_back(i);
            }
        }
        for(int i = 0; i < res.size(); i++){
            cout<<res[i]<<" ";
        }
        return res;
    }
};