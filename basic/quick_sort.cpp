#include <iostream>
#include <string>
#include <vector>
using namespace std;

void quick_sort(vector<int>& a, int left, int right){
    if(left > right) return;
    int pivot = a[left];
    int low = left + 1;
    int high = right;
    
    while(low <= high){
        while(a[low] <= pivot && low <= right) low++;
        while(a[high] >= pivot && high >= left + 1) high--;
        if(low <= high) swap(a[low], a[high]);
    }
    swap(a[left], a[high]); 
    quick_sort(a,left, high-1);
    quick_sort(a, high+1, right);
}

int main(){
    vector<int> a;
    a.reserve(10);
    for(int i = 10; i >= 1; i--) a.push_back(i);
    int left = 0;
    int right = int(a.size())-1;
    quick_sort(a, left, right);
    for(int i = 0; i < a.size(); i++){
        cout<<a[i]<<' ';
    }
    return 0;
}