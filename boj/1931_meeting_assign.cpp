#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
bool compare(const pair<int, int>&a, const pair<int, int>&b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    int N; cin>>N;
    vector<pair<int, int>> time_table;
    int count = 0; // How many # of Meetings that can be made.
    int current_finish = 0;
    while(N--){
        int start, finish;
        cin>>start>>finish;
        time_table.push_back(make_pair(start,finish));
    }
    int size = time_table.size();
    sort(time_table.begin(), time_table.end(), compare);
    for (int i = 0; i < size; ++i) {
        if(time_table[i].first >= current_finish){
            current_finish = time_table[i].second;
            count++;
        }
    }
    cout<<count;
    return 0;
}