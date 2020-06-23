#include <iostream>
#include <vector>
using namespace std;


int interpoleSearch(int arr[], int first, int last, int target){
    if(first > last) return -1;
    int mid = (double)(target-arr[first])/(arr[last]-arr[first]) * (last - first) + first;
    
    if(arr[mid] < target){
        return interpoleSearch(arr, mid, last, target);
    }
    else if(arr[mid] == target){
        return mid;
    }
    else{
        return interpoleSearch(arr, first, mid, target);
    }
}
