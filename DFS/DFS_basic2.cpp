//DFS/In Undirected Graph, Calculating Numbers of linked Components using DFS

#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> board;
vector<bool> visit;
int V,E;

void dfs(int n){
    visit[n]=true;
    for(int i=1; i<=V; i++){
        if(!visit[i] && board[n][i])
            dfs(i);
    }
}

int main(){
    cin>>V>>E;
    board.resize(V+1,vector<bool>(V+1,false));
    visit.resize(V+1,false);
    
    //board is Edgelist as a 2-dim Vector
    for(int i=1; i<=E; i++){
        int a,b;
        cin>>a>>b;
        board[a][b] = board[b][a] = true;
    }
    int cnt = 0;
    
    //if not visited 'i' vertax, Execute dfs function that we defined above.
    for(int i=1; i<=V; i++){
        if(!visit[i]){
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
