//  DFS/Search Order Printing out using DFS Function

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> adj; //adjacent list
vector<bool> visited; // Visited vector with Data Structure bool, checking wheter it has visited or not
int K, V, E; // K is initial point , V, Vertax, E, Edge

//Set DFS function with Printing Feature
void dfs(int here){
    cout<<here<<" ";
    visited[here] = true;
    for(int i=0; i<adj[here].size(); i++){
        int there = adj[here][i];
        if(!visited[there])
            dfs(there);
    }
}

int main(){
    //Set the size of adjacent list and visited
    cin>>V>>E>>K;
    adj.clear();
    adj.resize(V+1);
    visited.resize(V+1);
    
    //Made Adjacent List
    int a, b;
    for(int i= 0; i<E; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(K);
    return 0;
}
