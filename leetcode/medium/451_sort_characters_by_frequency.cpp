class Compare {
public:
    bool operator()(pair<int, char> p1, pair<int, char> p2){
        return p1.first < p2.first;
    }
};

class Solution {
public:
    bool comp(pair<int, char> p1, pair<int, char> p2){
        return p1.first > p2.first;
    }
    
    string frequencySort(string s) {
        string ans ="";
        unordered_map<char, int> map;
        for(auto &a:s) map[a]++;
        priority_queue<pair<int,char>, vector<pair<int,char>>, Compare> char_by_freq;
        for(auto it = map.begin(); it!= map.end(); it++){
            char_by_freq.push(make_pair(it->second, it->first));
        }
        
        while(!char_by_freq.empty()){
            ans += string(char_by_freq.top().first, char_by_freq.top().second);
            char_by_freq.pop();
        }
        return ans;
    }
};