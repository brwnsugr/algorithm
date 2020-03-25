#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int N;
int board[100][100];
bool check[100][100];
int g[100][100];
int group = 0;
void grouping(int y, int x){
    check[y][x] = true;
    g[y][x] = group;
    for(int i = 0; i < 4; i++){
        int next_y = y + dy[i];
        int next_x = x + dx[i];
        if(next_y >= 0 && next_y < N
           && next_x >= 0 && next_x < N
           && !check[next_y][next_x]){
            check[next_y][next_x] = true;
            g[y][x] = group;
            grouping(next_y, next_x);
        }
    }
}

int main() {
    
    int dist[100][100];
    cin>>N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int element; cin>>element;
            board[i][j] = element;
            if(element == 1){
                check[i][j] = false;
            }
            else{
                check[i][j] = true;
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!check[i][j]){
                ++group;
                grouping(i,j);
            }
        }
    }
    queue<pair<int,int>> q;
    int ans = -1;
    for(int l = 1; l <= group; l++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                dist[i][j] = -1;
                if(g[i][j] == l){
                    dist[i][j] = 0;
                    q.push(make_pair(i,j));
                }
            }
        }
        
        while(!q.empty()){
            pair<int,int> here = q.front();
            q.pop();
            for(int i = 0 ; i < 4; i++){
                int next_y = here.first + dy[i];
                int next_x = here.second + dx[i];
                if(next_y >= 0 && next_y < N
                   && next_x >= 0 && next_x < N
                   && dist[next_y][next_x] == -1){
                    dist[next_y][next_x] = dist[here.first][here.second] + 1;
                    q.push(make_pair(next_y, next_x));
                }
            }
        }
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(g[i][j]!=l && g[i][j] > 0){
                    if(ans == -1 || ans > dist[i][j]-1){
                        ans = dist[i][j]-1;
                    }
                }
            }
        }
    }
    
    cout<<ans<<endl;
    return 0;
}