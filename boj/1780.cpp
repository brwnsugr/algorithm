#include <vector>
#include <iostream>
using namespace std;
int cnt[3];
vector<vector<int>> a;
bool same(int y, int x, int n){
    bool flag = true;
    for(int i = y; i < y+n; i++){
        for(int j = x; j < x+n; j++){
            if(a[y][x] != a[i][j]){
                flag = false;
                break;
            }
        }
    }
    return flag;
}

void solve (int y, int x, int n){
    if(n==1) cnt[a[y][x]+1]++;
    else if(same(y, x, n)){
        cnt[a[y][x]+1]+=1;
    }
    else{
        int m = n/3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                solve(y+m*i, x+m*j, m);
            }
        }
    }
}

int main(){
    int N;
    cin>>N;
    a.resize(N, vector<int>(N,0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &a[i][j]);
        }
    }
    solve(0,0,N);
    for(int i = 0; i < 3; i++){
        printf("%d\n", cnt[i]);
    }
    return 0;
}