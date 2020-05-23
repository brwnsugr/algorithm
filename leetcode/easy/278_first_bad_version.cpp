class Solution {
public:
    int binarySearch(long long l, long long r, long long n){
        if(isBadVersion(1)) return 1;
        while(l<=r){
            long long mid = (l+r)/2;
            if( isBadVersion(mid) && !isBadVersion(mid-1)){
                return mid;
            }
            if( isBadVersion(mid)){ //left 찾기
                return binarySearch(l, mid-1, n);
            }
            return binarySearch(mid+1, r, n);
        }
        return n;
    }
    
    int firstBadVersion(int n) {
        return binarySearch(1, n, n);
    }
};