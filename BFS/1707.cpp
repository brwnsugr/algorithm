//acmicpc.net
//Graph 
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<int> a[20001];
int color[20001];
void dfs(int node, int c){
    color[node] = c;
    for(int i=0; i<a[node].size(); i++){
        int next = a[node][i];
        if(color[next]==0){
            dfs(next, 3-c);
        }
    }
}
int main(){
    int t;
    scanf("%d\n", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        for( int i=1; i<=n; i++){  // 정점의 개수를 받아서 정점을 index num으로 하는 a 배열을 정리
            a[i].clear(); // Vector 의 초기화, for문이므로..
            color[i] = 0; // color라는 배열에 정점을 index num으로 하는 값을 모두 0으로..
        }
        for(int i=0; i<m; i++){ // 간선의 개수를 받아서 간선의 개수 횟수만큼 for loop를 돌림
            int u, v; // 정수 u, v 의 선언
            scanf("%d %d", &u,&v); // 간선의 개수만큼 u v 쌍을 읽어서 a[u]에는 v 를 넣고, a[v]에는 u를 넣는다
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for(int i=1; i<=n; i++){ // 정점의 개수만큼 loop
            if(color[i]==0){ // color는 방문 배열정도로 생각하면됨, 해당 정점에 방문 안했으면, dfs함수로 방문..
                dfs(i, 1);
            }
        }
        bool ok = true; // ok 라는 bool data형에 true로 시작, 즉 ok=1
        for(int i=1; i<=n; i++){ // 정점의 개수만큼 loop
            for(int k=0; k<a[i].size(); k++){ // 해당 배열 a[i]의 size만큼 k 가 0부터 쭉 looping 시작
                int j = a[i][k]; //
                if(color[i]==color[j]){
                    ok = false;
                }
            }
        }
        printf("%s\n",ok ? "YES" : "NO");
    }
    return 0;
}