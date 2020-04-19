class Solution {
public:
    // 1. a[mid] > left_min 2. a[mid] < left_min 으로 나눠서 생각하자.
    int binary_search(vector<int>& nums, int& target, int left, int right){
        while(left <= right){
            int mid = (left + right)/2;
            if(target == nums[left]) return left;
            if(target == nums[right]) return right;
            if(target == nums[mid]) return mid;
            if(left == right) break;
            else if(nums[mid] > nums[left]){
                if(target > nums[left] && target < nums[mid]){ // target 이 left_min 과 mid 사이에 있는 경우면 왼쪽 탐색,
                    return binary_search(nums, target, left, mid-1);
                }
                else{ // 이 외에는 다 오른쪽을 탐색한다.
                    return binary_search(nums, target, mid+1, right);
                }
            }
            else {
                if(target < nums[right] && target > nums[mid]){ // target이 mid와 right 사이에 있으면 오른쪽 탐색
                    return binary_search(nums, target, mid+1, right);
                }
                else{
                    return binary_search(nums, target, left, mid-1);
                }
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int right = int(nums.size()-1);
        return binary_search(nums, target, 0, right);
    }
};