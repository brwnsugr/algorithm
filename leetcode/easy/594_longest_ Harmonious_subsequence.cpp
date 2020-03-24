//https://leetcode.com/problems/longest-harmonious-subsequence/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int answer=0;
        map<int,int> m;
        vector<int> a;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto it = m.begin(); it != m.end(); it++){
            a.push_back(it->first);
        }
        if(a.size()==0) return 0;
        for(int i = 0; i < a.size()-1; i++){
            if(a[i+1]-a[i]==1){
                int sum = m[a[i+1]] + m[a[i]];
                if(sum > answer) answer = sum;
            }
        }
        return answer;
    }
};