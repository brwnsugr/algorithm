//Leetcode/Medium
//www.leetcode.com/problems/gas-station
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int answer = -1;
        int size = gas.size();
        for(int i = 0; i < size; ++i){
            int remain = 0;
            if(gas[i] >= cost[i]){
                int start = i;
                int count = 0;
                for(int j = start; j < start+size; j++){
                    int idx = j % size;
                    remain += gas[idx];
                    remain -= cost[idx];
                    if(remain < 0) break;
                    count++;
                }
                if(count == size){
                    return i;
                }
            }
        }
        return answer;
    }
};