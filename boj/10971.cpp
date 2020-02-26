#include <algorithm>
#include <vector>
#include <iostream>
// www.acmicpc.net/problem/10971
// Brute Force using Next_permutation algorithm library 
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<vector<int>> cost;
    int answer = 6000000;
    cost.resize(N+1, vector<int>(N+1, 0));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int element;
            cin>>element;
            cost[i][j] = element;
        }
    }
    vector<int> track_order;
    for(int i = 1; i <= N; i++){
        track_order.push_back(i);
    }
    do{
        int sum = 0;
        for(int j = 1; j < track_order.size(); j++){
            int unit_cost = cost[track_order[j-1]][track_order[j]];
            if(unit_cost == 0) break;
            sum += unit_cost;
            if(j+1 == track_order.size()){
                int last_cost = cost[track_order[j]][track_order[0]];
                if(last_cost == 0) break;
                sum += last_cost;
                if(sum < answer) answer = sum;
            }
        }
    } while(next_permutation(track_order.begin(), track_order.end()));
    cout<<answer<<endl;
    return 0;
}