#include <iostream>
#include <vector>
using namespace std;
vector<int> parent;

int find(int x){
    if(parent[x] == x) return x;
    else{
        return parent[x] = find(parent[x]);
    }
}

void Union(int x, int y){
    x = find(x);
    y = find(y);
    parent[y] = x;
}

int main(){
    int answer = 0;
    int n, e;
    cin>>n; cin>>e;
    parent.resize(n+1, 0);
    for(int i = 1; i <= n; i++) parent[i] = i;
    
    while(e--){
        int L, R;
        cin>>L>>R;
        Union(L, R);
    }
    int parent_group = find(1);
    for(int i = 2; i <= n; i++){
        if(parent[find(i)] == parent_group) answer++;
    }
    cout<<answer<<endl;
    return 0;
}