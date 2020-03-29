#include <vector>
#include <iostream>
using namespace std;
vector<int> parent;
//Union Find 
int find(int x){ // 어떤 집합에 속해있는지 집합 root number 찾기 && parent
    if( x == parent[x]) return x;
    else{
        int y = find(parent[x]);
        parent[x] = y;
        return y;
    }
}

void Union(int x, int y){
    x = find(x);
    y = find(y);
    parent[y] = x;
}

int main(){
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    for(int i = 0; i <= n; i++){
        parent.push_back(i);
    }
    for(int i = 0; i < m; i++){
        int flag, left, right;
        cin>>flag>>left>>right;
        if(flag == 0){
            Union(left,right);
        }
        else if(flag == 1){
            if(find(left)==find(right)){
                cout<<"YES"<<'\n';
            }
            else{
                cout<<"NO"<<'\n';
            }
        }
    }
    return 0;
}