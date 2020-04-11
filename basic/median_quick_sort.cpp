//Median Quick Sort 
#include <iostream>
#include <vector>
using namespace std;

void three_sort(vector<int>& a, int left, int right, int mid){
    if(a[left] > a[mid]) swap(a[left], a[mid]);
    if(a[mid] > a[right]) swap(a[mid], a[right]);
    if(a[left] > a[mid]) swap(a[left], a[mid]);
}

void quick_sort(vector<int>& a, int left, int right){
    int mid = (left+right)/2;
    three_sort(a, left, right, mid);
    if(left > right) return;
    if(right-left+1 <= 3) return;
    int pivot_idx = left;
    int pivot_val = a[mid];
    swap(a[mid], a[left]);
    int low = left+1;
    int high = right;
    while(low <= high){
        while(a[low] <= pivot_val && low <= right) low++;
        while(a[high] >= pivot_val && high >= left +1) high--;
        if(low <= high) swap(a[low], a[high]);
    }
    swap(a[pivot_idx], a[high]);
    quick_sort(a,left, high-1);
    quick_sort(a, high+1, right);
}