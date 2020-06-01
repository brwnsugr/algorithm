class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> r(num+1, 0);
        for(int i = 1; i <= num; i++){
            r[i] = r[i - (i&(-i))] + 1;
        }
        return r;
    }
};