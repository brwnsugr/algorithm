class Solution {
public:
    vector<vector<int>> match_hash(vector<string> str){
    unordered_map<string, vector<int>> map;
    for(int i = 0; i < str.size(); ++i){
        sort(str[i].begin(), str[i].end());
        map[str[i]].push_back(i);
    }
    vector<vector<int>> match_idxs;
    for(auto &i: map){
        match_idxs.push_back(i.second);
    }
    return match_idxs;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    vector<vector<int>> idxs = match_hash(strs);
    for(int i = 0; i < idxs.size(); i++){
        vector<string> temps;
        for(int j = 0; j < idxs[i].size(); j++){
            string temp = strs[idxs[i][j]];
            temps.push_back(temp);
        }
        ans.push_back(temps);
    }
    return ans;
}
};