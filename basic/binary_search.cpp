#include <vector>
#include<iostream>

using namespace std;

int BinarySearch(vector<int>& arr, int target){
    int ret = -1;
    int len = int(arr.size());
    int start = 0;
    int last = len-1;
    while(start <= last){
        int mid = (start+last)/2;
        if(arr[mid] == target){
            ret = mid; break;
        }
        else{
            if(arr[mid] < target){
                start = mid + 1;
            }
            else if(arr[mid] > target){
                last = mid - 1;
            }
        }
    }
    return ret;
}

int main(){
    vector<int> a = {1,2,3,4};
    cout<<BinarySearch(a, 4)<<endl;
    cout<<BinarySearch(a, 6)<<endl;
    return 0;
}