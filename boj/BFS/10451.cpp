//acmicpc.net
//Permutation Cycle
#include <iostream>
using namespace std;

int a[1001];
bool c[1001];

void dfs(int x){
    if (c[x]) return;
    c[x]=true;
    dfs(a[x]);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for (int i=1; i<=n; i++){
            cin>>a[i];
            c[i]=false; // c배열에는 우선 다 0값(false)으로 넣음
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(c[i]==false){ //c[i]가 아직 방문 안되있으면 dfs 함수 써서 탐색
                dfs(i);
                ans+=1;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}