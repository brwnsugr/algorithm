#include <iostream>
#include <vector>
using namespace std;
int board[50][50];
bool check[50][50];
int dy[] = {-1,1,0,0,1,-1,1,-1};
int dx[] = {0,0,-1,1,1,-1,-1,1};
int w, h;

void dfs(int y, int x){
    check[y][x] = true;
    for(int i = 0; i < 8; i++){
        int next_y = y + dy[i];
        int next_x = x + dx[i];
        if(next_y >= 0 && next_y < h
           && next_x >= 0 && next_x < w
           && !check[next_y][next_x]
           && board[next_y][next_x] == 1){
            dfs(next_y, next_x);
        }
    }
}

int main() {
    while(1){
        cin>>w>>h;
        if(w == 0 && h == 0) break;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                int element; cin>>element;
                board[i][j] = element; check[i][j] = false;
            }
        }
        int cnt = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(!check[i][j] && board[i][j] == 1){
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        cout<<cnt<<endl;
    }
}