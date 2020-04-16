#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
vector<pair<int,int>> a;
void solve(int n, int x, int y){
    if(n==0) return;
    else{
        solve(n-1, x, 6-x-y);
        a.push_back(make_pair(x,y));
        cnt++;
        solve(n-1, 6-x-y, y);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    solve(n, 1, 3);
    printf("%d\n", cnt);
    for(int i = 0; i < a.size(); i++){
        printf("%d %d\n", a[i].first, a[i].second);
    }
    return 0;
}