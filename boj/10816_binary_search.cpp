#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> numbers;
unordered_map<int, int> m;
void binarySearch(int left, int right, int& target){
    while(left <= right){
        int mid = (left + right)/2;
        if(numbers[mid] == target){
            printf("%d ", m[target]); return;
        }
        else{
            if(numbers[mid] < target){
                left = mid+1;
            }
            else if(numbers[mid] > target){
                right = mid-1;
            }
        }
    }
    printf("%d ", 0); return;
}

int main(){
    int N, M;
    scanf("%d", &N);
    numbers.resize(N,0);
    for(int i = 0; i < N; i++){
        scanf("%d", &numbers[i]); m[numbers[i]]++;
    }
    sort(numbers.begin(), numbers.end());
    scanf("%d", &M);
    int left = 0;
    int right = int(numbers.size())-1;
    int target;
    for(int j = 0; j < M; j++){
        scanf("%d", &target);
        binarySearch(left, right, target);
    }
    return 0;
}