#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
// www.acmicpc.net/problem/1697
// Brute Force using queue

using namespace std;

int main(){
    const int MAX = 200000;
    int start;
    int end;
    cin>>start>>end;
    int dist[MAX+1];
    bool check[MAX+1];
    check[start] = true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int here = q.front();
        q.pop();
        //+1 jump case
        if(here+1 < MAX){
            if(!check[here+1]){
                q.push(here+1);
                check[here+1] = true;
                dist[here+1] = dist[here]+1;
            }
        }
        //-1 jump case
        if(here-1 >= 0){
            if(!check[here-1]){
                q.push(here-1);
                check[here-1] = true;
                dist[here-1] = dist[here]+1;
            }
        }
        //*2 jump case
        if(here*2 < MAX){
            if(!check[here*2]){
                q.push(here*2);
                check[here*2] = true;
                dist[here*2] = dist[here]+1;
            }
        }
    }
    cout<<dist[end];
    return 0;
}