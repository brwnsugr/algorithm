#include <iostream>
#include <vector>
//https://leetcode.com/problems/product-of-array-except-self/
using namespace std;
//Sol 1 has O(N) Space Complexity in order to keep track of the product of elements to the left and right
class Solution1 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int len = int(nums.size());
        vector<int> L(len-1, 1);
        vector<int> R(len, 1);
        for(int i = 0; i < len-1; i++){
            if(i==0) L[i] = nums[i];
            else L[i] = L[i-1] * nums[i];
        }
        for(int j = len-1; j >= 1; j--){
            if(j==len-1) R[j] = nums[j];
            else R[j] = R[j+1] * nums[j];
        }
        for(int k = 0; k < len; k++){
            if(k==0) res.push_back(R[k+1]);
            else if(k==len-1) res.push_back(L[k-1]);
            else res.push_back(L[k-1]*R[k+1]);
        }
        return res;
    }
};

//Sol2 has O(1) Space Complexity, 
class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int len = int(nums.size());
        res.resize(len,1);
        //#Step1 Let res[i] be the product of the left elements to i-1
        for(int i = 0; i < len; i++){
            if(i == 0) continue;
            else res[i] = res[i-1] * nums[i-1];
        }
        int R = 1;
        //# And then I take that Right Sided Product Values into res[] array
        for(int j = len-1; j >= 0; j--){
            if(j == len-1) continue;
            else{
                R = nums[j+1] * R;
                res[j] = res[j] * R;
            }
        }
        return res;
    }
};