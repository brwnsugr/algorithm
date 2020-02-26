#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/10819 
// BruteForce 

int calculate(vector<int> &arr){
    int sum = 0;
    for(int i = 1; i < arr.size(); ++i){
        sum += abs(arr[i] - arr[i-1]);
    }
    return sum;
}

int main() {
    int N;
    int answer = 0;
    cin>>N;
    vector<int> arr;
    for(int i = 0; i < N; ++i){
        int element;
        cin>>element;
        arr.push_back(element);
    }
    
    sort(arr.begin(), arr.end());
    
    do{
        int tmp = calculate(arr);
        answer = max(answer, tmp);
    } while(next_permutation(arr.begin(), arr.end()));
    
    cout<<answer;
    return 0;
}