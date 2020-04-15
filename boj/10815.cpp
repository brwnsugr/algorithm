#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void binarySearch(vector<int>& v, int left, int right, int& target){
    while(left <= right){
        int mid = (left + right)/2;
        if(v[mid] == target){
            printf("%d ", 1); return;
        }
        else{
            if(v[mid] < target){
                left = mid+1;
            }
            else if(v[mid] > target){
                right = mid-1;
            }
        }
    }
    printf("%d ", 0); return;
}

int main(){
    int N, M;
    vector<int> numbers;
    scanf("%d", &N);
    numbers.resize(N,0);
    for(int i = 0; i < N; i++){
        scanf("%d", &numbers[i]);
    }
    sort(numbers.begin(), numbers.end());
    scanf("%d", &M);
    int left = 0;
    int right = int(numbers.size())-1;
    int target;
    for(int j = 0; j < M; j++){
        scanf("%d", &target);
        binarySearch(numbers, left, right, target);
    }
    return 0;
}