#include <iostream>
#include <vector>
using namespace std;
vector<int> adj;
vector<int> steps;
vector<int> nsteps;
int dfs(int curr, int cnt, int& step){
    if(nsteps[curr] != 0){
        if(step != steps[curr]){
            return 0;
        }
        else{
            return cnt - nsteps[curr];
        }
    }
    steps[curr] = step;
    nsteps[curr] = cnt;
    return dfs(adj[curr], cnt+1, step);
}

int main() {
    int T; cin>>T;
    
    while(T--){
        int n; cin>>n;
        adj.clear(); adj.resize(n+1,0);
        steps.clear(); steps.resize(n+1,0);
        nsteps.clear(); nsteps.resize(n+1,0);
        for(int i = 1; i <= n; i++){
            int element; cin>>element;
            adj[i] = element;
        }
        int ret = 0;
        for(int i = 1; i <= n; i++){
            int tmp = 0;
            if(steps[i] == 0){
                tmp = dfs(i, 1, i);
            }
            ret += tmp;
        }
        cout<<n - ret<<endl;
    }
}