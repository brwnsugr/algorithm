#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N; cin>>N;
    vector<int> times;
    for(int i = 0; i< N; ++i){
        int element; cin>>element;
        times.push_back(element);
    }
    // sort by ascending order
    sort(times.begin(), times.end());
    
    // consuming time per each person
    vector<int> consume_times;
    int accumulated_time = 0;
    int min_sum = 0;
    for(int i = 0; i < N; i++){
        accumulated_time += times[i];
        min_sum += accumulated_time;
    }
    cout<<min_sum;
}